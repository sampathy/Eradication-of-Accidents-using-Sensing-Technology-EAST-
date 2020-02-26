#define trigPin1 6
#define echoPin1 7
#define trigPin2 3
#define echoPin2 4
#define trigPin3 8
#define echoPin3 9
#define trigPin4 10
#define echoPin4 11

int a0=0;
int a1=0;


long duration, distance, InputSensor1,OutputSensor1,InputSensor2,OutputSensor2,count1,count2;

void setup()
{
Serial.begin (9600);
pinMode(trigPin1, OUTPUT);
pinMode(echoPin1, INPUT);
pinMode(trigPin2, OUTPUT);
pinMode(echoPin2, INPUT);
pinMode(trigPin3, OUTPUT);
pinMode(echoPin3, INPUT);
pinMode(trigPin4, OUTPUT);
pinMode(echoPin4, INPUT);
pinMode(A0,INPUT);
pinMode(A4,INPUT);
}

void loop() {
SonarSensor(trigPin1, echoPin1);
InputSensor1 = duration;

SonarSensor(trigPin2, echoPin2);
OutputSensor1 = duration;


SonarSensor(trigPin3, echoPin3);
InputSensor2 = duration;

SonarSensor(trigPin4, echoPin4);
OutputSensor2 = duration;


//Serial.print(InputSensor1);
//Serial.print("        ");
//Serial.println(OutputSensor1);
//Serial.print("        ");
//Serial.print(InputSensor1);
//Serial.print("        ");
//Serial.println(OutputSensor1);
Serial.print("        ");


if(InputSensor1<5)
{
count1=count1+1;


}


  
if(OutputSensor1<5 && count1>0)
{
  count1=count1-1;
}

if(count1>0)
{
  digitalWrite(12,HIGH);
}
else
{
  digitalWrite(12,LOW);
}

Serial.print(count1);


if(InputSensor2<5)

{
count2=count2+1;
}
if(OutputSensor2<5 && count2>0)
{
  count2=count2-1;
}

if(count2>0)
{
  digitalWrite(5,HIGH);
}
else
{
  digitalWrite(5,LOW);
}

//Serial.print(count2);
//Serial.println();
//delay(100);
a0=digitalRead(A0);
a1=digitalRead(A4);



if((a0+a1)<2)
{
  Serial.println("LED ON!!!!");
  digitalWrite(13,HIGH);
  Serial.println("ATD9502718882;\r\n");
}
else
{
  digitalWrite(13,LOW);
}

}



void SonarSensor(int trigPin,int echoPin)
{
digitalWrite(trigPin, LOW);
delayMicroseconds(2);
digitalWrite(trigPin, HIGH);
delayMicroseconds(10);
digitalWrite(trigPin, LOW);
duration = pulseIn(echoPin, HIGH);
duration = (duration) / 58;
}

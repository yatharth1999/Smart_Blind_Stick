const int trigPin = 37;
const int echoPin = 36;
const int buzzer = 23;
const int bt=10;
long duration;
int distance;
int safetyDistance;

void setup()
{
  Serial.begin(9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(buzzer, OUTPUT);
  pinMode(bt,INPUT);
}

void loop()
{
    digitalWrite(trigPin, LOW);
    delayMicroseconds(2);
    digitalWrite(trigPin, HIGH);
    delayMicroseconds(10);
    digitalWrite(trigPin, LOW);
    duration = pulseIn(echoPin, HIGH);
    distance= duration*0.034/2;
    safetyDistance = distance;
    if (safetyDistance <= 50)
    {
        digitalWrite(buzzer, HIGH);
    }
    else
    {
        digitalWrite(buzzer, LOW);
    }
    if(digitalRead(bt)==HIGH)
    {
        Serial.println("a");
    }
    delay(400);
}

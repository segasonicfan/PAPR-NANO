//PAPR_NANO V1.4.1 Test Code
//by Segasonicfan Designs
// https://www.segasonicfan.wixsite.com/vgmods
//4.15.2020

//Adapted and built off of:
 //created 21 November 2006
 //by David A. Mellis
 //modified 30 Aug 2011
 //by Limor Fried
 //modified 28 Dec 2012
 //by Mike Walters

// constants won't change. They're used here to
// set pin numbers:

const int buttonPin = 2;    // the number of the pushbutton pin PWR ON
const int ledPinError = 8;  // the number of the LED pin
const int ledPin1 = 9;  // the number of the LED pin
const int ledPin2 = 10;  // the number of the LED pin
const int ledPin3 = 11;  // the number of the LED pin
const int ledPin4 = 12;  // the number of the LED pin

// ON Signal
const int PinOn = 15; // ON signal to activate LED FET Q1

// Variables will change:
       // the current state of the output pin
int buttonState = HIGH;            // the current reading from the input pin (changed from floating to HIGHvv - SSFD)
int lastButtonState = HIGH;   // the previous reading from the input pin 
int ledState = HIGH;  // the previous reading from the output pin
int PinState = LOW;  // the previous reading from the output pin

// the following variables are long's because the time, measured in miliseconds,
// will quickly become a bigger number than can be stored in an int.

long lastDebounceTime = 0;  // the last time the output pin was toggled
long debounceDelay = 50;    // the debounce time; increase if the output flickers

void setup() {
  pinMode(buttonPin, INPUT);
  pinMode(ledPinError, OUTPUT);
  pinMode(ledPin1, OUTPUT);
  pinMode(ledPin2, OUTPUT);
  pinMode(ledPin3, OUTPUT);
  pinMode(ledPin4, OUTPUT);
  pinMode(PinOn, OUTPUT);

  // set initial LED state
  digitalWrite(ledPinError, ledState);
  digitalWrite(ledPin1, ledState);
  digitalWrite(ledPin2, ledState);
  digitalWrite(ledPin3, ledState);
  digitalWrite(ledPin4, ledState);
  digitalWrite(PinOn, PinState);
}

void loop() {
  // read the state of the switch into a local variable:
  int reading = digitalRead(buttonPin);

  // check to see if you just pressed the button
  // (i.e. the input went from LOW to HIGH),  and you've waited
  // long enough since the last press to ignore any noise:

  // If the switch changed, due to noise or pressing:
  if (reading != lastButtonState) {
    // reset the debouncing timer
    lastDebounceTime = millis();
  }

  if ((millis() - lastDebounceTime) > debounceDelay) {
    // whatever the reading is at, it's been there for longer
    // than the debounce delay, so take it as the actual current state:

    // if the button state has changed:
    if (reading != buttonState) {
      buttonState = reading;

      // only toggle the LED if the new button state is HIGH
      if (buttonState == HIGH) {
        ledState = !ledState;
      }
    }
  }

  // set the LED:
  digitalWrite(ledPinError, ledState);
  digitalWrite(ledPin1, ledState);
  digitalWrite(ledPin2, ledState);
  digitalWrite(ledPin3, ledState);
  digitalWrite(ledPin4, ledState);

  // save the reading.  Next time through the loop,
  // it'll be the lastButtonState:
  lastButtonState = reading;
}


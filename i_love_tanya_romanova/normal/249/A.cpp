/*
Beneath the dampened soil lies a terror from the past
The rotting corpses of the damned where evil has been cast
A deathly curse surrounding all the ancient graves and tombs
The time has come the time is now: release unearthly doom
Lightning strikes, evil night, start the dreaded turmoil
Rotting flesh appears now from above the loosened soil
Rising from the underworld, destroy the human race
Unleashed upon a dreary night to spread unholy grace
From hell they rise, with screams and cries
At death's own will
In frantic rage they set the stage
They start to kill
Evil Invaders: Death deception in the night
Evil Invaders: Corruption as they fight the fight
Evil Invaders: Spreading out to take command
Evil Invaders: The future of mankind at hand
Mutilated bodies now employed upon the streets
Searching around, seeking out the human flesh to eat
Resurgence of the damned will our cities fate defeat?
Unless we're strong and earth defend we'll fall beneath their feet
The evil force grows stronger as the terror grows intense
The panic stricken population builds up its defence
A sudden rude awakening as cities fall to dread
Amidst the human slaughter, tell us how we kill the dead
*/

//#pragma comment(linker, "/STACK:16777216")
#include <fstream>
#include <iostream>
#include <string>
#include <complex>
#include <math.h>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include <stdio.h>
#include <stack>
#include <algorithm>
#include <list>
#include <ctime>
#include <memory.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define  INF 100000000
#define eps 1e-11
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007
#define bsize 256

using namespace std;

double y1,y2,yw,xb,yb,r;

double gdist(double x,double y,double x1,double y1,double x2,double y2)
{
double s=(x-x1)*(y-y2)-(x-x2)*(y-y1);
s=fabs(s);
double d=sqrt((x1-x2)*(x1-x2)+(y1-y2)*(y1-y2));
return s/d;
}

double dy,td;

int main(){
//freopen("melman.in","r",stdin);
//freopen("melman.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
cin.tie(0);

cout.precision(12);

cin>>y1>>y2>>yw>>xb>>yb>>r;
yw-=r;
yb=yw+(yw-yb);
y1+=r;
if (gdist(0,y2,0,y1,xb,yb)<r)
cout<<-1<<endl;
else
{
 dy=yb-y1;
 td=yb-yw;
 cout<<fixed<<xb*((dy-td)/dy)<<endl;
    
}

cin.get();cin.get();
return 0;}
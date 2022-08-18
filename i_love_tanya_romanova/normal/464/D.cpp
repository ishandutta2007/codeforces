/*
We are not the sons of God
We are not His chosen people now
We have crossed the path He trod
We will feel the pain of His beginning

Shadow fingers rise above
Iron fingers stab the desert sky
Oh, behold the power of the earth
Are your children ready for the fall?

Locking hands, together we'll
Raze a city, build a living Hell
Join the race to suicide
Listen for the tolling of the bell

Out of the the universe
A strange light is born
Unholy union, trinity reformed

Yellow sun, it's evil twin
In the black, the winds deliver him
We will sleep to souls within
At a siege a nuclear gust is driven

Out of the the universe
A strange light is born
Unholy union, Trinity reformed

Out of the darkness
Brighter than a thousand suns
Out of the darkness
Brighter than a thousand suns

Out of the darkness
Brighter than a thousand suns
Out of the darkness
Brighter than a thousand suns

Out of the darkness
Brighter than a thousand suns
Out of the darkness
Brighter than a thousand suns

Burying our morals and burying our dead
Burying our head in the sand
E equals MC squared, you can't relate
How we made God with our hands

Whatever would Robert have said to his God?
About he made war with the sun
E equals MC squared, you can't relate
How we made God with our hands

All nations are rising
Through acid bells of love and hate
Chain medals of Satan
Uncertainty led us all to this

All nations are raising
Through acid bells of love and hate
Confusion and fury

Divide and conquer while ye may
Others preach and others fall and pray
In the bunkers, where we'll die
We're the executioners that lie

Bombers launched with no recall
Minute warning of the missile fall
Take a look at your last day
Guessing you wont have the time to cry

Out of the the universe
A strange light was born
Unholy union, Trinity reformed

Out of the darkness
Out of the darkness
Out of the darkness
Brighter than a thousands suns

Out of the darkness
Brighter than a thousand suns
Out of the darkness
Brighter than a thousand suns

Out of the darkness
Brighter than a thousand suns
Out of the darkness
Brighter than a thousand suns

Holy Father, we have sinned
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

#define eps 1e-11
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 512
#define MAG 1000

using namespace std;

long n,k;
double prob[10][MAG+100];
double ans;
double ev[10][MAG+100];
double pup,prem;
double rev[100000];

int main(){
//freopen("highway.in","r",stdin);
//freopen("highway.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>k;
double gz=1.0/k;
for (int i=1;i<=MAG+1000;i++)
 rev[i]=1.0/i;
 
prob[0][1]=1;
ev[0][1]=0;

for (int i=0;i<n;i++)
{
 for (int j=1;j<=MAG;j++)
  prob[1-i%2][j]=ev[1-i%2][j]=0;
  
  long ths,nxt;
  ths=i%2;
  nxt=1-ths;
 for (int j=1;j<=MAG;j++)
 {
  if (prob[ths][j]<1e-50)continue;
  // up ths
  ev[ths][j]/=prob[ths][j];
  pup=gz*rev[j+1];
  prob[nxt][j+1]+=prob[ths][j]*pup;
  ev[nxt][j+1]+=(ev[ths][j]+j)*prob[ths][j]*pup;
  prem=gz*(1.0-rev[j+1]);
  prob[nxt][j]+=prob[ths][j]*prem;
  ev[nxt][j]+=(ev[ths][j]+(j+1)*0.5)*prob[ths][j]*prem;
  prob[nxt][j]+=prob[ths][j]*(1.0-gz);
  ev[nxt][j]+=ev[ths][j]*(1.0-gz)*prob[ths][j];
 }
}

for (int i=1;i<=MAG;i++)
 ans+=ev[n%2][i]*k;

cout.precision(12);
cout<<fixed<<ans<<endl;

cin.get();cin.get();
return 0;}
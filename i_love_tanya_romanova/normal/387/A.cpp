/*
Weak aside - no place for those our struggle
Leaves behind
Our Lord won't tolerate those whom through
Attrition fall

We must dominate!

With iron through our veins and a will made so elite
Hunting for our daily bread and the sinister close in sight
Hunger always drives the beast and the women fall prey.

Leading all the wonders to certain fate

Another victim reviled
I'm staring at you through the eyes of the wolf
Tell me who is going to save you now!

Animal senses ever alert
Praise be to the father-war
As a servant I am serving myself and I bathe in anticipation
Unless you taste it you could never know
All the power our Lord bestows
With a bow and a kiss profane
Be a victor or be a victim.
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
//#include <memory.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define  INF 100000000
#define eps 1e-10
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007

//#define free asdfasdfsdadsg
#define MAXN 10000
//#define SIZE 60
#define bsize 256

using namespace std;

string st1,st2;
long timee;
long gett(string st)
{
 long res=0;
 res=st[0]-48;
 res*=600;
 res+=(st[1]-48)*60;
 res+=(st[3]-48)*10;
 res+=st[4]-48;
 return res;
}

int main(){
//freopen("exchange.in","r",stdin);
//freopen("exchange.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>st1;
cin>>st2;
timee=gett(st1);
timee-=gett(st2);
if (timee<0)timee+=1440;
cout<<timee/600;
timee%=600;
cout<<timee/60<<":";
timee%=60;
cout<<timee/10<<timee%10<<endl;

cin.get();cin.get();
return 0;}
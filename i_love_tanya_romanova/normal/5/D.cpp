/*
Kill all in sight
Defend with your might
Break the man's skull
Rip out his eyes - destroy

On to the fight
We will go
Kill them all
To the Fight

Evil in his soul
You must take control
God's on your side
He is your pride - destroy

Strike make him bleed
Death dying speed
When he is dead
Cut off his head
*/

#pragma comment(linker, "/STACK:16777216")
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
#define bsize 256

using namespace std;

double dv,v,t,n,a,dis,m,l,r,w;
double tm;
double d;
double gv;
double tw,dw;

double gd(double v,double t)
{
 return v*t+(a*t*t)/2.0;
}

double ntime(double d,double v)
{
 dis=v*v+a*d*2;
 r=-v+sqrt(dis);
 r/=a;
 tm=(gv-v)/a;
 if (tm>r)return r;
 return tm+(d-gd(v,tm))/gv;
}

double solve()
{
 if (gv<=w)return ntime(l,0);
 tw=w/a;
 dw=gd(0,tw);
 if (dw>=d)return ntime(l,0);
 return tw+ntime(l-d,w)+2*ntime((d-dw)/2,w);
}

int main(){
//freopen("trade.in","r",stdin);
//freopen("trade.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cout.precision(12);
cin>>a>>v;
gv=v;
cin>>l>>d>>w;

cout<<fixed<<solve()<<endl;

cin.get();cin.get();
return 0;}
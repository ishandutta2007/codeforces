/*
First drop, first untied knot
Long lost time unveiling its lies
Waiting for inevitable
Only rise to fall
When these days are like yesterdays
I'm too proud to feel the same
Welcome here where it all ends
My hopes, my fears, my dreams

So silent after rain, so calm the dawn
The day so pale, I'll pray for mercy for the last time

There is

Hell for me to feel, for me to hear
Hell for me to kneel, for me to sear

In the eye of the blind for the last time
All the words of the numb to hear
Glimpses of past too shallow to last
These fragments too hollow to feel

To hear, to feel, to sear

Last drop, last untied knot
Time to unleash all demons inside
Waiting here for the last lines
I'll close my eyes
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

long long n,q[200000],m,ans[200000],answ,a,b,c;
long calc;

int main(){
//freopen("sufflcp.in","r",stdin);
//freopen("sufflcp.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=1;i<=n;i++)
cin>>q[i];
cin>>m;
for (int i=1;i<=n;i++)
 ans[i]=2e9;
 for (int i=1;i<=m;i++)
 {
  cin>>a>>b>>c;
  ans[b]=min(ans[b],c);
 }
answ=0;
for (int i=1;i<=n;i++)
if (ans[i]<1e8)answ+=ans[i];else ++calc;
if (calc>1)answ=-1;
cout<<answ<<endl;

cin.get();cin.get();
return 0;}
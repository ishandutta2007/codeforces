/*
Deep in the pit and lying alone
Where death has reared itself a throne
We're all the good, the bad, the worst and the best
And where they land is their eternal rest

Foul plays of passion at twilight's dim
In joy of woe, of good and sin
Winds of storm and fates overcast
Darkly my presence is now your past

Join the insanity or die as you fall
Into the pit
The mass production and the killing of all
Into the pit

The future screams for help are fading away
Into the pit
The world tomorrow, will it die for today?
Into the pit

So in the sad, silent watches of night
The lonely pathway envisions my sight
Echoes of laughter and boundless cries
So here I wander under infinite skies

Join the insanity or die as you fall
Into the pit
The mass production and the killing of all
Into the pit

The future screams for help are fading away
Into the pit
The world tomorrow, will it die for today?
Into the pit
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

long long n,h,dp[50][50],r;

int main(){
//freopen("substr.in","r",stdin);
//freopen("substr.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>h;
dp[0][0]=1;
for (int i=1;i<=35;i++)
for (int th=0;th<=35;th++)
 for (int l=0;l<i;l++)
 {
  r=i-l-1;
  for (int j=0;j<=th-1;j++)
   for (int q=0;q<=th-1;q++)
   {
    if (j<th-1&&q<th-1)continue;
    dp[i][th]+=dp[l][j]*dp[r][q];
   }
 }
 long long answ=0;
 for (int i=h;i<=35;i++)
  answ+=dp[n][i];

cout<<answ<<endl;

cin.get();cin.get();
return 0;}
/*
An empty stare, a stupid grin.
Sweating palms and cold within.
Delete past calculations, adapt to a brand new breed.
Sudden movements, the smell of caffeine

Won't ever see me turning the other cheek, tooth for a tooth, I want more than you lies.
Won't ever see me walking away, not forgiving, I won't admit that I'm wrong.

Can't rid the disease, a need of release, the source will pull you under.
Can't rid the disease, a need of release, or a way to end it.

Twitching muscles, an aching head.
Brain hurting, unable to think straight.
A great future would have been, among the lost.
Among deceivers, like himself.

Wont ever see me...

Can't rid the disease...
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
 
 long n,m,ar[1100][1100],dp1[1100][1100],dp2[1100][1100],dp3[1100][1100],
 dp4[1100][1100];
 long answ;
 
int main(){
//freopen("partition.in","r",stdin);
//freopen("partition.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);
 
cin>>n>>m;
for (int i=1;i<=n;i++)
 for (int j=1;j<=m;j++)
  cin>>ar[i][j];

for (int i=1;i<=n;i++)
 for (int j=1;j<=m;j++)
  {
   dp1[i][j]=max(dp1[i-1][j],dp1[i][j-1])+ar[i][j];
  }

for (int i=n;i;--i)
 for (int j=m;j;--j)
 {
  dp2[i][j]=max(dp2[i+1][j],dp2[i][j+1])+ar[i][j];
 }
 
for (int i=n;i;--i)
 for (int j=1;j<=m;j++)
 {
  dp3[i][j]=max(dp3[i+1][j],dp3[i][j-1])+ar[i][j];
 }

for (int i=1;i<=n;i++)
 for (int j=m;j;--j)
 {
  dp4[i][j]=max(dp4[i-1][j],dp4[i][j+1])+ar[i][j];
 }

answ=0;
for (int i=1;i<=n;i++)
 for (int j=1;j<=m;j++)
 {
  if (i==1||i==n||j==1||j==m)continue;
  // l -> r, d -> u
  answ=max(answ,dp1[i][j-1]+dp2[i][j+1]+dp3[i+1][j]+dp4[i-1][j]);
  // u-> d, l -> r
  answ=max(answ,dp1[i-1][j]+dp2[i+1][j]+dp3[i][j-1]+dp4[i][j+1]);
 }
 cout<<answ<<endl;
 
cin.get();cin.get();
return 0;}
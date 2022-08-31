/*
Hiding again behind your wall
Decay decline a downfall
A failure forgotten out of time
Collapse so long ago

Drifting on
Lost on the way
A past beyond memory

Gone past the point of no return
Lead to a place so far gone
The dark embraces all your fears
Someday you'll rise again

Drifting on
Lost on the way
A past beyond memory

Drifting on
Lost the way
A past beyond memory
Minutes seems to pass away
Lost upon my way
A past beyond memory
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

long n,m,s,e,ar1[200000],ar2[200000],dp[111111][321];
set<long> ent[300000];
set<long>::iterator it;
long ans,t;

int main(){
//freopen("partition.in","r",stdin);
//freopen("partition.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m>>s>>e;
for (int i=1;i<=n;i++)
 cin>>ar1[i];
for (int i=1;i<=m;i++)
{
 cin>>ar2[i];
 ent[ar2[i]].insert(i);
}

for (int i=0;i<=n;i++)
 for (int j=0;j<=300;j++)
  dp[i][j]=1e9;

dp[0][0]=0;
for (int i=0;i<=n;i++)
 for (long j=0;j<=s/e;j++)
 {
  if (dp[i][j]<=m&&dp[i][j]+j*e+i<=s)ans=max(ans,j);
  dp[i+1][j]=min(dp[i+1][j],dp[i][j]);
  t=ar1[i+1];
  it=ent[t].upper_bound(dp[i][j]);
  if (it==ent[t].end())continue;
  t=(*it);
  dp[i+1][j+1]=min(dp[i+1][j+1],t);
 }

cout<<ans<<endl;

cin.get();cin.get();
return 0;}
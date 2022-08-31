/*
A unique love rose from a unique hate
Two lovers were caught by their appalling fate
The enmity of their families made
The passion fade and the pain unquell

When dawn came, the city was covered by
A mantle of tragic sighs
The walls of the towers are hard to climb
They're a place of death if you mention who you are

A thin ice covers my soul
My body is frozen and cold
The skies from blue turn to grey
All my desire carries no shame

I'll spread my wings to hold you in my arms
Like daylight chasing the dark
No one can hear me, it's the sound of the night
Tears in my hands. Only loneliness I'll find

A thin ice covers my soul
My body is frozen and cold
The skies from blue turn to grey
All my desire carries no shame
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
#define bsize 256
#define right adsgasgadsg

using namespace std;

long n,ar1[200000],ar2[20000],m;
vector<long> v;
map<long, long> mapp,rmapp;
long calc,next1[1050][1050],next2[1050][1050],
dp[600][600];
pair<long, long> par[600][600];
long q,w,answ;
pair<long, long> ap;
vector<long> avec;

int main(){
//freopen("paired.in","r",stdin);
//freopen("paired.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=1;i<=n;i++)
 cin>>ar1[i];
cin>>m;
for (int i=1;i<=m;i++)
 cin>>ar2[i];

for (int i=1;i<=n;i++)
 v.push_back(ar1[i]);
for (int i=1;i<=m;i++)
 v.push_back(ar2[i]);
sort(v.begin(),v.end());

for (int i=0;i<v.size();i++)
{
 if (i==0||v[i]!=v[i-1])
 {
  mapp[v[i]]=calc;
  rmapp[calc]=v[i];
  ++calc;
 }
}

for (int i=1;i<=n;i++)
 ar1[i]=mapp[ar1[i]];
for (int i=1;i<=m;i++)
 ar2[i]=mapp[ar2[i]];

// nexttt

 for (int j=0;j<=calc;j++)
 {
  next1[n][j]=n+1;
 }
for (int i=n-1;i;--i)
 for (int j=0;j<=calc;j++)
 {
  next1[i][j]=next1[i+1][j];
  if (ar1[i+1]==j)next1[i][j]=i+1;
 }

 for (int j=0;j<=calc;j++)
 {
  next2[m][j]=m+1;
 }
for (int i=m-1;i;--i)
 for (int j=0;j<=calc;j++)
 {
  next2[i][j]=next2[i+1][j];
  if (ar2[i+1]==j)next2[i][j]=i+1;
 }
 
//------------
//dp

for (int i=1;i<=n;i++)
 for (int j=1;j<=m;j++)
  dp[i][j]=-1e9;


for (int i=1;i<=n;i++)
 for (int j=1;j<=m;j++)
  if (ar1[i]==ar2[j])
  {
   if (dp[i][j]<0)dp[i][j]=1;
   for (int p=ar1[i]+1;p<=calc;p++)
   {
    q=next1[i][p];
    w=next2[j][p];
    if (q<=n&&w<=m)
    {
     if (dp[q][w]<=dp[i][j])
     {
      dp[q][w]=dp[i][j]+1;
      par[q][w]=make_pair(i,j);
     }
    }
   }
  }

answ=0;
for (int i=1;i<=n;i++)
 for (int j=1;j<=m;j++)
 {
  if (dp[i][j]>answ)
  {
   answ=dp[i][j];
   ap=make_pair(i,j);
  }
 }

for (int i=answ;i;--i)
{
 avec.push_back(rmapp[ar1[ap.first]]);
 q=par[ap.first][ap.second].first;
 w=par[ap.first][ap.second].second;
 ap=make_pair(q,w);
}
cout<<answ<<endl;
reverse(avec.begin(),avec.end());
for (int i=0;i<avec.size();i++)
{
 if (i)cout<<" ";
 cout<<avec[i];
}
cout<<endl;

cin.get();cin.get();
return 0;}
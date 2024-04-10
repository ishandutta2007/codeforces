/*
Furnace glows in far horizon
Crowd is there to blame
Yes, the harvest of creation
Books will burn again
Lines of faceless humans
Walk into the sea
Waves of men with no expressions
Eyes have lost their gleam

Power guides the mindless ones
Like a moth to the flame of deceit

A storm is rising again
A war is coming again

Black swarms of locusts hide the sun
Plagued fields of east
Tainted grains in the endless field
A war is coming again

Feeding on sorrow, harvesting pain
They will never stop the destruction
Their scythe will rend again
Souls ablaze with hatred

Power guides the mindless ones
Like a moth to the flame of deceit

A storm is rising again
A war is coming again

Black swarms of locusts hide the sun
Plagued fields of east
Tainted grains in the endless field
A war is coming again

Symbols of old just painted anew
Shortest straw is the longest rope
Their guilt will hang innocent hope

A storm is rising again
A war is coming again

Black swarms of locusts hide the sun
Plagued fields of east
Tainted grains in the endless field
A war is coming again
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
#define rmost agasdgasdg

using namespace std;

long n,k,ar[10][1<<10],ps[10][1<<10];
long er;
long dp[1<<10];
long answ,can[1<<10][1<<10];
vector<long> g[1<<10];

int main(){
//freopen("paired.in","r",stdin);
//freopen("paired.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>k;
for (int i=1;i<=k;i++)
{
 for (int j=1;j<=n;j++)
  {
   cin>>ar[i][j];
   ps[i][ar[i][j]]=j;
  }
}

for (int i=1;i<=n;i++)
 for (int j=1;j<=n;j++)
 {
  er=0;
  for (int q=1;q<=k;q++)
   if (ps[q][i]>=ps[q][j])er=1;
  if (er==0)
  g[i].push_back(j);
 }

for (int iter=1;iter<=1000;iter++)
 for (int i=1;i<=n;i++)
 for (int j=0;j<g[i].size();j++)
 {
    dp[i]=max(dp[i],dp[g[i][j]]+1);
 }
answ=0;
for (int i=1;i<=n;i++)
 answ=max(answ,dp[i]);
cout<<answ+1<<endl;

cin.get();cin.get();
return 0;}
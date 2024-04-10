/*
Darkness creeps around us in the twilight time
The string of decoy-ducks is swinging on the waves
Behind the ness
The flock is dabbling
The tension intensifies
Before their takeoff
We hear the wings rustling just before they come
And with the calling sound we bluff them down to land

Deadfall - merciless firestorm 
Deadfall - merciless firestorm 
Take 'em all down

Before it ends
We're running out of shells
And they have gone
We just shot none
Time to stop this lethal game
We have had our chance to take
But we still have days to come
Shallow waters call, my friend

And when the time is right we just can't resist
The call of the gentle wind coming from the west
With those rustling wings they're coming once again
And we're hiding in the bushes waiting for them

Deadfall - merciless firestorm 
Deadfall - merciless firestorm 
Take 'em all down
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

string st1,st2;
long n,m,dp1[5500][5500],dp2[5500][5500],dp3[5500][5500],
dp4[5500],dp5[5500];
long ans,a;

int main(){
//freopen("partition.in","r",stdin);
//freopen("partition.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>st1;
cin>>st2;

n=st1.size();
m=st2.size();

for (int i=n-1;i+1;--i)
 for (int j=n-1;j+1;--j)
 {
  dp1[i][j]=dp1[i+1][j+1]+1;
  if (st1[i]!=st1[j])dp1[i][j]=0;
 }
for (int i=m-1;i+1;--i)
 for (int j=m-1;j+1;--j)
 {
  dp2[i][j]=dp2[i+1][j+1]+1;
  if (st2[i]!=st2[j])dp2[i][j]=0;
 }
for (int i=n-1;i+1;--i)
 for (int j=m-1;j+1;--j)
  {
   dp3[i][j]=dp3[i+1][j+1]+1;
   if (st1[i]!=st2[j])dp3[i][j]=0;
  }

for (int i=0;i<n;i++)
 for (int j=0;j<n;j++)
  if (i!=j)
   dp4[i]=max(dp4[i],dp1[i][j]);

for (int i=0;i<m;i++)
 for (int j=0;j<m;j++)
  if (i!=j)
   dp5[i]=max(dp5[i],dp2[i][j]);

ans=1e8;

for (int i=0;i<n;i++)
 for (int j=0;j<m;j++)
 {
  a=max(dp4[i],dp5[j])+1;
  if (a>dp3[i][j])continue;
  ans=min(ans,a);
 }

if (ans>1e7)ans=-1;
cout<<ans<<endl;

cin.get();cin.get();
return 0;}
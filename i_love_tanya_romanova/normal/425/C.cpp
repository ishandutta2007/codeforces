/*
It's under crimson skies hell's horizon
Our trap will spring
Unaware of our presence they'll be marching
Straight to their doom

We are prepared for war ready to fire
Stand by to charge
Counting down as they march into destruction
Their time has come

They'll never know we give no warning
We set a trap they took the bait
Leading them straight into hell

They will not live to tell the tale
We'll strike at dusk and fight 'til dawn
Tonight our foe is bound to fail
Our time is now all ready at arms

Upon our chosen ground dead men marching
No sign of hope
Victory will be ours before the dawn breaks
Tonight we charge

Chaos and disorder sound of the attack
Charging down the mountain frontal assault
Guns light up the darkness mortars rip the ground
Like a force of nature shaking the field

They'll never know we give no warning
We set a trap they took the bait
Cut off retreat

Released
Unleashed
The beast within berserker rage is
Released
Unleashed
A storm a force unbreakable warmachine

Victims of the ambush
Stains the ground with blood
Fields of execution murderous plan
Soldiers turn to madmen in the dead of night
Fighting with a fury fiery eyes
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
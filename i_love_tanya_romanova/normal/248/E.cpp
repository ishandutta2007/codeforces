/*
Warnings of an air strike
The sirens scream out loud
Warnings on the radio
Of what's coming

Appearing on the radar
A threat from overseas
Planes on the horizon
Cast shadows on the ground

Bringers of destruction
Are ravaging the land
Fury of the bombers
A force to reckon with

Sets the world on fire
Then turns to strike again
Flames are burning higher
The bombs keep falling

AA guns are blazing
As the sky is turning red
Better run for cover
You'll be quick or be dead

Burn, burn, rage of the heavens
Burn, burn, death from above
Die, die, merciless killing
Burn, burn, death from above

Carpet bombing cities
And grinding them to dust
Able men and women
Will all be victims

Everyone will suffer
In the wake of their attack
Bombers show no mercy
A land in ruin

Homes are turned to rubble
When the air strike has been approved
Facing their destruction
Fear the black wings of death

Burn, burn, rage of the heavens
Burn, burn, death from above
Die, die, merciless killing
Burn, burn

Nothing remains
Cities ruined turned to dust
All has been lost
Rise from the ashes and strike

AA guns are blazing
As the sky is turning red
Better run for cover
You'll be quick or be dead

Burn, burn, rage of the heavens
Burn, burn, death from above
Die, die, merciless killing
Burn, burn, death from above
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

long n,a[200000];
double dp[110000][110];
long q,v,e,u,k,tests;
double ans;
double prob;

void add(long u,long v)
{
 for (int j=1;j<=a[u]&&j<=100;j++)
 {
  prob=j*1.0/a[u];
  dp[u][j-1]+=dp[u][j]*prob;
  if (j==1)ans+=dp[u][j]*prob;
  dp[u][j]=dp[u][j]*(1.0-prob);
 }
// cout<<dp[u][0]<<" "<<dp[u][1]<<" "<<dp[u][2]<<endl;
 a[u]--;
}

int main(){
//freopen("melman.in","r",stdin);
//freopen("melman.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
cin.tie(0);

cin>>n;
for (int i=1;i<=n;i++)
{cin>>a[i];if(a[i]==0)ans+=1;}

for (int i=1;i<=n;i++)
dp[i][a[i]]=1;

cout.precision(11);
cin>>tests;
for (;tests;--tests)
{
 cin>>u>>v>>k;
 for (int j=1;j<=k;j++)
 add(u,v);
 a[v]+=k;
 cout<<fixed<<ans<<endl;    
}
cin.get();cin.get();
return 0;}
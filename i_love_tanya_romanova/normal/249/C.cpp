/*
Warriors of leather unchained to rule the night
Ganglands join together to fight the metal fight
Speed and fury now delivered to the hungry crowd
Trashing like there's no tomorrow, that's what it's about
Rages like an earthquake shaking all your heads
Death to all the posers, tear then all to shreds
Breaking down the barriers we'll let it go tonight
Let's all bring the roof down and trash with all our might
Speed Merchants decked out in spikes and chains
Speed Merchants have metal in their veins
Speed Merchants cut loose and bash their brains
Speed Merchants we sweat and go insane
Furious intentions directed at the stage
A building of agressionis now released in rage
You raise your hands to feel the awesome power in the air
Your body aches, your neck it breaks, but you don't seem to care
Burning hearts of fire amidst the human mass
Intensities reach maximum wich we shall now surpass
Draining all our energy, stricken with abuse
A deadly charge like dynamite, we've got to light the fuse
Scorching blaze surrounds them as the metal takes control
It penetrates their willing minds and occupies their souls
Speed Merchants live for pleasure, Speed Merchants live for pain
They live for understanding and sparks to start the flame
Speed merchants!
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
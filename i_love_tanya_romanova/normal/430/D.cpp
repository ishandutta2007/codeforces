/*
Under the ice
we hide from your stare
buried in grief and despair
We're the debris,
the scattered remains
leaves in the storm
who is lashing the world

Destiny calls
extinction of man
will it all happen again
But yet we're alive
unbroken we stand
bannish the conquerer
who's taken the land

We'll be a thorn in your unhuman flesh
there'll be a time for retortion
We'll break the fetters, we'll never give in
although it seems our end will begin

Forces united - forces arise
Legions of iron descent from the skies
Dark knight - you'll never defeat
the immortal spirit of freedom
Savior - watch out beware
we will engage
The Forces Of Rage

Starbirds are gliding
on winds of decay
merciless hunting the pray
Infernal machine
the hatchet of war
sharp as a razor
will cut back the claw

We'll be the virus - a deadly disease
the fever is burning inside you
To bring you to fail is the ultimate aim
we'll rise from the ashes again and again

Forces united - forces arise
Legions of iron descent from the skies
Dark knight - you'll never defeat
the immortal spirit of freedom
Savior - watch out beware
we will engage

Free - at least for a moment in time
Years - how many years have gone by
In fury and wharf we're looking above
forging the sword, the blade of reprisal
Leaders of man let's ride out again
From fire and ice a blazing star will arise!

We'll be a thorn

Forces united - forces arise
Legions of iron descent from the skies
Dark knight - you'll never defeat
the immortal spirit of freedom
Savior - watch out beware
we will engage
The Forces Of Rage
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
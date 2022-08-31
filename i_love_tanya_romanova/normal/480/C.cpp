/*
In the shades of
The verdant forest
Tender and mild winds
Are washing the leaves

Echoing whispers
Lead me to valley
Where a tree stands in
A silver dress

[Chorus:]
Leaves shaped of tears
Of sorrow and lonely tears
Gleaming in the light
Of the rising sun
The silvery leaves are
Covering all my tears
As I sit under
The Willow Of Tears

Whispers are calling
In Beaming dreamy air
On the meadow where
The willow and I

Wait for the mist to come
To dance on the silver pond
It slowly guides us
To eternal sleep

[Chorus x2]
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
#define free adsgasdg

using namespace std;

long n,a,b,k,dp[5050][5050],up,wl;
long d,lw;
void ad(long&a,long b)
{
 a+=b;
 if (a>=bs)a-=bs;
}
long ans;

int main(){
//freopen("logins.in","r",stdin);
//freopen("logins.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>a>>b>>k;

dp[0][a]=1;
for (int iter=0;iter<k;++iter)
{
 for (int j=1;j<=n;j++)
 {
  d=abs(b-j);
  --d;
  up=j+d;
  lw=j-d;
  if (up>n)
  up=n;
  ad(dp[iter+1][up],dp[iter][j]);
  if (lw>1)
   ad(dp[iter+1][lw-1],bs-dp[iter][j]);
 }
 for (int j=n;j;--j)
  ad(dp[iter+1][j],dp[iter+1][j+1]);
 for (int j=n;j;--j)// don't stay
  ad(dp[iter+1][j],bs-dp[iter][j]);
}
ans=0;
for (int i=1;i<=n;i++)
 ad(ans,dp[k][i]);

cout<<ans<<endl;

cin.get();cin.get();
return 0;}
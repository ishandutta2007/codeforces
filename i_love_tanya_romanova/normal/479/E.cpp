/*
I turned you down so hastily
And it's tearing me apart
In my heart of hearts I'm screaming
In my heart of hearts I cry
And it's cold
So cold
I turned you down
Oh, I turned you down so thoughtlessly
And it's tearing me apart
In my heart of hearts I'm screaming
In my heart of hearts I cry
How I wish you told me that
I wish you'd told me that before
I wish you'd told me that before
I wish you'd told me that before
I turned you down
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
/*
I can really safely say
That you're still alive
One thing they can't take away
Is your will to survive

I know I won't believe it
I know I won't believe it
They say you can't be found
This man is better off dead

They want to turn your head around
Turn your head around
Turn your head around
Turn your head around

How can they leave you lying there
Hiding from the lights
They don't know and they couldn't care
They'll be dead by tonight

Someone's made a big mistake
I can't believe my ears
Just how long will this thing take
Give him days, months and years
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

#define eps 1e-10
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256
#define right adsgasgadsg

using namespace std;

long long n,m,k,ar[1<<14],s[1<<14],dp[5050][5050];

int main(){
//freopen("paired.in","r",stdin);
//freopen("paired.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m>>k;

for (int i=1;i<=n;i++)
{
 cin>>ar[i];
 s[i]=s[i-1]+ar[i];
}

for (int i=1;i<=n;i++)
 for (int j=0;j<=k;j++)
  dp[i][j]=-1e18;

for (int i=1;i<=n;i++)
 for (int j=0;j<=k;j++)
 {
  dp[i][j]=dp[i-1][j];
  if (j>0&&i>=m)
  dp[i][j]=max(dp[i][j],dp[i-m][j-1]+s[i]-s[i-m]);
 }
cout<<dp[n][k]<<endl;

cin.get();cin.get();
return 0;}
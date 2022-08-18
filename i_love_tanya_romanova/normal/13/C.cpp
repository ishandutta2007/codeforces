/*
Medication Time
My favorite part
Hello Rainbow Box
Need you to survive

White is for my health
Blue for happiness
Thanks to Red I die and live
With a shade of smile on my face

Alpha waves appeared
I've crossed a line
Sea of memories
Feel I'm going down

Achromatic day
Got choked by colored pills
I thought that I could
But the icy water closed over me

You know
Want to feel alive
Need you more
Anytime

You know
Want to feel alive
Need you more
Anytime
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

#define EPS 1e-11
//#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256
#define right adsgasgadsg

using namespace std;

long long n,ar[10000],dp[3][10000];
vector<long long> v;
long long answ,z[10000];

int main(){
//freopen("paired.in","r",stdin);
//freopen("paired.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=1;i<=n;i++)
 cin>>ar[i];

for (int i=1;i<=n;i++)
{
 v.push_back(ar[i]);
}

sort(v.begin(),v.end());

for (int i=1;i<=n;i++)
{
 z[i]=v[i-1];
}

for (int i=1;i<=n;i++)
 dp[1][1]=abs(ar[1]-z[1]);

for (int i=2;i<=n;i++)
 dp[1][i]=min(dp[1][i-1],abs(ar[1]-z[i]));

for (int i=2;i<=n;i++)
{
/* for (int j=1;j<=n;j++)
 cout<<dp[1-i%2][j]<<" ";
 cout<<endl;
*/
 for (int j=1;j<=n;j++)
  dp[i%2][j]=1e18;
 for (int j=1;j<=n;j++)
 {
  if (j==1)dp[i%2][j]=dp[1-i%2][j]+abs(ar[i]-z[j]);
  else
  {
   dp[i%2][j]=min(dp[1-i%2][j]+abs(ar[i]-z[j]),dp[i%2][j-1]);
  }
 }
}
/*
for (int i=1;i<=n;i++)
 cout<<dp[n%2][i]<<" ";
cout<<endl;
*/
answ=1e18;
for (int i=1;i<=n;i++)
 answ=min(answ,dp[n%2][i]);

cout<<answ<<endl;

cin.get();cin.get();
return 0;}
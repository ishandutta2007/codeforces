/*
We are living in search of
The american dream
Based on the almighty dollar
Oh! How we wheel, deal and scheme
Pray to God you get your share
There's no rainbow it's not there - No oh! oh!

We're all stealing and cheating
Work yourself 'til you bleed
This is the way of the dollar
No one is immune to the greed
Pray to God you get your share
No pot of gold it's not there - No oh! oh!

For greed we live
In need we die
Your life's a circle
We live and die for something that we'll never have
For greed!

For greed you live
In need you die
Your life's a circle
You live and die for something that you'll never have
For greed! For greed! For greed!
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

long long d,n,a[1<<20],b,root,ans;
vector<long> g[1<<20];
long long used[1<<20],dp[1<<20];

bool better(long v1,long v2)
{
 if (a[v1]!=a[v2])return a[v1]>a[v2];
 return v1>v2;
}

void dfs(long v)
{
 used[v]=1;
 dp[v]=1;
 for (int i=0;i<g[v].size();i++)
 {
  long q=g[v][i];
  if(used[q])continue;
  if (better(q,root))continue;
  if (a[root]>a[q]+d)continue;
  dfs(q);
  dp[v]+=dp[v]*dp[q]%bs;
  dp[v]%=bs;
 }
}

int main(){
//freopen("digits.in","r",stdin);
//freopen("digits.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>d>>n;
for (int i=1;i<=n;i++)
 cin>>a[i];

for (int i=1;i<n;i++)
{
 long a,b;
 cin>>a>>b;
 g[a].push_back(b);
 g[b].push_back(a);
}

for (int i=1;i<=n;i++)
{
 for (int j=1;j<=n;j++)
  used[j]=dp[j]=0;
 root=i;
 dfs(i);
 ans+=dp[i];
 ans%=bs;
}
cout<<ans<<endl;

cin.get();cin.get();
return 0;}
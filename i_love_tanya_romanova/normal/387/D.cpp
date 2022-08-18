/*
Resign my brain.
Knows bored, minds cored.
Your fate has come rewound.
I thought the day I'd die you'd rule.

Rewind my sense.
Range choice of live expense.
Days come, nights fall.
Fix all mistakes, rule all.

When is locked in.
Set back within your realm of violence.
If you see anything, soon we'll rise.

Resign, my brain.
Knows bored, minds cored.
Your fate has come, rewound.
I said the day I'd rule you'd die.

Resign my friend.
Knows bored, minds cored.
Your fate has come rewound.
I said the day I'd rule you'd die.
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
//#include <memory.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash

#define  INF 100000000
#define eps 1e-10
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007

//#define free asdfasdfsdadsg
#define MAXN 10000
//#define SIZE 60
#define bsize 256

using namespace std;

long n,m,a,b;
vector<pair<long, long> > edges;
vector<long> g[20000];
long ans,tans;
long mt[200000],used[200000];

bool try_kuhn(long v)
{
 if (used[v])return false;
 used[v]=1;
 for (int i=0;i<g[v].size();i++)
 {
  long to=g[v][i];
  if (mt[to]==-1||try_kuhn(mt[to]))
  {mt[to]=v;return true;}
 }
 return false;
}

int main(){
//freopen("exchange.in","r",stdin);
//freopen("exchange.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>m;
for (int i=1;i<=m;i++)
{
    cin>>a>>b;
    edges.push_back(make_pair(a,b));
}

ans=1e9;
for (int center=1;center<=n;center++)
{
 tans=2*n-1;
 for (int i=1;i<=n;i++)
 g[i].clear();
 for (int i=0;i<m;i++)
 {
  if (edges[i].first==center||edges[i].second==center)--tans;
  else {tans++;
  g[edges[i].first].push_back(edges[i].second);
 }}
 
 // dpa +-
 tans+=(n-1);
 
/// cout<<tans<<endl;
 for (int i=1;i<=n;i++)
 mt[i]=-1;
 
 for (int i=1;i<=n;i++)
  {
   for (int j=1;j<=n;j++)
   used[j]=0;
   try_kuhn(i);
  }
  long q=0;
  
 for (int i=1;i<=n;i++)
 if (mt[i]!=-1)
 ++q,tans-=2;
 //cout<<center<<" "<<q<<endl;
 ans=min(ans,tans);
}

cout<<ans<<endl;

cin.get();cin.get();
return 0;}
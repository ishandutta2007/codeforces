/*
The first time I saw you, you were chasin' down
A cyclone all alone in the field
With rail yards and clovers, I kept rollin' on
Never thought you'd wind up chasin' me

Settle down, I won't hesitate to hit the highway
Before you lay me to waste, no
Saddle up and I'll help you find something to drive
Before you drive me insane

You're tired of walkin' and you loathe the ground
The sidewalk will barely touch your feet
Life moves too slowly to hold you down
With ring in hand you take it out on me

Settle down, I won't hesitate to hit the highway
Before you lay me to waste, no
Saddle up and I'll help you find something to drive
Before you drive me insane

So get yourself a car and drive it all alone
Get yourself a car and ride it on the wind, yeah
Get yourself a car and drive it all alone
Get yourself a car and ride it on the wind

Settle down, I won't hesitate to hit the highway
Before you lay me to waste, no
Saddle up and I'll help you find something to drive
Before you drive me insane

So get yourself a car and drive it all alone
You get yourself a car and ride it on the wind, yeah
Well, get yourself a car and drive it all alone
Get yourself a car and ride it on the wind
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

using namespace std;

long n,m,tests,a,b;
vector<long> g[500000];
long w[500000];
long diam[500000];
long used[500000];
long qd,tp;
long v,q;
long sdep[500000];

long gett(long v)
{
 if (v!=w[v])return w[v]=gett(w[v]);
 return v;
}

void merg(long a,long b)
{
 a=gett(a);
 b=gett(b);
 if (rand()%2)w[a]=b;
 else w[b]=a;
}

void dfs(long v)
{
 used[v]=1;
 sdep[v]=0;
 vector<pair<long, long> > sons;
 for (int i=0;i<g[v].size();i++)
 {
  long q=g[v][i];
  if (used[q])continue;
  dfs(q);
  sons.push_back(make_pair(sdep[q],q));
 }
 sort(sons.begin(),sons.end());
 reverse(sons.begin(),sons.end());
 if (sons.size())qd=max(qd,sons[0].first+1);
 if (sons.size()>1)qd=max(qd,sons[0].first+sons[1].first+2);
 if (sons.size())sdep[v]=max(sdep[v],sons[0].first+1);
}

int main(){
//freopen("rush.in","r",stdin);
//freopen("rush.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m>>tests;
for (int i=1;i<=n;i++)
{
 diam[i]=0;
 w[i]=i;
}

for (int i=1;i<=m;i++)
{
 cin>>a>>b;
 g[a].push_back(b);
 g[b].push_back(a);
 merg(a,b);
}
for (int i=1;i<=n;i++)
{
 if (used[i]==0)
 {
  qd=0;
  dfs(i);
  diam[gett(i)]=qd;
 }
}

for (int i=1;i<=tests;i++)
{
 cin>>tp;
 if (tp==1)
 {
  cin>>v;
  cout<<diam[gett(v)]<<"\n";
 }
 else
 {
  cin>>a>>b;
  if (gett(a)==gett(b))continue;
  a=gett(a);
  b=gett(b);
  q=(diam[a]+1)/2+(diam[b]+1)/2+1;
  if (q<max(diam[a],diam[b]))q=max(diam[a],diam[b]);
  diam[a]=diam[b]=q;
  merg(a,b);
 }
}

cin.get();cin.get();
return 0;}
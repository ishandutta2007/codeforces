/*
Silent calls of solitude
Waiting for decline
Delivered from their passion
To spill the blood tonight

Laughing dead corruption
The truth is just a fake
Undying hate is buried
Into a nameless grave

Don't be afraid
Don't run away

Their past has been divided
Emperor's sacrifice
The dead will take the reign
Blessed by the guns

City of God

Crawling deep into your soul
A life that fades away
Balanced on the edge of scorn
For whom you gonna pray

Terror without pity
Insane and tearing minds
All wars could be forgotten
When life is so unkind

Don't be afraid
Don't run away

Their past has been divided
Emperor's sacrifice
The dead will take the reign
Blessed by the guns

City of God

Don't be afraid
Don't run away

Their past has been divided
Emperor's sacrifice

City of God

The dead will take the reign
Blessed by the guns

City of God
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

long long n,m,start,fin,a,b,c,
v1[200000],v2[200000];
vector<pair<long long,long long> > g[20000];
long long dist[200000];
set<pair<long long, long long> > ::iterator it;
set<pair<long long, long long> > sett;
long long qv;
pair<long long, long long> tp;
long long tc;
long long d[1200][1200];
long long bst,bp;
long long ans[20000];
long long used[200000];

int main(){
//freopen("paired.in","r",stdin);
//freopen("paired.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m;
cin>>start>>fin;
for (int i=1;i<=m;i++)
{
 cin>>a>>b>>c;
 g[a].push_back(make_pair(b,c));
 g[b].push_back(make_pair(a,c));
}

for (int i=1;i<=n;i++)
 cin>>v1[i]>>v2[i];
 
for (int st=1;st<=n;st++)
{
 for (int i=1;i<=n;i++)
  dist[i]=1e18;
 dist[st]=0;
 sett.clear();
 for (int i=1;i<=n;i++)
  sett.insert(make_pair(dist[i],i));
  
 for (int iter=1;iter<=n;iter++)
 {
  it=sett.begin();
  tp=(*it);
  sett.erase(it);
  qv=tp.second;
  for (int i=0;i<g[qv].size();i++)
  {
   long long q=g[qv][i].first;
   long long c=g[qv][i].second;
   tc=c+dist[qv];
   if (dist[q]>tc)// upd
   {
    sett.erase(make_pair(dist[q],q));
    dist[q]=tc;
    sett.insert(make_pair(dist[q],q));
   }
  }
 }
 for (int i=1;i<=n;i++)
  if (dist[i]>v1[st])d[st][i]=1e18;
  else d[st][i]=v2[st];
}
/*
for (int i=1;i<=n;i++)
{
 for (int j=1;j<=n;j++)
  cout<<d[i][j]<<" ";
 cout<<endl;
}*/
for (int i=1;i<=n;i++)
 ans[i]=1e18;
ans[start]=0;

for (int iter=1;iter<=n;iter++)
{
 bst=bp=1e18+1e12;
 for (int i=1;i<=n;i++)
 {
  if (used[i]==0&&ans[i]<bst)
  {
   bst=ans[i];
   bp=i;
  }
 }
 used[bp]=1;
 for (int i=1;i<=n;i++)
  if (d[bp][i]+bst<ans[i])
   ans[i]=d[bp][i]+bst;
}
if (ans[fin]>1e17)ans[fin]=-1;
cout<<ans[fin]<<endl;

cin.get();cin.get();
return 0;}
/*
The love that you bring
You bring me alone
The pain that you give
Gives me a home

Do you wanna stay by my side?
Do you want me to turn and hide?
We are disappearing inside
Seeing pictures of our goodbyes

When we, we believe
That our love will survive
The pain that you bring
Brings me all alone

Do you love me, do you hate me?
Do you wanna believe me?
Do you think that you don't need me?
Do you wanna deceive me?

I can't take that it's all over, don't want to forget
I can take the disappointment down
I want to repress your goodbye, goodbye

The design, we broke the mold
The dreams when you see
That goodbyes aren't for long

Please follow me to the borders of destiny
I don't want to break from your side
The falling ground screams goodbye

Please follow me to the borders of destiny
I don't want to break from your side
The falling ground screams goodbye

Goodbye, goodbye
The design, we broke the mold
The dreams when you see
That goodbyes aren't for long
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
//#include <memory.h>

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
//#define N 120000

using namespace std;

long long n,m,k,a,b,c;

set<pair<long long, long long> > sett;
set<pair<long long, long long> >::iterator it;
long long dist[200000];
vector<pair<long long, long long> > g[200000];
vector<long long> vec[200000];
long long ways[200000];
long long qv,qcost,tv,tcost;

void add_edge(long long a,long long b,long long c)
{
 g[a].push_back(make_pair(b,c));
 g[b].push_back(make_pair(a,c));
}

int main(){
//freopen("path.in","r",stdin);
//freopen("path.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m>>k;
for (int i=1;i<=m;i++)
{
 cin>>a>>b>>c;
 add_edge(a,b,c);
}
for (int i=1;i<=k;i++)
{
 cin>>a>>b;
 vec[a].push_back(b);
}

for (int i=1;i<=n;i++)
{
 sort(vec[i].begin(),vec[i].end());
 if (vec[i].size()>0)
 {
  add_edge(1,i,vec[i][0]);
 }
}

for (int i=1;i<=n;i++)
 dist[i]=1e16;
ways[1]=1;
dist[1]=0;

for (int i=1;i<=n;i++)
{
 sett.insert(make_pair(dist[i],i));
}

for (int iter=1;iter<=n;iter++)
{
 it=sett.begin();
 qv=(*it).second;
 qcost=(*it).first;
 sett.erase(it);
 for (int i=0;i<g[qv].size();i++)
 {
  tv=g[qv][i].first;
  tcost=g[qv][i].second+qcost;
  if (tcost>dist[tv])continue;
  if (tcost==dist[tv]){ways[tv]+=ways[qv];continue;}
  sett.erase(make_pair(dist[tv],tv));
  dist[tv]=tcost;
  ways[tv]=ways[qv];
  sett.insert(make_pair(dist[tv],tv));
 }
}

for (int i=1;i<=n;i++)
{
// cout<<dist[i]<<" & "<<ways[i]<<endl;
}

for (int i=1;i<=n;i++)
{
 if (vec[i].size()==0)continue;
 if (vec[i][0]==dist[i]&&ways[i]==1)--k;
}
cout<<k<<endl;

cin.get();cin.get();
return 0;}
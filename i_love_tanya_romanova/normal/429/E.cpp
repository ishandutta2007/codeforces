/*
To walk an eternity of steps
For it all to end at one...
Disheartened

Laments of emptiness,
In being of barren decay.
The gritty dusk holds,
the poems of everlasting distress...
Absence...

Transparent memory of the purest emptiness.
Amnesty in nothing but void...
For all that will remain...
Silence...

The autumn sky, Moving wings of crimson light,
For an enternity, it never reached the soul.
Winds of solemn despair, Carrying a final breath...

I wither...

Away...
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

set<pair<pair<long, long> ,long> > s;
set<pair<pair<long, long>, long> > ::iterator it;
long n;
long a,b;
pair<pair<long, long>,long> p1,p2;
vector<long> g[200000];
long ans[200000];

void dfs(long v,long c)
{
 ans[v]=c;
 for (int i=0;i<g[v].size();i++)
 {
  long q=g[v][i];
  if (ans[q])continue;
  dfs(q,3-c);
 }
}

int main(){
//freopen("partition.in","r",stdin);
//freopen("partition.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n;
for (int i=1;i<=n;i++)
{
 cin>>a>>b;
 s.insert(make_pair(make_pair(a,b),i));
}

while (s.size()>1)
{
 it=s.begin();
 p1=(*it);
 it++;
 p2=(*it);
 if (p1.first.second<p2.first.first){s.erase(p1);continue;}
 a=p1.second;
 b=p2.second;
 g[a].push_back(b);
 g[b].push_back(a);
 if (p1.first.second==p2.first.second)
 {
  s.erase(p1);s.erase(p2);continue;
 }
 if (p1.first.second<p2.first.second)
 swap(p1,p2);
 s.erase(p1);s.erase(p2);
 s.insert(make_pair(make_pair(p2.first.second+1,p1.first.second),p1.second));
}

for (int i=1;i<=n;i++)
 if (ans[i]==0)
  dfs(i,1);
  
for (int i=1;i<=n;i++)
{
 if (i>1)cout<<" ";;
 cout<<ans[i]-1;
}
cout<<endl;

cin.get();cin.get();
return 0;}
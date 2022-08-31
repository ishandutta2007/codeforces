/*
Now I think I understand
How this world can overcome a man
Like a friend we saw it through
In the end I gave my life for you

Gave you all I had to give
Found a place for me to rest my head
While I may be hard to find
Heard there's peace just on the other side

Not that I could
Or that I would
Let it burn under my skin
Let it burn

Left this life to set me free
Took a piece of you inside of me
All this hurt can finally fade
Promise me you'll never feel afraid

Not that I could
Or that I would
Let it burn under my skin
Let it burn


I hope it's worth it, here on the highway, yeah 
I know you'll find your own way
When I'm not with you

So tell everybody, the ones who walk beside me, yeah
I hope you find your own way
When I'm not with you tonight

I hope it's worth it, what's left behind me, yeah
I know you'll find your own way
When I'm not with you

So tell everybody, the ones who walk beside me, yeah
I know you'll find your own way
When I'm not with you tonight
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

long n,m,a,b;
vector<long> g[200000];
set<pair<long, long> > done;
vector<pair<long, pair<long, long> > > ans;
long ptr[300000];

long dfs(long v)
{
// cout<<v<<endl;
 vector<long> dd;
 dd.reserve(16);
 for (;ptr[v]<g[v].size();ptr[v]++)
 {
  long q=g[v][ptr[v]];
//  ++ptr[v];
  pair<long, long> p=make_pair(min(v,q),max(v,q));
  if (done.find(p)!=done.end())continue;
  if (p.first>p.second)swap(p.first,p.second);
  done.insert(p);
  long t=dfs(q);
  if (t==0)
  dd.push_back(q);
  else
  {
   ans.push_back(make_pair(v,make_pair(q,t)));
  }
 }
 long t=dd.size()%2;
 for (int i=t;i<dd.size();i+=2)
 {
  long a,b;
  a=dd[i];
  b=dd[i+1];
  ans.push_back(make_pair(a,make_pair(v,b)));
  done.insert(make_pair(min(a,v),max(a,v)));
  done.insert(make_pair(min(b,v),max(b,v)));
 }
 if (dd.size()%2==0)return 0;
 done.insert(make_pair(min(dd[0],v),max(dd[0],v)));
 return dd[0];
}

int main(){
//freopen("cyclic.in","r",stdin);
//freopen("cyclic.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
cin.tie(0);

cin>>n>>m;
if (m%2)
{
 cout<<"No solution"<<endl;
 return 0;
}
for (int i=1;i<=m;i++)
{
 cin>>a>>b;
 g[a].push_back(b);
 g[b].push_back(a);
}

dfs(1);
for (int i=0;i<ans.size();i++)
{
 cout<<ans[i].first<<" "<<ans[i].second.first<<" "<<ans[i].second.second<<endl;
}

cin.get();cin.get();
return 0;}
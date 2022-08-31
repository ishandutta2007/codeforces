/*
You can't expect to see him and survive
You'll swallow his tongue of thorns
His mouth, dripping with flies
In his glorious kingdom of fire
But I believe he wept
I will make them all lie down
Down where hope lies dying
With lust, you're kicking mankind to death
We live and die without hope
You tramp us down in a river of death
As I stand here now, my heart is black
I don't want to die a lonely man
This is a weary hour
This is a weary hour
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

vector<pair<long, long> > quer[666666];
vector<long> g[666666];
long ans[666666];
long arp[666666];
long n,m,cl[666666];
long a,b;

struct cmap
{
 map<long, long> c;
 map<long, long> s;
 map<long, long>::iterator it;
 cmap(){c.clear();s.clear();}
 void add(long a,long b)
 {
  it=c.find(a);
  if (it==c.end())
  {c[a]=b;++s[b];}
  else
  {
   long temp=c[a];
   --s[temp];
   ++s[temp+b];
   c[a]+=b;
  }
 }
 long size(){return c.size();}
};

cmap *merge(cmap *a, cmap *b)
{
 if (!a)return b;
 if (!b)return a;
 if (a->size()>b->size())swap(a,b);
 map<long, long>::iterator it;
 for (it=a->c.begin();it!=a->c.end();++it)
  b->add((*it).first,(*it).second);
 return b;
}

cmap* dfs(long v)
{
// cout<<v<<endl;
 arp[v]=1;
 cmap* cur=0;
 for (int i=0;i<g[v].size();i++)
 {
  long q=g[v][i];
  if (arp[q])continue;
  cur=merge(cur,dfs(q));
 }
 if (!cur)cur=new cmap();
 cur->add(cl[v],1);
 
 for (int i=0;i<quer[v].size();i++)
 {
  map<long, long>::iterator it;
  for (it=cur->s.begin();it!=cur->s.end();it++)
  {
 //  if (v==1&&i==0)
 //  cout<<(*it).first<<" % "<<(*it).second<<" "<<quer[v][i].first<<endl;
   if ((*it).first>=quer[v][i].first)
    ans[quer[v][i].second]+=(*it).second;
  }
 }
 return cur;
}

int main(){
//freopen("circuit.in","r",stdin);
//freopen("circuit.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);

cin>>n>>m;
for (int i=1;i<=n;i++)
{
 cin>>cl[i];   
}
for (int i=1;i<n;i++)
{
    cin>>a>>b;
    g[a].push_back(b);
    g[b].push_back(a);
}

for (int i=1;i<=m;i++)
{
    cin>>a>>b;
    quer[a].push_back(make_pair(b,i));
}

dfs(1);

for (int i=1;i<=m;i++)
cout<<ans[i]<<endl;

cin.get();cin.get();
return 0;}
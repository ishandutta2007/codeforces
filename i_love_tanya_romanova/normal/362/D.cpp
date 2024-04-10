/*
Too much in the truth they say
Keep it 'till another day
Let them have their little game
Illusion helps to keep them sane

Let them have their little toys
Matchbox cars and mortgaged joy
Exciting in their plastic ways
Frozen food in a concrete maze

You're gonna go insane
I'm trying to save your brain

I don't know what's happening
My head's all torn inside
People say I'm heavy
They don't know what I hide

Take a life, it's going cheap
Kill someone, no one will weep
Freedom's yours, just pay your dues
We just want your soul to use

You're gonna go insane
I'm trying to save your brain
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
#define eps 1e-7
//#define M_PI 3.141592653589793
//#define mx 1000000000000ll
#define bs 1000000007

//#define free asdfasdfsdadsg
//#define pb push_back
#define MAXN 10000
#define free afdshjioey
//#define SIZE 60
#define bsize 256

using namespace std;

long long a,b,c,n,m,p,q;
long long w[200000],d[200000];
set<pair<long long,long long> > g;
long long sz[200000];
set<pair<long long, long long> > comps;
set<pair<long long, long long> > ::iterator it;
long long q1,q2,cost1,cost2;
long long tcost;
vector<pair<long long, long long> > ans;

vector<long long> compp[200000];

void add_edge(long long a,long long b)
{
     ans.push_back(make_pair(a,b));
}

long gett(long x)
{
 if (w[x]==x)return x;
 return gett(w[x]);
}

void merg(long long a,long long b)
{
 w[a]=b;
 long long tc=tcost;//sz[a]+sz[b]+tcost;
 comps.erase(make_pair(sz[a],a));
 comps.erase(make_pair(sz[b],b));
 sz[b]=sz[a]+sz[b]+tc;
 comps.insert(make_pair(sz[b],b));
 for (int i=0;i<compp[a].size();i++)
 compp[b].push_back(compp[a][i]);
 compp[a].clear();
} 
 
int main(){
//freopen("gift.in","r",stdin);
//freopen("gift.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
//ios_base::sync_with_stdio(0);

cin>>n>>m>>p>>q;
for (int i=1;i<=n;i++)
w[i]=i;

for( int i=1;i<=m;i++)
{
 cin>>a>>b>>c;
 g.insert(make_pair(a,b));
 g.insert(make_pair(b,a));
 
 while (a!=w[a])a=w[a];
 while (b!=w[b])b=w[b];
 if (a==b){sz[a]+=c;continue;}
 if (d[a]>d[b])
 {
  w[b]=a;sz[a]=sz[b]+sz[a]+c;
 }    
 else
 {
     w[a]=b;sz[b]=sz[a]+sz[b]+c;
     if (d[a]==d[b])++d[b];
 }
}

for (int i=1;i<=n;i++)
{
 if (w[i]==i)
 comps.insert(make_pair(sz[i],i));   
}

if (comps.size()<q)
{
 cout<<"NO"<<endl;
 return 0;
}

for (int i=1;i<=n;i++)
compp[gett(i)].push_back(i);

for (int i=1;i<=p;i++)
{
    if (comps.size()==q)break;
    it=comps.begin();
    q1=(*it).second;
    cost1=(*it).first;
    ++it;
    q2=(*it).second;
    cost2=(*it).first;
    tcost=cost1+cost2+1;
    if (tcost>1000000000)tcost=1000000000;
    cost1=cost1+cost2+tcost;
    add_edge(q1,q2);
    
    if (compp[q1].size()>compp[q2].size())
    merg(q2,q1);
    else merg(q1,q2);
}

for (int i=1;i<=n;i++)
if (compp[i].size()>1)
{
 while (ans.size()<p)
 add_edge(compp[i][0],compp[i][1]);
}
if (ans.size()==p&&comps.size()==q)
{cout<<"YES"<<endl;
 for (int i=0;i<ans.size();i++)
 cout<<ans[i].first<<" "<<ans[i].second<<endl;
}
else
{
    cout<<"NO"<<endl;
}
cin.get();cin.get();
return 0;}
/*
You just stood there screaming
Fearing no one was listening to you
They say the empty can rattles the most
The sound of your own voice must suit you

Hearing only what you want to hear
And knowing only what you've heard
You, you're smothered in tragedy
And you're off to save the world

Misery
You insist that the weight of the world
Should be on your shoulders

Misery
There's much more to life than what you see
My friend of misery

You still stood there screaming
No one caring about these words you tell
My friend before your voice is gone
One man's fun is another's hell

These times are sent to try men's souls
But something's wrong with all you see
You, you'll take it on all yourself
Remember, misery loves company

Misery
You insist that the weight of the world
Should be on your shoulders

Misery
There's much more to life than what you see
My friend of misery, my friend of misery

You just stood there screaming
My friend of misery

Misery
You insist that the weight of the world
Should be on your shoulders

Misery
There's much more to life than what you see
My friend of misery, my friend of misery

You just stood there screaming
My friend of misery

Yeah, yeah, go
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
 
using namespace std;

long n,m,k,w;
string st;
long ar[1010][12][12];
long d[1010][1010],dist[1010],bst,bp,ans;
long used[200000],par[200000];
vector<long> g[20000];
long arp[20000];
vector<pair<long,long> > answ;

void add_edge(long a,long b)
{
 g[a].push_back(b);
 g[b].push_back(a);
}

void dfs(long a,long b)
{
 answ.push_back(make_pair(a,b));
 arp[a]=1;
 for (int i=0;i<g[a].size();i++)
 {
  long q=g[a][i];
  if (arp[q])continue;
  dfs(q,a);
 }
}

int main(){
//freopen("trade.in","r",stdin);
//freopen("trade.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m>>k>>w;
for (int lvl=1;lvl<=k;lvl++)
for (int i=1;i<=n;i++)
{
 cin>>st;
 for (int j=1;j<=m;j++) 
  ar[lvl][i][j]=st[j-1];
}

for (int i=1;i<=k;i++)
 d[0][i]=n*m;
 
for (int i=1;i<=k;i++)
 for (int j=1;j<=k;j++)
 {
  for (int a=1;a<=n;a++)
   for (int b=1;b<=m;b++)
    if (ar[i][a][b]!=ar[j][a][b])d[i][j]+=w;
 }

dist[0]=0;
for (int i=1;i<=k;i++)
dist[i]=1e9;

for (int iter=0;iter<=k;iter++)
{
 bst=1e9;
 bp=0;
 for (int i=0;i<=k;i++) 
  if (dist[i]<bst&&used[i]==0){bst=dist[i];bp=i;}
 used[bp]=1;
 if (bp>0)add_edge(bp,par[bp]);
 for (int i=0;i<=k;i++)
  if (d[bp][i]<dist[i]){dist[i]=d[bp][i];par[i]=bp;}
  ans+=bst;
}

cout<<ans<<endl;

dfs(0,-1);
for (int i=1;i<answ.size();i++)
 cout<<answ[i].first<<" "<<answ[i].second<<endl;
 
cin.get();cin.get();
return 0;}
/*
I'm so fed up with everyone around me
No one seems to care
I'm just so far gone and nothing's gonna change
I'll never be the same
It's always do this, do that, everything they want to
I don't wanna live that way
Every chance they get they're always pushing me away

It's never enough, no it's never enough
No matter what I say
It's never enough, no it's never enough
I'll never be what you want me to be

It's all so messed up and no one ever listens
Everyone's deranged
I'm just so messed up and I'm never gonna change
I wanna lay it all to waste
They're always say this, say that, nothing that you want to
I don't wanna live that way
Every chance they get they're always shoving me aside

It's never enough, no it's never enough
No matter what I say
It's never enough, no it's never enough
I'll never be what you want me to be
I'm done!

In the end we're all just chalk lines on the concrete
Drawn only to be washed away
For the time that I've been given
I am what I am

I'd rather hate you for everything you are
Than ever love you for something you are not
I'd rather you hate me for everything I am
Than have you love me for something that I can't

It's never enough, it's never enough
No matter what I say
It's never enough, no it's never enough
No matter who I try to be
It's never enough, no it's never enough
No matter how I try to taste
It's never enough, never never enough
I'll never be what you want me to be

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
#include <ctime> 
 
#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash
 
#define eps 1e-9
//#define M_PI 3.141592653589793
#define bs 1000000009
#define bsize 256
#define right adsgasgadsg
#define free adsgasdg
#define MAXN 100000
using namespace std;

long n,m,ar[10000],a[10000],b[10000];
bool good[200][200];
vector<pair<long, long> >v;
long cnt1;
pair<long, long> val[30000];


struct edge {
    int a, b, cap, flow;
};
 
//int n, s, t, d[MAXN], ptr[MAXN], q[MAXN];
long s,t,d[1<<20],ptr[1<<20],q[1<<20];

vector<edge> e;
vector<int> g[MAXN];
 
void add_edge (int a, int b, int cap) {
    edge e1 = { a, b, cap, 0 };
    edge e2 = { b, a, 0, 0 };
//  cout<<a<<"  "<<b<<" "<<cap<<endl;
    g[a].push_back ((int) e.size());
    e.push_back (e1);
    g[b].push_back ((int) e.size());
    e.push_back (e2);
}
 
bool bfs() {
    int qh=0, qt=0;
    q[qt++] = s;
    memset (d, -1, n * sizeof d[0]);
    d[s] = 0;
    while (qh < qt && d[t] == -1) {
        int v = q[qh++];
        for (size_t i=0; i<g[v].size(); ++i) {
            int id = g[v][i],
                to = e[id].b;
            if (d[to] == -1 && e[id].flow < e[id].cap) {
                q[qt++] = to;
                d[to] = d[v] + 1;
            }
        }
    }
    return d[t] != -1;
}
 
int dfs (int v, int flow) {
    if (!flow)  return 0;
    if (v == t)  return flow;
    for (; ptr[v]<(int)g[v].size(); ++ptr[v]) {
        int id = g[v][ptr[v]],
            to = e[id].b;
        if (d[to] != d[v] + 1)  continue;
        int pushed = dfs (to, min (flow, e[id].cap - e[id].flow));
        if (pushed) {
            e[id].flow += pushed;
            e[id^1].flow -= pushed;
            return pushed;
        }
    }
    return 0;
}
 
 long cnt;
 
int dinic() {
    int flow = 0;
    for (;;) {
        if (!bfs())  break;
        memset (ptr, 0, n * sizeof ptr[0]);
        while (int pushed = dfs (s, 1000000))
            flow += pushed;
    }
    return flow;
}

vector<pair<long, long> >fact(long x)
{
 vector<pair<long, long> > v;
 for (int i=2;i*i<=x;i++)
 {
  if (x%i)continue;
  long cnt=0;
  while (x%i==0)
   {cnt++;x/=i;}
   v.push_back(make_pair(i,cnt));
 }
 if (x>1)v.push_back(make_pair(x,1));
 return v;
}

int main(){
//freopen("capital.in","r",stdin);
//freopen("capital.out","w",stdout);
//freopen("C:/input.txt","r",stdin);
//freopen("C:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m;
for (int i=1;i<=n;i++)
{
 cin>>ar[i];
}
for (int i=1;i<=m;i++)
{
 cin>>a[i]>>b[i];
 if (a[i]%2==0)
  swap(a[i],b[i]);
  good[a[i]][b[i]]=1;
}

for (int i=1;i<=n;i+=2)
{
 v=fact(ar[i]);
 for (int j=0;j<v.size();j++)
 {
  ++cnt1;
  add_edge(0,cnt1,v[j].second);
  val[cnt1]=make_pair(i,v[j].first);
 }
}


for (int i=2;i<=n;i+=2)
{
 v=fact(ar[i]);
 for (int j=0;j<v.size();j++)
 {
  ++cnt1;
  add_edge(cnt1,10000,v[j].second);
  val[cnt1]=make_pair(i,v[j].first);
 }
}


for (int i=1;i<=cnt1;i++)
 for (int j=1;j<=cnt1;j++)
  if(good[val[i].first][val[j].first]==1&&val[i].second==val[j].second)
   add_edge(i,j,10000);
 

s=0;
t=10000;
n=t+1;
cout<<dinic()<<endl;


cin.get();cin.get();
return 0;}
/*
In a world of terror

Well, he's a man on a mission; he's sent from Allah
Longing for the glory in Shangri-La
Got God on his side; no one can take him away
He's glorious, he said

Viva the revolution
I know I will be born again
Long live mass confusion
I'm a martyr
Hidden in the London caves
Hidden in the London caves
In the caves of London

I'm a guy with a message, turn on the news
Children of the west; here's the Baghdad blues
There's a bomb in my bag;
Our justice is going to blow you away
I'm glorious, he said

Viva the revolution
I know I will be born again
Long live mass confusion
I'll be a legend, you'll have to face

Terror down under ground in the London caves
Hidden down under ground in the London caves
I will never be found in the London caves
Man of God

I'm a man on a mission, I'm blessed by Allah
Longing for the glory in Shangri-La
Got a bomb in my bag; my justice will blow you away
I'm glorious, I say

Viva the revolution
I know I will be born again
Long live mass confusion
London town under ground
Viva the revolution
I know I will be born again
Long live mass confusion
I'll have a place by the master's side

Terror down under ground in the London caves
Hidden down under ground in the London caves
I will never be found in the London caves
Never
I will never be found
I'm a guy with a message
Hidden in the London caves
*/
 
#pragma comment(linker, "/STACK:66777216")
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
#define bs 1000000007
#define bsize 256

using namespace std;

struct edge
{
    int a,b,cap,flow;
};

int s,t,N;
int d[1<<20],ptr[1<<20],q[1<<20];
vector<edge> e;
vector<int> g[1<<20];

void add_edge(int a,int b,int cap)
{
    edge e1={a,b,cap,0};
    edge e2={b,a,0,0};
    g[a].push_back(e.size());
    e.push_back(e1);
    g[b].push_back(e.size());
    e.push_back(e2);
}

bool bfs()
{
    int qt,qh;
    q[0]=s;
    qh=0;
    qt=1;
    for (int i=0;i<=N;i++)
     d[i]=-1;
    d[s]=0;
    while (qh<qt&&d[t]==-1)
    {
        int v=q[qh];
        ++qh;
        for (int i=0;i<g[v].size();i++)
        {
            int id=g[v][i];
            int to=e[id].b;
            if (d[to]==-1&&e[id].flow<e[id].cap)
            {
            q[qt]=to;
            ++qt;
            d[to]=d[v]+1;       
            }
        }   
    }
    return (d[t]!=-1);
}

int dfs(int v,int flow)
{
    if (v==t||flow==0) return flow;
    for (;ptr[v]<g[v].size();++ptr[v])
    {
        int id=g[v][ptr[v]];
        int to=e[id].b;
        if (d[to]!=d[v]+1)continue;
        int pushed =dfs(to,min(flow,e[id].cap-e[id].flow));
        if (pushed)
        {
            e[id].flow+=pushed;
            e[id^1].flow-=pushed;
            return pushed;
        }
    }
    return 0;
}

int dinic()
{
    int flow=0;
    while (true)
    {
        if (!bfs())break;
        for (int i=0;i<=N;i++)
         ptr[i]=0;
        while (true)
        {
            long pushed=dfs(s,10000);
            if (pushed==0)break;
            flow+=pushed;
        }
    }
    return flow;
}
int n,m,a[1<<20],b[1<<20],res;
int ans[1<<10][1<<10];

int main(){
//freopen("newlines.in","r",stdin);
//freopen("newlines.out","w",stdout);
//freopen("F:/input.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>m;
for (int i=1;i<=n;i++)
 cin>>a[i];
for (int i=1;i<=n;i++)
 cin>>b[i];

for (int i=1;i<=m;i++)
{
    int a,b;
    cin>>a>>b;
    add_edge(a,b+n,1000000);
    add_edge(b,a+n,1000000);
}

for (int i=1;i<=n;i++)
 add_edge(i,i+n,1000000);
 
int ss=0;
for (int i=1;i<=n;i++)
 ss+=b[i];

s=0;
t=n*2+1;
N=t+1;
for (int i=1;i<=n;i++)
 add_edge(s,i,a[i]);
for (int i=1;i<=n;i++)
 add_edge(i+n,t,b[i]);

int s2=0;
for (int i=1;i<=n;i++)
 s2+=a[i];
 
int res=dinic();
//cout<<res<<endl;

if (res!=ss||res!=s2)
 cout<<"NO"<<endl;
 else
 {
    for (int i=0;i<e.size();i++)
     if (e[i].a>=1&&e[i].a<=n&&e[i].b>n&&e[i].b<=2*n)
        ans[e[i].a][e[i].b-n]=e[i].flow;
    cout<<"YES"<<endl;
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=n;j++)
         cout<<ans[i][j]<<" ";
        cout<<endl;
    }
 }
 
//cin.get();cin.get();
return 0;}
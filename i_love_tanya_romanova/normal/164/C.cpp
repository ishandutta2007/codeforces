/*
Easily let's get carried away
Easily let's get married today
Shao Lin shouted a rose
From his throat
Everything must go
A lickin' stick is thicker
When you break it to show
Everything must go

The story of a woman on the morning of a war
Remind me if you will exactly what we're
fighting for

Calling calling for something in the air
Calling calling I know you must be there

Easily let's get caught in a wave
Easily we won't get caught in a cage
Shao Lin shakin' for the sake
Of his soul - Everything must go
Lookin' mighty tired of
All the things that you own
Everything must go

I can't tell you who to idolize
You think it's almost over
But it's only on the rise
Calling calling
For something in the air
Calling calling I know you must be there

The story of a woman on the morning of a war
Remind me if you will exactly what we're
fighting for

Throw me to the wolves because
Because there's order in the pack
Throw me to the sky
Because I know I'm coming back

Shao Lin shakin' for the sake
Of his soul - Everything must go
Lookin' mighty tired of
All the things that you own
Everything must go

The story of a woman on the morning of a war
Remind me if you will exactly what we're
fighting for

Calling calling for something in the air
Calling calling I know you must be there

I don't want to be your little research monkey
boy
The creature that I am is only going to destroy

Throw me to the wolves
Because there's order in the pack
Throw me to the sky
Because I know I'm coming back

Easily
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
#define M_PI 3.141592653589793
#define bs 1000000007
#define bsize 256

using namespace std;

struct rib
{
    int b,u,c,f;
    int back;
};

vector<rib> g[1<<20];

void add_edge(int a,int b,int u,int c)
{
//  cout<<"%"<<a<<" "<<b<<" "<<u<<" "<<c<<endl;
    
    rib r1={b,u,c,0,g[b].size()};
    rib r2={a,0,-c,0,g[a].size()};
    g[a].push_back(r1);
    g[b].push_back(r2);
}

int n,k,s[1<<20],t[1<<20],c[1<<20];
int N,S,T;
int ans[1<<20];

int main(){
//freopen("binomial.in","r",stdin);
//freopen("binomial.out","w",stdout);
//freopen("F:/in.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

cin>>n>>k;
for (int i=1;i<=n;i++)
{
    cin>>s[i]>>t[i]>>c[i];
}

add_edge(2*n+1,0,k,0);
for (int i=1;i<=n;i++)
{
    add_edge(0,i*2-1,k,0);
    add_edge(i*2,2*n+2,k,0);
}

for (int i=1;i<=n;i++)
    add_edge(2*i-1,2*i,1,-c[i]);

for (int i=1;i<=n;i++)
{
    vector<pair<int, int> > v;
    for (int j=1;j<=n;j++)
    {
        v.push_back(make_pair(s[j],j));
    }
    sort(v.begin(),v.end());
    for (int j=0;j<v.size();j++)
    {
        if (v[j].second==i)
        {
            if (j+1<v.size())
                add_edge(i*2-1,v[j+1].second*2-1,100,0);
        }
    }
    for (int j=0;j<v.size();j++)
        if (v[j].first>=s[i]+t[i])
        {
            add_edge(i*2,v[j].second*2-1,100,0);
            break;
        }
}

S=2*n+1;
T=2*n+2;
N=T+1;

int flow=0;
int cost=0;

while (flow<k)
{
    vector<int> id(N,0);
    vector<int> d(N,10000000);
    vector<int> q(N);
    vector<int> p(N);
    vector<int> p_rib(N);
    int qh,qt;
    q[0]=S;
    qh=0;qt=1;
    d[S]=0;
    while (qh!=qt)
    {
        int v=q[qh];
//      cout<<v<<"   "<<d[v]<<endl;
        
        ++qh;
        id[v]=2;
        if (qh==N)qh=0;
        for (int i=0;i<g[v].size();i++)
        {
            rib &r=g[v][i];
            if (r.f<r.u&&d[v]+r.c<d[r.b])
            {
                d[r.b]=d[v]+r.c;
                if (id[r.b]==0||id[r.b]==2)
                {
                    q[qt]=r.b;++qt;
                    if (qt==N)qt=0;
                }
                else if (id[r.b]==2)
                {
                    if (qh==0)  
                        qh=N-1;
                    else --qh;
                    q[qh]=r.b;
                }
                id[r.b]=1;
                p[r.b]=v;
                p_rib[r.b]=i;
            }
        }
    }
    if (d[T]>1e6)break;
    int addflow=k-flow;
    for (int v=T;v!=S;v=p[v])
    {
        int pv=p[v];
//      cout<<pv<<"%"<<endl;
        int pr=p_rib[v];
//      cout<<"%"<<pv<<" "<<pr<<endl;
        addflow=min(addflow,g[pv][pr].u-g[pv][pr].f);
    }
    for (int v=T;v!=S;v=p[v])
    {
        int pv=p[v];
        int pr=p_rib[v];
        int r=g[pv][pr].back;
//      cout<<v<<" "<<pv<<" * "<<addflow<<endl;
//      cout<<pv<<" @ "<<g[pv][pr].b<<" "<<g[pv][pr].f<<endl;
//      cout<<v<<" "<<g[v][r].b<<" "<<g[v][r].f<<"^"<<endl;
        g[pv][pr].f+=addflow;
        g[v][r].f-=addflow;
        cost+=g[pv][pr].c*addflow;
    }
    flow+=addflow;
}

for (int i=1;i<=n*2;i+=2)
{
    for (int j=0;j<g[i].size();j++)
    {
//      cout<<g[i][j].b<<" "<<g[i][j].f<<" "<<i<<endl;
        if (g[i][j].b==i+1&&g[i][j].f>0)
            ans[i/2+1]=1;
    }
}

for (int i=1;i<=n;i++)
{
    if (i>1)cout<<" ";
    cout<<ans[i];
}
cout<<endl;
//cout<<flow<<" "<<cost<<endl;
//cin.get();cin.get();
return 0;}
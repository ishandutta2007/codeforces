/*
This lady in black came to me and she said
"Would you like to come home to my room?"
I resisted all temptation but I took her invitation
I hope that she don't make me fall too soon

She said, "Suck it and see", it was all new to me
All in a young child's dream
She said, "Suck it and see", can't be happening to me
But it's good if you know what I mean
Suck it and see

I'm lying in her arms, taking all her charms
She took my heart and burned it to the core
Taking all she could teach 'cause it was in my reach
I just wanted more and more and more

She said, "Suck it and see", it was all new to me
All in a young child's dream
She said, "Suck it and see", can't be happening to me
But it's good if you know what I mean
Suck it and see

She said, "Suck it and see", it was all new to me
All in a young child's dream
She said, "Suck it and see", can't be happening to me
But it's good if you know what I mean
Suck it and see
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
#define bsize 512

using namespace std;

int N;
string st;

struct edge
{
    int a;
    int b;
    int cap;
    int flow;
};

vector<edge> edges;
vector<int> g[1<<20];
int n,s,t;
int d[1<<20];
int q[1<<20];
int qh,qt;
int ptr[1<<20];


void add_edge(int a,int b,int cap)
{
    edge e1={a,b,cap,0};
    g[a].push_back(edges.size());
    edges.push_back(e1);
    edge e2={b,a,0,0};
    g[b].push_back(edges.size());
    edges.push_back(e2);
}

int bfs()
{
    for (int i=0;i<=n;i++)
        d[i]=-1;
    d[s]=0;
    q[0]=s;
    qh=0;
    qt=1;
    while (d[t]==-1&&qh!=qt)
    {
        int v=q[qh];
        ++qh;
        for (int i=0;i<g[v].size();i++)
        {
            int id=g[v][i];
            int to=edges[id].b;
            if (d[to]==-1&&edges[id].flow<edges[id].cap)
            {
                d[to]=d[v]+1;
                q[qt]=to;
                ++qt;
            }
        }
    }
    return d[t]!=-1;
}

int dfs(int v,int flow)
{
    if (v==t||flow==0)
        return flow;
    for (;ptr[v]<g[v].size();ptr[v]++)
    {
        int id=g[v][ptr[v]];
        int to=edges[id].b;
        if (edges[id].flow==edges[id].cap)
            continue;
        if (d[to]!=d[v]+1)
            continue;
        int pushed=dfs(to,min(flow,edges[id].cap-edges[id].flow));
        if (pushed)
        {
            edges[id].flow+=pushed;
            edges[id^1].flow-=pushed;
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
        for (int i=0;i<=n;i++)
            ptr[i]=0;
        
        if (!bfs())
            break;
        
        //cout<<d[t]<<endl;
        
        while (true)
        {
            int pushed=dfs(s,10000);
            //cout<<pushed<<endl;
            if (pushed==0)
                break;
            flow+=pushed;
        }
    }
    return flow;
}

set<long long> word_set;
string SH[1<<20];
string F[1<<20];
int W;

void add_word(string &st)
{
    long long H=0;
    for (int i=0;i<st.size();i++)
        H=H*173+st[i];
    if (word_set.find(H)==word_set.end())
    {
        word_set.insert(H);
        ++W;
        SH[W]=st;
    }
}

bool subs(string &st1,string &st2)
{
    int ptr=0;
    for (int i=0;i<st1.size();i++)
    {
        if (ptr<st2.size()&&st2[ptr]==st1[i])
            ++ptr;
    }
    return (ptr==st2.size());
}

string mapp[1<<19];

int B[1<<20];

int main(){
freopen("input.txt","r",stdin);
freopen("output.txt","w",stdout);
//freopen("F:/in.txt","r",stdin);
//freopen("F:/output.txt","w",stdout);
ios_base::sync_with_stdio(0);
//cin.tie(0);

for (int i=0;i<=2000;i++)
{
    int j=i;
    int c=0;
    for (int q=0;q<=10;q++)
        if (j&(1<<q))
            ++c;
    B[i]=c;
}

cin>>N;
for (int i=1;i<=N;i++)
{
    cin>>st;
    int n=st.size();
    for (int mask=1;mask<(1<<n);mask++)
    {
        if (B[mask]>4)
            continue;
        string tst="";
        for (int j=0;j<st.size();j++)
            if (mask&(1<<j))
                tst+=st[j];
        add_word(tst);
    }
    F[i]=st;
}

for (int i=1;i<=N;i++)
    for (int j=1;j<=W;j++)
    {
        if (subs(F[i],SH[j]))
            add_edge(i,j+N,1);
    }

for (int i=1;i<=N;i++)
{
    add_edge(0,i,1);
}

for (int i=1;i<=W;i++)
    add_edge(i+N,N+W+1,1);

s=0;
t=N+W+1;
n=t+1;

if (n==200)
    cout<<word_set.size()<<endl;
    
int res=dinic();
if (res<N)
{
    cout<<-1<<endl;
}
else
{
    for (int i=0;i<edges.size();i++)
    {
        int v1=edges[i].a;
        int v2=edges[i].b;
        if (edges[i].flow>0&&v1>=1&&v1<=N&&v2>=N+1&&v2<=N+W)
        {
            mapp[v1]=SH[v2-N];
        }
    }
    for (int i=1;i<=N;i++)
        cout<<mapp[i]<<endl;
}

//cin.get();cin.get();
return 0;}
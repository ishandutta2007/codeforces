#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cmath>
#include <string>
#include <map>
#include <stack>
#include <vector>
#include <set>
#include <queue>
#pragma comment (linker,"/STACK:102400000,102400000")
#define pi acos(-1.0)
#define eps 1e-6
#define lson rt<<1,l,mid
#define rson rt<<1|1,mid+1,r
#define FRE(i,a,b)  for(i = a; i <= b; i++)
#define FREE(i,a,b) for(i = a; i >= b; i--)
#define FRL(i,a,b)  for(i = a; i < b; i++)
#define FRLL(i,a,b) for(i = a; i > b; i--)
#define mem(t, v)   memset ((t) , v, sizeof(t))
#define sf(n)       scanf("%d", &n)
#define sff(a,b)    scanf("%d %d", &a, &b)
#define sfff(a,b,c) scanf("%d %d %d", &a, &b, &c)
#define pf          printf
#define DBG         pf("Hi\n")
typedef __int64 ll;
using namespace std;

#define INF 0x3f3f3f3f
#define mod 1000000009
const int maxn = 1005;
const int MAXN = 100011;
const int MAXM = 250010;
const int N = 1005;

int n,m,s,t;

struct Edge
{
    int u,v,next,id;
    ll len;
}e1[MAXM],e2[MAXM];

int head1[MAXN],head2[MAXN];

typedef pair<ll,int>P;
ll dist1[MAXN],dist2[MAXN];
int num,tot,start,End;
bool cut[MAXN];

int Low[MAXN],DFN[MAXN],Stack[MAXN];
bool Instack[MAXN];
int Index,top;

void init()
{
    num=0;  tot=0;
    mem(head1,-1);
    memset(head2,-1,sizeof(head2));
}

void addedge(int u,int v,ll w,int id)
{
    e1[num].u=u;
    e1[num].v=v;
    e1[num].len=w;
    e1[num].id=id;
    e1[num].next=head1[u];
    head1[u]=num++;
}

void addedge2(int u,int v,ll w,int id)
{
    e2[tot].u=u;
    e2[tot].v=v;
    e2[tot].len=w;
    e2[tot].id=id;
    e2[tot].next=head2[u];
    head2[u]=tot++;
}

void Dijkstra(int s,int t,int head[],ll dist[],Edge edge[])
{
    priority_queue<P,vector<P>,greater<P> >Q;
    dist[s]=0;
    Q.push(make_pair(0,s));
    while (!Q.empty())
    {
        P p=Q.top(); Q.pop();
        int u=p.second;
        if (dist[u]<p.first) continue;
        for (int i=head[u];~i;i=edge[i].next)
        {
            int v=edge[i].v;
            if (dist[v]>dist[u]+edge[i].len)
            {
                dist[v]=dist[u]+edge[i].len;
                Q.push(make_pair(dist[v],v));
            }
        }
    }
}

void Tarjan(int u,int pre)
{
    int v;
    Low[u]=DFN[u]=++Index;
    Stack[top++]=u;
    Instack[u]=true;
    int pre_cnt=0;
    for (int i=head2[u];~i;i=e2[i].next)
    {
        v=e2[i].v;
        if (v==pre&&pre_cnt==0) { pre_cnt++;continue; }
        if (!DFN[v])
        {
            Tarjan(v,u);
            if (Low[u]>Low[v]) Low[u]=Low[v];
            if (Low[v]>DFN[u])
                cut[e2[i].id]=true;
        }
        else if (Low[u]>DFN[v])
            Low[u]=DFN[v];
    }
    Instack[u]=false;
    top--;
}

void solve()
{
    memset(DFN,0,sizeof(DFN));
    memset(Instack,false,sizeof(Instack));
    Index=top=0;
    for (int i=1;i<=n;i++)
        if (!DFN[i])
        Tarjan(i,i);
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("C:/Users/lyf/Desktop/IN.txt","r",stdin);
#endif
    int i,j,u,v;
    ll w;
    while (~scanf("%d%d%d%d",&n,&m,&s,&t))
    {
        init();
        for (i=0;i<m;i++)
        {
            scanf("%d%d%I64d",&u,&v,&w);
            addedge(u,v,w,i);
            addedge2(v,u,w,i);
        }
        mem(dist1,INF);
        mem(dist2,INF);
        Dijkstra(s,t,head1,dist1,e1);
        Dijkstra(t,s,head2,dist2,e2);
        tot=0;
        memset(head2,-1,sizeof(head2));
        for (i=0;i<m;i++)
        {
            cut[i]=false;
            u=e1[i].u;
            v=e1[i].v;
            if (dist1[u]+dist2[v]+e1[i].len==dist1[t])
            {
                addedge2(u,v,e1[i].len,i);
                addedge2(v,u,e1[i].len,i);
            }
        }
        solve();
        for (i=0;i<m;i++)
        {
            u=e1[i].u;
            v=e1[i].v;
            if (cut[i]) printf("YES\n");
            else if (dist1[u]+dist2[v]+e1[i].len==dist1[t])
            {
                if (e1[i].len>1)
                    printf("CAN 1\n");
                else
                    printf("NO\n");
            }
            else
            {
                ll dd=dist1[t]-dist1[u]-dist2[v]-1;
                if (dd<=0)
                    printf("NO\n");
                else
                    printf("CAN %I64d\n",e1[i].len-dd);
            }
        }
    }
    return 0;
}
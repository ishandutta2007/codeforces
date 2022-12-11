#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define REP(i,a,b) for(int i=(a),_end_=(b);i<=_end_;i++)
#define DREP(i,a,b) for(int i=(a),_end_=(b);i>=_end_;i--)
#define EREP(i,a) for(int i=start[(a)];i;i=e[i].next)
template<class T>inline void chkmax(T &a,T b){ if(a<b)a=b;}
template<class T>inline void chkmin(T &a,T b){ if(a>b)a=b;}
#define fi first
#define se second
#define mkr(a,b) make_pair(a,b)
#define SZ(A) ((int)A.size())
inline int read()
{
    int sum=0,p=1;char ch=getchar();
    while(!(('0'<=ch && ch<='9') || ch=='-'))ch=getchar();
    if(ch=='-')p=-1,ch=getchar();
    while('0'<=ch && ch<='9')sum=sum*10+ch-48,ch=getchar();
    return sum*p;
}

const int maxn=1e4+20;

const int inf=0x3f3f3f3f;

struct Edge {
    int u,v;
};
Edge E[maxn];

struct node {
    int v,next,w;
};
node e[maxn];
int cnt,start[maxn];
inline void addedge(int u,int v,int w){ e[++cnt]=(node){v,start[u],w};start[u]=cnt;}

int n,m;

vector<int>ed[maxn];
int vis[maxn];

inline void bfs()
{
    static int f[maxn],g[maxn];
    queue<int>q;
    f[1]=1; q.push(1);
    while(!q.empty())
    {
	int u=q.front();q.pop();
	for(int v:ed[u])if(u<v && !f[v])f[v]=1,q.push(v);
    }
    g[n]=1; q.push(n);
    while(!q.empty())
    {
	int u=q.front();q.pop();
	for(int v:ed[u])if(v<u && !g[v])g[v]=1,q.push(v);
    }
    REP(i,1,n)if(f[i] && g[i])vis[i]=1;
}

inline void init()
{
    n=read();m=read();
    REP(i,1,m)
    {
	int u=read(),v=read();
	E[i]=(Edge){u,v};
	ed[u].push_back(v);
	ed[v].push_back(u);
    }
    bfs();
    REP(i,1,m)
    {
	int u=E[i].u,v=E[i].v;
	if(vis[u] && vis[v])addedge(v,u,-1),addedge(u,v,2);
    }
}

int dist[maxn],dis[maxn],inq[maxn];

inline void doing()
{
    queue<int>q; q.push(1); inq[1]=1; memset(dist,inf,sizeof(dist)); dist[1]=0;
    while(!q.empty())
    {
	int u=q.front();q.pop();inq[u]=0;
	if(dis[u]>n)puts("No"),exit(0);
	EREP(i,u)
	{
	    int v=e[i].v;
	    if(dist[v]>dist[u]+e[i].w)
	    {
		dist[v]=dist[u]+e[i].w; dis[v]=dis[u]+1;
		if(!inq[v])q.push(v),inq[v]=1;
	    }
	}
    }
    puts("Yes");
    REP(i,1,m)
    {
	int u=E[i].u,v=E[i].v;
	if(vis[u] && vis[v])printf("%d\n",dist[v]-dist[u]);
	else puts("1");
    }
}

int main()
{
#ifndef ONLINE_JUDGE
    freopen("flights.in","r",stdin);
    freopen("flights.out","w",stdout);
#endif
    init();
    doing();
    return 0;
}
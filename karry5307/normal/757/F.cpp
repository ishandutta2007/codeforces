#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll MAXN=3e5+51;
struct Edge{
	ll to,prev,dist;
};
struct Tuple{
	ll x,y;
	inline bool operator <(const Tuple &rhs)const
	{
		return this->x>rhs.x;
	}
};
struct Graph{
	Edge ed[MAXN<<1];
	ll tot;
	ll last[MAXN];
	Graph()
	{
		tot=0,memset(last,0,sizeof(last));
	}
	inline void addEdge(ll from,ll to,ll dist=0)
	{
		ed[++tot].prev=last[from];
		ed[tot].to=to;
		ed[tot].dist=dist;
		last[from]=tot;
	}
};
Graph g0,g,t;
priority_queue<Tuple>q;
ll n,m,source,res;
ll from[MAXN],to[MAXN],dis[MAXN],dist[MAXN],inQueue[MAXN];
inline ll read()
{
    register ll num=0,neg=1;
    register char ch=getchar();
    while(!isdigit(ch)&&ch!='-')
    {
        ch=getchar();
    }
    if(ch=='-')
    {
        neg=-1;
        ch=getchar();
    }
    while(isdigit(ch))
    {
        num=(num<<3)+(num<<1)+(ch-'0');
        ch=getchar();
    }
    return num*neg;
}
inline void Dijkstra(ll source)
{
	ll top;
	Edge *ed=g0.ed;
	ll *last=g0.last;
	memset(dist,0x3f,sizeof(dist)),dist[source]=0,inQueue[source]=1;
	q.push((Tuple){0,source});
	while(!q.empty())
	{
		top=q.top().y,q.pop(),inQueue[top]=0;
		for(register int i=last[top];i;i=ed[i].prev)
		{
			if(dist[ed[i].to]>dist[top]+ed[i].dist)
			{
				dist[ed[i].to]=dist[top]+ed[i].dist;
				if(!inQueue[ed[i].to])
				{
					q.push((Tuple){dist[ed[i].to],ed[i].to});
					inQueue[ed[i].to]=1;
				}
			}
		}
	}
}
namespace DominationTree{
	ll deg[MAXN],fa[MAXN],depth[MAXN],anc[MAXN][18],sz[MAXN];
	inline ll LCA(ll x,ll y)
	{
		if(depth[x]<depth[y])
		{
			swap(x,y);
		}
		for(register int i=17;i>=0;i--)
		{
			if(depth[anc[x][i]]>=depth[y])
			{
				x=anc[x][i];
			}
		}
		if(x==y)
		{
			return x;
		}
		for(register int i=17;i>=0;i--)
		{
			if(anc[x][i]!=anc[y][i])
			{
				x=anc[x][i],y=anc[y][i];
			}
		}
		return anc[x][0];
	}
	inline void dfs(ll node)
	{
		sz[node]=dist[node]!=dist[0];
		for(register int i=t.last[node];i;i=t.ed[i].prev)
		{
			dfs(t.ed[i].to),sz[node]+=sz[t.ed[i].to];
		}
	}
	inline void create()
	{
		queue<ll>q;
		ll top,to;
		memset(fa,-1,sizeof(fa));
		for(register int i=1;i<=n;i++)
		{
			if(!deg[i])
			{
				fa[i]=0,q.push(i);
			}
		}
		while(!q.empty())
		{
			top=q.front(),q.pop(),depth[top]=depth[fa[top]]+1;
			t.addEdge(fa[top],top),anc[top][0]=fa[top];
			for(register int i=1;i<18;i++)
			{
				anc[top][i]=anc[anc[top][i-1]][i-1];
			}
			for(register int i=g.last[top];i;i=g.ed[i].prev)
			{
				to=g.ed[i].to,fa[to]=fa[to]==-1?top:LCA(fa[to],top);
				if(!--deg[to])
				{
					q.push(to);
				}
			}
		}
	}
} 
using DominationTree::create;
using DominationTree::dfs;
using DominationTree::deg;
using DominationTree::sz;
int main()
{
	n=read(),m=read(),source=read();
	for(register int i=0;i<m;i++)
	{
		from[i]=read(),to[i]=read(),dis[i]=read();
		g0.addEdge(from[i],to[i],dis[i]);
		g0.addEdge(to[i],from[i],dis[i]);
	}
	Dijkstra(source);
	for(register int i=0;i<m;i++)
	{
		if(dist[from[i]]+dis[i]==dist[to[i]])
		{
			g.addEdge(from[i],to[i]),deg[to[i]]++;
		}
		if(dist[to[i]]+dis[i]==dist[from[i]])
		{
			g.addEdge(to[i],from[i]),deg[from[i]]++;
		}
	}
	create(),dfs(0);
	for(register int i=1;i<=n;i++)
	{
		if(i!=source)
		{
			res=max(res,sz[i]);
		}
	}
	printf("%d\n",res);
}
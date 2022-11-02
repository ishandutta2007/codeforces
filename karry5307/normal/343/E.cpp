#include<bits/stdc++.h>
using namespace std;
typedef int ll;
const ll MAXN=251,MAXE=1e3+51,inf=0x7fffffff;
struct Edge{
	ll to,prev,flow;
};
Edge ed[MAXE<<2];
ll nc,ec,source,sink,tot=1,from,to,flow,maxFlow,rres,p,q,id,wt,ptr;
ll last[MAXN],depth[MAXN],inQueue[MAXN],curr[MAXN],res[MAXN],vis[MAXN<<1];
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
inline void addEdge(ll from,ll to,ll flow)
{
	ed[++tot].prev=last[from];
	ed[tot].to=to;
	ed[tot].flow=flow;
	last[from]=tot; 
}
inline ll Min(ll x,ll y)
{
	return x<y?x:y;
}
inline bool bfs()
{
	queue<ll>q;
	ll top,to;
	memset(depth,0x3f,sizeof(depth));
	for(register int i=1;i<=nc;i++)
	{
		curr[i]=last[i];
	}
	depth[source]=0,q.push(source);
	while(!q.empty())
	{
		top=q.front();
		q.pop(),inQueue[top]=0;
		for(register int i=last[top];i;i=ed[i].prev)
		{
			to=ed[i].to;
			if(depth[to]>depth[top]+1&&ed[i].flow)
			{
				depth[to]=depth[top]+1;
				if(!inQueue[to])
				{
					q.push(to),inQueue[to]=1;
				}
			}
		}
	}
	if(depth[sink]!=0x3f3f3f3f)
	{
		return 1;	
	} 
	return 0;
}
inline ll dfs(ll cur,ll flow)
{
	ll curFlow=0,low;
	if(cur==sink)
	{
		return flow;
	}
	for(register int i=curr[cur];i;i=ed[i].prev)
	{
		curr[cur]=i;
		if(ed[i].flow&&depth[ed[i].to]==depth[cur]+1)
		{
			low=dfs(ed[i].to,Min(flow-curFlow,ed[i].flow));
			ed[i].flow-=low,ed[i^1].flow+=low,curFlow+=low;
			if(!low)
			{
				depth[ed[i].to]=0;
			}
			if(curFlow==flow)
			{
				break;
			}
		}
	}
	return curFlow;
}
inline ll Dinic()
{
	ll flow;
	while(bfs())
	{
		while(flow=dfs(source,inf))
		{
			maxFlow+=flow;
		}
	}
	return maxFlow;
}
inline void clearFlow()
{
	maxFlow=0;
	for(register int i=2;i<=tot;i+=2)
	{
		ed[i].flow+=ed[i^1].flow,ed[i^1].flow=0;
	}
}
namespace GomoryHuTree{
	struct Edge{
		ll to,prev,dist;
	};
	Edge ed[MAXN<<1];
	ll tot;
	ll last[MAXN],nd[MAXN],tmp[MAXN],tmp2[MAXN];
	inline void addEdge(ll from,ll to,ll dist)
	{
		ed[++tot].prev=last[from];
		ed[tot].to=to;
		ed[tot].dist=dist;
		last[from]=tot; 
	}
	inline void setup()
	{
		for(register int i=1;i<=nc;i++)
		{
			nd[i]=i;
		}
	}
	inline void create(ll l,ll r)
	{
		ll cut,cnt,ccnt;
		if(l==r)
		{
			return;
		}
		source=nd[l],sink=nd[l+1],cut=Dinic(),clearFlow();
		addEdge(source,sink,cut),addEdge(sink,source,cut),cnt=ccnt=0;
		for(register int i=l;i<=r;i++)
		{
			::depth[nd[i]]!=0x3f3f3f3f?tmp[++cnt]=nd[i]:tmp2[++ccnt]=nd[i];
		}
		for(register int i=l;i<l+cnt;i++)
		{
			nd[i]=tmp[i-l+1];
		}
		for(register int i=l+cnt;i<=r;i++)
		{
			nd[i]=tmp2[i-cnt-l+1];
		}
		create(l,l+cnt-1),create(l+cnt,r);
	}
	inline ll dfs(ll node,ll fa)
	{
		ll son=0;
		for(register int i=last[node];i;i=ed[i].prev)
		{
			if(ed[i].to!=fa&&!vis[i])
			{
                if(ed[i].dist<wt)
				{
					p=node,q=ed[i].to,id=i,wt=ed[i].dist;
				}
				dfs(ed[i].to,node),son=1;
			}
		}
		return son;
	}
}
using GomoryHuTree::setup;
using GomoryHuTree::create;
inline void ddfs(ll node)
{
	ll x,y;
	wt=0x3f3f3f3f;
	if(!GomoryHuTree::dfs(node,0))
	{
		res[++ptr]=node;
		return;
	}
	vis[id]=vis[((id-1)^1)+1]=1,rres+=wt,x=p,y=q;
	ddfs(x),ddfs(y);
}
int main()
{
	nc=read(),ec=read(),setup();
	for(register int i=0;i<ec;i++)
	{
		from=read(),to=read(),flow=read();
		addEdge(from,to,flow),addEdge(to,from,0);
		addEdge(to,from,flow),addEdge(from,to,0);
	}
	create(1,nc),ddfs(1),printf("%d\n",rres);
	for(register int i=1;i<=ptr;i++)
	{
		printf("%d ",res[i]);
	}
}
#include<bits/stdc++.h>
using namespace std;
typedef int ll;
const ll MAXN=4e5+51,inf=0x7fffffff;
struct Edge{
	ll to,prev,flow;
};
Edge ed[MAXN<<1];
ll nc,ec,cnt,kk,source,sink,tot=1,maxFlow,l,r,mid,res=-1,f,t;
ll last[MAXN],depth[MAXN],inQueue[MAXN];
ll pos[MAXN],curr[MAXN],dis[651][651];
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
template <class T>
inline T Min(T x,T y)
{
	return x<y?x:y;
}
template <class T>
inline T Max(T x,T y)
{
	return x>y?x:y;
}
inline bool bfs()
{
	queue<ll>q;
	ll top,to;
	for(register int i=0;i<=sink;i++)
	{
		depth[i]=0x3f3f3f3f,curr[i]=last[i];
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
	ll low;
	if(cur==sink)
	{
		return flow;
	}
	for(register int i=curr[cur];i;i=ed[i].prev)
	{
		curr[cur]=i;
		if(ed[i].flow&&depth[ed[i].to]==depth[cur]+1)
		{
			if(low=dfs(ed[i].to,Min(flow,ed[i].flow)))
			{
				ed[i].flow-=low,ed[i^1].flow+=low;
				return low;
			}
		}
	}
	return 0;
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
inline void createGraph(ll x)
{
	memset(last,0,sizeof(last)),memset(curr,0,sizeof(curr));
	source=maxFlow=0,sink=cnt+nc+1,tot=1;
	for(register int i=0;i<cnt;i++)
	{
		for(register int j=1;j<=nc;j++)
		{
			if(dis[pos[i]][j]<=x)
			{
				addEdge(i+1,cnt+j,1),addEdge(cnt+j,i+1,0);
			}
		}
	}
	for(register int i=0;i<cnt;i++)
	{
		addEdge(source,i+1,1),addEdge(i+1,source,0);
	}
	for(register int i=1;i<=nc;i++)
	{
		addEdge(cnt+i,sink,1),addEdge(sink,cnt+i,0);
	}
}
inline bool check(ll x)
{
	createGraph(x);
	return Dinic()>=kk;
}
int main()
{
	nc=read(),ec=read(),cnt=read(),kk=read();
	for(register int i=0;i<cnt;i++)
	{
		pos[i]=read();
	}
	memset(dis,0x3f,sizeof(dis)),l=0,r=1731311;
	for(register int i=0;i<ec;i++)
	{
		f=read(),t=read(),dis[f][t]=dis[t][f]=Min(dis[f][t],read());
	}
	for(register int i=1;i<=nc;i++)
	{
		dis[i][i]=0;
	}
	for(register int k=1;k<=nc;k++)
	{
		for(register int i=1;i<=nc;i++)
		{
			for(register int j=1;j<=nc;j++)
			{
				dis[i][j]=Min(dis[i][j],dis[i][k]+dis[k][j]);
			}
		}
	}
	while(l<=r)
	{
		mid=(l+r)>>1,check(mid)?r=mid-1,res=mid:l=mid+1;
	}
	printf("%d\n",res);
}
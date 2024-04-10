#include<bits/stdc++.h>
using namespace std;
typedef int ll;
const ll MAXN=2e5+51,inf=0x7fffffff;
struct Edge{
    ll to,prev,flow;
};
Edge ed[MAXN<<1];
ll nc,cnt,ccnt,c,source,sink,tot=1,from,to,flow,maxFlow,op,kk,x,y,res;
ll last[MAXN],depth[MAXN],inQueue[MAXN],curr[MAXN],num[MAXN];
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
int main()
{
	cnt=read(),ccnt=read(),c=read(),source=1,nc=sink=cnt+ccnt+2;
	for(register int i=1;i<=cnt;i++)
	{
		num[i]=read();
	}
	for(register int i=1;i<=cnt;i++)
	{
		x=read();
		if(num[i])
		{
			addEdge(i+1,sink,x),addEdge(sink,i,0);
		}
		else
		{
			addEdge(source,i+1,x),addEdge(i+1,source,0);
		}
	}
	for(register int i=2;i<ccnt+2;i++)
	{
		op=read(),res+=(x=read()),kk=read();
		if(op)
		{
			for(register int j=1;j<=kk;j++)
			{
				addEdge((y=read()+1),cnt+i,0x3f3f3f3f),addEdge(cnt+i,y,0);
			}
			addEdge(cnt+i,sink,x+(read()?c:0)),addEdge(sink,cnt+i,0);
		}
		else
		{
			for(register int j=1;j<=kk;j++)
			{
				addEdge(cnt+i,(y=read()+1),0x3f3f3f3f),addEdge(y,cnt+i,0);
			}
			addEdge(source,cnt+i,x+(read()?c:0)),addEdge(cnt+i,source,0);
		}
	}
	printf("%d\n",res-Dinic());
}
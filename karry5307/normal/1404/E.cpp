#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51,inf=0x3f3f3f3f;
struct Edge{
	ll to,prev,flow;
};
Edge ed[MAXN*3];
ll n,m,source,sink,tot=1,totd,maxFlow,sm;
char ch[251][251];
ll last[MAXN],depth[MAXN],inQueue[MAXN],r[251][251][4];
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
	ed[++tot]=(Edge){to,last[from],flow},last[from]=tot;
}
inline ll bfs()
{
	queue<ll>q;
	ll top,to;
	memset(depth,0x3f,sizeof(depth)),depth[source]=0,q.push(source);
	while(!q.empty())
	{
		top=q.front(),q.pop(),inQueue[top]=0;
		for(register int i=last[top];i;i=ed[i].prev)
		{
			if(depth[to=ed[i].to]>depth[top]+1&&ed[i].flow)
			{
				depth[to]=depth[top]+1,!inQueue[to]?q.push(to),inQueue[to]=1:1;
			}
		}
	}
	return depth[sink]!=inf;
}
inline ll dfs(ll cur,ll flow)
{
	ll c=0,low,to;
	if(cur==sink)
	{
		return flow;
	}
	for(register int i=last[cur];i;i=ed[i].prev)
	{
		if(depth[to=ed[i].to]==depth[cur]+1&&ed[i].flow)
		{
			low=dfs(to,min(flow-c,ed[i].flow));
			ed[i].flow-=low,ed[i^1].flow+=low,c+=low,!low?depth[to]=0:1;
			if(flow==c)
			{
				break;
			}
		}
	}
	return c;
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
	n=read(),m=read(),sink=totd=1;
	for(register int i=1;i<=n;i++)
	{
		scanf("%s",ch[i]+1);
		for(register int j=1;j<=m;j++)
		{
			sm+=ch[i][j]=='#';
		}
	}
	for(register int i=1;i<=n;i++)
	{
		for(register int j=1;j<m;j++)
		{
			if(ch[i][j]=='#'&&ch[i][j+1]=='#')
			{
				r[i][j][1]=r[i][j+1][0]=++totd;
				addEdge(0,totd,1),addEdge(totd,0,0);
			}
		}
	}
	for(register int i=1;i<n;i++)
	{
		for(register int j=1;j<=m;j++)
		{
			if(ch[i][j]=='#'&&ch[i+1][j]=='#')
			{
				r[i][j][3]=r[i+1][j][2]=++totd;
				addEdge(totd,1,1),addEdge(1,totd,0);
			}
		}
	}
	for(register int i=1;i<=n;i++)
	{
		for(register int j=1;j<=m;j++)
		{
			for(register int k=0;k<=1;k++)
			{
				for(register int l=2;l<=3;l++)
				{
					if(r[i][j][k]&&r[i][j][l])
					{
						addEdge(r[i][j][k],r[i][j][l],1);
						addEdge(r[i][j][l],r[i][j][k],0);
					}
				}
			}
		}
	}
	printf("%d\n",sm-totd+Dinic()+1);
}
#include<bits/stdc++.h>
#pragma GCC optimize("Ofast,unroll-loops")
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=1e3+51;
struct Edge{
	ll to,prev;
};
Edge ed[MAXN<<8];
ll n,m,u,v,tot,totc,res;
ll last[MAXN],col[MAXN],bel[MAXN],dist[MAXN],vis[MAXN],r[MAXN];
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
inline void addEdge(ll from,ll to)
{
	ed[++tot].prev=last[from];
	ed[tot].to=to;
	last[from]=tot;
}
inline void dfs(ll x,ll c)
{
	col[x]=c,bel[x]=totc;
	for(register int i=last[x];i;i=ed[i].prev)
	{
		if(col[ed[i].to])
		{
			col[ed[i].to]==col[x]?puts("-1"),exit(0):(void)1;
			continue;
		}
		dfs(ed[i].to,-c);
	}
}
inline ll bfs(ll source)
{
	ll top,mx=0;
	queue<ll>q;
	dist[source]=0,vis[source]=1,q.push(source);
	while(!q.empty())
	{
		top=q.front(),q.pop();
		for(register int i=last[top];i;i=ed[i].prev)
		{
			if(!vis[ed[i].to])
			{
				dist[ed[i].to]=dist[top]+1,vis[ed[i].to]=1;
				mx=max(mx,dist[ed[i].to]),q.push(ed[i].to);
			}
		}
	}
	return mx;
}
int main()
{
	n=read(),m=read();
	for(register int i=1;i<=m;i++)
	{
		u=read(),v=read(),addEdge(u,v),addEdge(v,u);
	}
	for(register int i=1;i<=n;i++)
	{
		!col[i]?++totc,dfs(i,1):(void)1;
	}
	for(register int i=1;i<=n;i++)
	{
		memset(vis,0,sizeof(vis)),r[bel[i]]=max(r[bel[i]],bfs(i));
	}
	for(register int i=1;i<=totc;i++)
	{
		res+=r[i];
	}
	printf("%d\n",res);
}
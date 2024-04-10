#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e6+51;
struct Edge{
	ll to,prev,dist;
};
Edge ed[MAXN<<1];
ll nc,tot,dfn,x;
char ch;
ll last[MAXN],fa[MAXN],size[MAXN],heavy[MAXN],l[MAXN],r[MAXN];
ll id[MAXN],depth[MAXN],res[MAXN],vis[MAXN],barrel[(1<<23)+51],dist[MAXN];
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
template <class T>
inline T Max(T x,T y)
{
	return x>y?x:y;	
} 
inline void addEdge(ll from,ll to,ll dist)
{
	ed[++tot].prev=last[from];
	ed[tot].to=to;
	ed[tot].dist=dist;
	last[from]=tot;
}
inline void dfs(ll node,ll f)
{
	depth[node]=depth[fa[node]=f]+1,size[node]=1,l[node]=++dfn,id[dfn]=node;
	ll maxn=-1;
	for(register int i=last[node];i;i=ed[i].prev)
	{
		if(ed[i].to!=f)
		{
			dist[ed[i].to]=dist[node]^ed[i].dist;
			dfs(ed[i].to,node),size[node]+=size[ed[i].to];
			if(size[ed[i].to]>maxn)
			{
				maxn=size[heavy[node]=ed[i].to];
			}
		}
	}
	r[node]=dfn;
}
inline void ddfs(ll node,ll state)
{
	for(register int i=last[node];i;i=ed[i].prev)
	{
		if(ed[i].to!=fa[node]&&ed[i].to!=heavy[node])
		{
			ddfs(ed[i].to,0),res[node]=Max(res[node],res[ed[i].to]);
		}
	}
	if(heavy[node])
	{
		ddfs(heavy[node],1),res[node]=Max(res[node],res[heavy[node]]);
	}
	if(barrel[dist[node]])
	{
		res[node]=Max(res[node],barrel[dist[node]]-depth[node]);
	}
	for(register int i=0;i<22;i++)
	{
		if(barrel[dist[node]^(1<<i)])
		{
			res[node]=Max(res[node],barrel[dist[node]^(1<<i)]-depth[node]);
		}
	}
	barrel[dist[node]]=Max(depth[node],barrel[dist[node]]);
	for(register int i=last[node];i;i=ed[i].prev)
	{
		if(ed[i].to!=fa[node]&&ed[i].to!=heavy[node])
		{
			for(register int j=l[ed[i].to];j<=r[ed[i].to];j++)
			{
				ll x=id[j],kk=depth[x]-(depth[node]<<1);
				if(barrel[dist[x]])
				{
					res[node]=Max(res[node],barrel[dist[x]]+kk);
				}
				for(register int k=0;k<22;k++)
				{
					if(barrel[dist[x]^(1<<k)])
					{
						res[node]=Max(res[node],barrel[dist[x]^(1<<k)]+kk);
					}
				}
			}
			for(register int j=l[ed[i].to];j<=r[ed[i].to];j++)
			{
				barrel[dist[id[j]]]=Max(barrel[dist[id[j]]],depth[id[j]]);
			}
		}
	}
	if(!state)
	{
		for(register int i=l[node];i<=r[node];i++)
		{
			barrel[dist[id[i]]]=0;
		}
	}
}
int main()
{
	nc=read();
	for(register int i=0;i<nc-1;i++)
	{
		x=read(),cin>>ch;
		addEdge(i+2,x,1<<(ch-'a')),addEdge(x,i+2,1<<(ch-'a'));
	}
	dfs(1,0),ddfs(1,1);
	for(register int i=1;i<=nc;i++)
	{
		printf("%d ",res[i]);
	}
}
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll MAXN=2e5+51;
struct Edge{
	ll to,prev;
};
Edge ed[MAXN<<1];
vector<pair<ll,ll> >xx;
ll nc,tot,x,y,res,tmp;
ll last[MAXN],fa[MAXN],depth[MAXN],at[MAXN];
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
inline void dfs(ll node,ll f)
{
	fa[node]=f,depth[node]=depth[f]+1;
	for(register int i=last[node];i;i=ed[i].prev)
	{
		if(ed[i].to!=f)
		{
			dfs(ed[i].to,node);
		}
	}
}
inline void dfs2(ll node,ll rt)
{
	for(register int i=last[node];i;i=ed[i].prev)
	{
		if(ed[i].to!=fa[node])
		{
			dfs2(ed[i].to,at[ed[i].to]?ed[i].to:rt);
		}
	}
	if(!at[node])
	{
		if((depth[rt]<<1)>depth[y])
		{
			res+=depth[node],xx.push_back(make_pair(x,node));
		}
		else
		{
			res+=depth[node]+depth[y]-(depth[rt]<<1);
			xx.push_back(make_pair(y,node));
		}
	}
}
int main()
{
	nc=read(),depth[0]=-1;
	for(register int i=0;i<nc-1;i++)
	{
		x=read(),y=read(),addEdge(x,y),addEdge(y,x);
	}
	dfs(1,0),x=1;
	for(register int i=1;i<=nc;i++)
	{
		if(depth[i]>depth[x])
		{
			x=i;
		}
	}
	dfs(x,0),y=x;
	for(register int i=1;i<=nc;i++)
	{
		if(depth[i]>depth[y])
		{
			y=i;
		}
	}
	tmp=y,at[x]=1;
	while(tmp^x)
	{
		at[tmp]=1,tmp=fa[tmp];
	}
	dfs2(x,x);
	while(x^y)
	{
		res+=depth[y],xx.push_back(make_pair(x,y));
		y=fa[y];
	}
	printf("%lld\n",res);
	for(auto i:xx)
	{
		printf("%d ",i.first);
		printf("%d ",i.second);
		printf("%d\n",i.second);
	}
}
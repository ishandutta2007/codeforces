#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll MAXN=1e5+51;
struct Edge{
	ll to,prev;
};
Edge ed[MAXN<<1];
ll nc,tot,from,to,temp,sum;
ll last[MAXN],fa[MAXN],res[MAXN],size[MAXN],heavy[MAXN],barrel[MAXN];
ll used[MAXN],col[MAXN];
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
	fa[node]=f,size[node]=1;
	ll maxn=-1;
	for(register int i=last[node];i;i=ed[i].prev)
	{
		if(ed[i].to!=f)
		{
			dfs(ed[i].to,node);
			size[node]+=size[ed[i].to];
			if(size[ed[i].to]>maxn)
			{
				maxn=size[ed[i].to],heavy[node]=ed[i].to;
			}
		}
	}
}
inline void calc(ll node,ll add)
{
	barrel[col[node]]+=add;
	if(add>0&&barrel[col[node]]==temp)
	{
		sum+=col[node];
	}
	if(add>0&&barrel[col[node]]>temp)
	{
		temp=barrel[col[node]],sum=col[node];
	}
	for(register int i=last[node];i;i=ed[i].prev)
	{
		if(ed[i].to!=fa[node]&&!used[ed[i].to])
		{
			calc(ed[i].to,add);
		}
	}
}
inline void ddfs(ll node,ll state)
{
	for(register int i=last[node];i;i=ed[i].prev)
	{
		if(ed[i].to!=fa[node]&&ed[i].to!=heavy[node])
		{
			ddfs(ed[i].to,0);
		}
	}
	if(heavy[node])
	{
	   ddfs(heavy[node],1),used[heavy[node]]=1;
	}
	calc(node,1),res[node]=sum;
	if(heavy[node])
	{
		used[heavy[node]]=0;
	}
	if(!state)
	{
	    calc(node,-1);
    	temp=sum=0;
	}
}
int main()
{
    nc=read();
	for(register int i=1;i<=nc;i++)
	{
		col[i]=read();
	}
	for(register int i=0;i<nc-1;i++)
	{
		from=read(),to=read();
		addEdge(from,to),addEdge(to,from);
	}
	dfs(1,0),ddfs(1,0);
	for(register int i=1;i<=nc;i++)
	{
		printf("%lld ",res[i]);
	}
}
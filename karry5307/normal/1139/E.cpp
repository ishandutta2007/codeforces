#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=1e4+51;
struct Edge{
	ll to,prev;
};
Edge ed[MAXN<<1];
ll n,m,d,tot;
ll last[MAXN],p[MAXN],c[MAXN],x[MAXN],vis[MAXN],visr[MAXN];
ll match[MAXN],res[MAXN];
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
inline ll dfs(ll x)
{
	for(register int i=last[x];i;i=ed[i].prev)
	{
		if(!visr[ed[i].to])
		{
			visr[ed[i].to]=1;
			if(match[ed[i].to]==-1||dfs(match[ed[i].to]))
			{
				return match[ed[i].to]=x,1;
			}
		}
	}
	return 0;
}
int main()
{
	n=read(),m=read();
	for(register int i=1;i<=n;i++)
	{
		p[i]=read();
	}
	for(register int i=1;i<=n;i++)
	{
		c[i]=read();
	}
	d=read(),memset(match,-1,sizeof(match));
	for(register int i=1;i<=d;i++)
	{
		vis[x[i]=read()]=1;
	}
	for(register int i=1;i<=n;i++)
	{
		if(!vis[i])
		{
			addEdge(p[i],5000+c[i]),addEdge(5000+c[i],p[i]);
		}
	}
	for(register int i=d;i;i--)
	{
		for(register int j=res[i+1];j<=m;j++)
		{
			memset(visr,0,sizeof(visr));
			if(!dfs(j))
			{
				res[i]=j;
				break;
			}
		}
		addEdge(p[x[i]],5000+c[x[i]]),addEdge(5000+c[x[i]],p[x[i]]);
	}
	for(register int i=1;i<=d;i++)
	{
		printf("%d\n",res[i]);
	}
}
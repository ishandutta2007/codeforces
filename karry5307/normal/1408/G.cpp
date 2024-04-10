#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=3e3+51,MOD=998244353;
struct EdgeForKruskal{
	ll from,to,dist;
	inline bool operator <(const EdgeForKruskal &rhs)const
	{
		return this->dist<rhs.dist;
	}
};
EdgeForKruskal ed[MAXN*MAXN];
ll n,m,idx,u,v,itvc;
ll x[MAXN][MAXN],f[MAXN][MAXN],ffa[MAXN],sz[MAXN],edc[MAXN];
ll l[MAXN],r[MAXN],flg[MAXN];
vector<ll>g[MAXN],itv[MAXN];
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
inline ll find(ll x)
{
	return ffa[x]==x?x:ffa[x]=find(ffa[x]);
}
inline void add(ll x)
{
	if((++edc[x])==sz[x]*(sz[x]-1)/2)
	{
		flg[x]=1;
	}
}
inline void dfs(ll x)
{
	if(x<=n)
	{
		return (void)(l[x]=r[x]=++itvc);
	}
	l[x]=n+1;
	for(register int to:g[x])
	{
		dfs(to),l[x]=min(l[x],l[to]);
	}
	r[x]=itvc,flg[x]?itv[r[x]].push_back(l[x]):(void)1;
}
int main()
{
	n=read(),f[0][0]=1;
	for(register int i=1;i<=n;i++)
	{
		for(register int j=1;j<=n;j++)
		{
			x[i][j]=read();
			j>i?(void)(ed[++m]=(EdgeForKruskal){i,j,x[i][j]}):(void)1;
		}
	}
	idx=n,sort(ed+1,ed+m+1);
	for(register int i=1;i<=n;i++)
	{
		flg[i]=1,itv[i].push_back(i),ffa[i]=i,sz[i]=1,edc[i]=0;
	}
	for(register int i=1;i<=m;i++)
	{
		u=find(ed[i].from),v=find(ed[i].to);
		if(u==v)
		{
			add(u);
		}
		else
		{
			g[++idx].push_back(u),g[idx].push_back(v);
			ffa[u]=ffa[v]=ffa[idx]=idx;
			sz[idx]=sz[u]+sz[v],edc[idx]=edc[u]+edc[v],add(idx);
		}
	}
	dfs(idx);
	for(register int i=1;i<=n;i++)
	{
		for(register int j=1;j<=n;j++)
		{
			for(register int k:itv[i])
			{
				f[i][j]=(f[i][j]+f[k-1][j-1])%MOD;
			}
		}
	}
	for(register int i=1;i<=n;i++)
	{
		printf("%d ",f[n][i]);
	}
}
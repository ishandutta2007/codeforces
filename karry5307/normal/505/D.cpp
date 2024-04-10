#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51;
ll n,m,u,v,res;
bitset<MAXN>c;
vector<ll>g[MAXN],vg[MAXN];
ll col[MAXN],vis[MAXN],r[MAXN];
inline ll read()
{
    register ll num=0;
    register char ch=getchar();
    while(!isdigit(ch)&&ch!='-')
    {
        ch=getchar();
    }
    while(isdigit(ch))
    {
        num=(num<<3)+(num<<1)+(ch-'0');
        ch=getchar();
    }
    return num;
}
inline void dfs(ll x)
{
	col[x]=res;
	for(auto i:vg[x])
	{
		!col[i]?dfs(i):(void)1;
	}
}
inline void dfs2(ll x)
{
	vis[x]=r[x]=1;
	for(auto i:g[x])
	{
		!vis[i]?dfs2(i),1:r[i]?c[col[x]]=1:1;
	}
	r[x]=0;
}
int main()
{
	n=read(),m=read();
	for(register int i=1;i<=m;i++)
	{
		u=read(),v=read(),g[u].push_back(v);
		vg[u].push_back(v),vg[v].push_back(u);
	}
	for(register int i=1;i<=n;i++)
	{
		!col[i]?++res,dfs(i):(void)1;
	}
	for(register int i=1;i<=n;i++)
	{
		!vis[i]?dfs2(i):(void)1;
	}
	printf("%d\n",n-res+c.count());
}
#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51;
ll n,m,u,v,res;
ll x[MAXN],c[MAXN],f[MAXN],g[MAXN];
vector<ll>vg[MAXN];
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
inline void dfs(ll node,ll fa)
{
	f[node]=x[node]?f[fa]+1:0,g[node]=max(g[fa],f[node]),c[node]=1;
	for(register int i:vg[node])
	{
		i!=fa?dfs(i,node),c[node]=0:1;
	}
	res+=c[node]&&(g[node]<=m);
}
int main()
{
	n=read(),m=read();
	for(register int i=1;i<=n;i++)
	{
		x[i]=read();
	}
	for(register int i=0;i<n-1;i++)
	{
		u=read(),v=read();
		vg[u].push_back(v),vg[v].push_back(u);
	}
	dfs(1,0),printf("%d\n",res);
}
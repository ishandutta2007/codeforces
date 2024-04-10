#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=3e3+51,MOD=1e9+7;
ll n,m,u,v,res;
vector<ll>vg[MAXN];
ll f[MAXN][MAXN],g[MAXN][MAXN],pl[MAXN],pr[MAXN],fact[MAXN];
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
inline ll qpow(ll base,ll exponent)
{
	ll res=1;
	while(exponent)
	{
		if(exponent&1)
		{
			res=(li)res*base%MOD;
		}
		base=(li)base*base%MOD,exponent>>=1;
	}
	return res;
}
inline void dfs(ll node)
{
	for(register int i=1;i<=n+5;i++)
	{
		f[node][i]=1;
	}
	for(register int i:vg[node])
	{
		dfs(i);
		for(register int j=1;j<=n+5;j++)
		{
			f[node][j]=(li)f[node][j]*g[i][j]%MOD;
		}
	}
	for(register int i=1;i<=n+5;i++)
	{
		g[node][i]=(g[node][i-1]+f[node][i])%MOD;
	}
}
int main()
{
	n=read(),m=read();
	for(register int i=2;i<=n;i++)
	{
		vg[read()].push_back(i);
	}
	dfs(1),pl[0]=pr[n+2]=fact[0]=1;
	for(register int i=1;i<=n+1;i++)
	{
		pl[i]=(li)pl[i-1]*(m-i+MOD)%MOD,fact[i]=(li)fact[i-1]*i%MOD;
	}
	for(register int i=n+1;i;i--)
	{
		pr[i]=(li)pr[i+1]*(m-i+MOD)%MOD;
	}
	for(register int i=1;i<=n+1;i++)
	{
		v=(li)fact[i-1]*fact[n+1-i]%MOD,v=(n-i)&1?v:MOD-v;
		u=(li)pl[i-1]*pr[i+1]%MOD;
		res=(res+(li)g[1][i]*u%MOD*qpow(v,MOD-2)%MOD)%MOD;
	}
	printf("%d\n",res);
}
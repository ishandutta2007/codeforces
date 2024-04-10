#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51,MOD=1e9+7;
ll n;
ll x[MAXN],f[MAXN][2],g[MAXN];
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
	ll prod=1,sm=0;
	for(register int i:vg[node])
	{
		dfs(i),prod=(li)prod*g[i]%MOD;
		sm=(sm+(li)f[i][1]*qpow(g[i],MOD-2))%MOD;
	}
	f[node][0]=x[node]?0:prod,f[node][1]=x[node]?prod:(li)prod*sm%MOD;
	g[node]=(f[node][0]+f[node][1])%MOD;
}
int main()
{
    n=read();
    for(register int i=2;i<=n;i++)
    {
    	vg[read()+1].push_back(i);
	}
	for(register int i=1;i<=n;i++)
	{
		x[i]=read();
	}
	dfs(1),printf("%d\n",f[1][1]);
}
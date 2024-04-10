#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=1e6+51,MOD=998244353;
vector<ll>g[MAXN];
ll cnt,p,mx,q,res,invl;
ll x[MAXN],invx[MAXN];
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
int main()
{
	cnt=read(),invl=qpow(cnt,MOD-2);
	for(register int i=1;i<=cnt;i++)
	{
		x[i]=read(),invx[i]=qpow(x[i],MOD-2);
		for(register int j=1;j<=x[i];j++)
		{
			p=read(),g[p].push_back(i),mx=max(mx,p);
		}
	}
	for(register int i=1;i<=mx;i++)
	{
		q=0;
		for(register int j=0;j<g[i].size();j++)
		{
			q=(q+(li)invx[g[i][j]]*invl%MOD)%MOD;
		}
		res=(res+(li)q*invl%MOD*g[i].size()%MOD)%MOD;
	}
	printf("%d\n",res);
}
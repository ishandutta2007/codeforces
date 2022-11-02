#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51,MOD=1e9+7;
ll n,kk,res,r,pw,rr,invl;
ll x[MAXN],f[MAXN];
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
	n=read(),kk=read(),res=f[0]=pw=rr=1,invl=qpow(n,MOD-2);
	for(register int i=1;i<=n;i++)
	{
		x[i]=read(),res=(li)res*x[i]%MOD;
		for(register int j=i;j>=0;j--)
		{
			f[j]=((li)x[i]*f[j]+(MOD-f[j-1]))%MOD;
		}
	}
	for(register int i=0;i<=n;i++)
	{
		r=(r+(li)f[i]*pw%MOD*rr)%MOD,pw=(li)pw*invl%MOD,rr=(li)rr*(kk-i)%MOD;
	}
	printf("%d\n",(res-r+MOD)%MOD);
}
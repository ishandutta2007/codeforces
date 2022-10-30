#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll MAXN=1e4+51,MOD=1e9+7;
ll x,cnt,tot,res;
ll factor[MAXN];
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
inline void getFact(ll x)
{
	for(register int i=2;i<=sqrt(x);i++)
	{
		if(!(x%i))
		{
			factor[++tot]=i;
			while(!(x%i))
			{
				x/=i;
			}
		}
	}
	if(x!=1)
	{
		factor[++tot]=x;
	}
}
inline ll qpow(ll base,ll exponent)
{
	ll res=1;
	while(exponent)
	{
		if(exponent&1)
		{
			res=res*base%MOD;
		}
		base=base*base%MOD,exponent>>=1;
	}
	return res;
}
inline ll calc(ll cnt,ll x,ll p)
{
	if(cnt==0)
	{
		return 1;
	}
	return qpow(p,(cnt-cnt/x)%(MOD-1))*calc(cnt/x,x,p*x%MOD)%MOD;
}
int main()
{
	x=read(),cnt=read(),getFact(x),res=1;
	for(register int i=1;i<=tot;i++)
	{
		res=res*calc(cnt,factor[i],1)%MOD;
	}
	cout<<res<<endl;
}
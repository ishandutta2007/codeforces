#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll MAXN=2e5+51,MOD=1e9+7,INV3=333333336;
ll n,x,c=1;
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
			res=res*base%MOD; 
		}
		base=base*base%MOD,exponent>>=1;
	}
	return res;
}
int main()
{
	n=read();
	for(register int i=1;i<=n;i++)
	{
		x=read()%(MOD-1),c=c*x%(MOD-1);
	}
	c=(c+MOD-2)%(MOD-1);
	printf("%lld/%lld",(qpow(2,c)-qpow(MOD-1,c)+MOD)*INV3%MOD,qpow(2,c));
}
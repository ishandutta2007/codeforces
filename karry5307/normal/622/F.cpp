#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=1e6+51,MOD=1e9+7;
ll n,kk,x,p,q,res;
ll pl[MAXN],pr[MAXN],fact[MAXN];
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
	n=read(),kk=read(),pl[0]=pr[kk+3]=fact[0]=1;
	for(register int i=1;i<=kk+2;i++)
	{
		pl[i]=(li)pl[i-1]*(n-i+MOD)%MOD,fact[i]=(li)fact[i-1]*i%MOD;
	}
	for(register int i=kk+2;i;i--)
	{
		pr[i]=(li)pr[i+1]*(n-i+MOD)%MOD;
	}
	for(register int i=1;i<=kk+2;i++)
	{
		x=(x+qpow(i,kk))%MOD;
		p=(li)pl[i-1]*pr[i+1]%MOD;
		q=(li)fact[i-1]*((kk-i)&1?MOD-1:1)%MOD*fact[kk+2-i]%MOD;
		res=(res+(li)x*p%MOD*qpow(q,MOD-2)%MOD)%MOD;
	}
	printf("%d\n",res%MOD);
}
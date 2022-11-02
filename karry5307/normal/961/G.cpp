#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51,MOD=1e9+7;
ll num,sum,cnt,k,res;
ll fact[MAXN],finv[MAXN];
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
inline void setup(ll num)
{
	fact[0]=finv[0]=1;
	for(register int i=1;i<=num;i++)
	{
		fact[i]=(li)fact[i-1]*i%MOD;
	}
	finv[num]=qpow(fact[num],MOD-2);
	for(register int i=num-1;i;i--)
	{
		finv[i]=(li)finv[i+1]*(i+1)%MOD;
	}
}
inline ll getSt(ll n,ll m)
{
	li res=0;
	for(register int i=0;i<=n;i++)
	{
		res=res+(li)((n-i)&1?MOD-1:1)*qpow(i,m)%MOD*finv[i]%MOD*finv[n-i]%MOD;
		res%=MOD;
	}
	return res;
}
int main()
{
	cnt=read(),k=read(),setup(cnt);
	for(register int i=0;i<cnt;i++)
	{
		sum=(sum+(num=read()))%MOD;
	}
	res=(getSt(k,cnt)+(li)(cnt-1)*getSt(k,cnt-1)%MOD)%MOD;
	printf("%d\n",(li)res*sum%MOD);
}
///
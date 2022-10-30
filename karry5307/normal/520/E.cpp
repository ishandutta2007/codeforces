#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51,MOD=1e9+7;
ll n,m,cur,res;
ll fact[MAXN],finv[MAXN],prefix[MAXN];
char ch[MAXN];
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
inline void setup(ll cnt)
{
	fact[0]=fact[1]=finv[0]=1;
	for(register int i=2;i<=cnt;i++)
	{
		fact[i]=(li)fact[i-1]*i%MOD;
	}
	finv[cnt]=qpow(fact[cnt],MOD-2);
	for(register int i=cnt-1;i;i--)
	{
		finv[i]=(li)finv[i+1]*(i+1)%MOD;
	}
}
inline ll binom(ll m,ll n)
{
	return (li)fact[m]*finv[n]%MOD*finv[m-n]%MOD;
}
int main()
{
	setup(n=read()),m=read(),scanf("%s",ch+1),cur=1;
	for(register int i=1;i<=n;i++)
	{
		prefix[i]=prefix[i-1]+(ch[i]-='0');
	}
	for(register int i=n;i>m;i--)
	{
		res=(res+(li)ch[i]*binom(i-1,m)%MOD*cur%MOD)%MOD;
		res=(res+(li)prefix[i-1]*binom(i-2,m-1)%MOD*cur%MOD)%MOD;
		cur=(li)cur*10%MOD;
	}
	printf("%d\n",res);
}
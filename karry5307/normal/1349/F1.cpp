#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=5e3+51,MOD=998244353;
ll n,res;
ll p[MAXN][MAXN],fact[MAXN],finv[MAXN];
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
    for(register int i=0;i<=cnt;i++)
    {
	p[i][0]=1;
    }
    for(register int i=1;i<=cnt;i++)
    {
	for(register int j=1;j<=i;j++)
	{
	    p[i][j]=((li)(i-j)*p[i-1][j-1]%MOD+(li)(j+1)*p[i-1][j]%MOD)%MOD;
	}
    }
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
    setup(n=read());
    for(register int k=0;k<n;k++)
    {
	res=0;
	for(register int i=max(k,1);i<=n;i++)
	{
	    res=(res+(li)binom(n,i)*p[i][k]%MOD*fact[n-i]%MOD)%MOD;
	}
	printf("%d ",res);
    }
    puts("");
}
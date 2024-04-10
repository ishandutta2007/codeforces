#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51,MOD=1e9+7;
ll n,kk,res,sm;
ll x[MAXN],fact[MAXN],finv[MAXN];
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
    for(register int i=1;i<=cnt;i++)
    {
        fact[i]=(li)fact[i-1]*i%MOD;
    }
    finv[cnt]=qpow(fact[cnt],MOD-2);
    for(register int i=cnt-1;i;i--)
    {
        finv[i]=(li)finv[i+1]*(i+1)%MOD;
    }
}
int main()
{
	n=read(),kk=read(),setup(n),res=fact[n-kk];
	for(register int i=1;i<=kk;i++)
	{
		x[i]=read();
	}
	sort(x+1,x+kk+1);
	for(register int i=1;i<=kk;i++)
	{
		res=(li)res*finv[x[i]-x[i-1]-1]%MOD;
	}
	res=(li)res*finv[n-x[kk]]%MOD;
	for(register int i=2;i<=kk;i++)
	{
		x[i]-x[i-1]>1?res=(li)res*qpow(2,x[i]-x[i-1]-2)%MOD:1;
	}
	printf("%d\n",res);
}
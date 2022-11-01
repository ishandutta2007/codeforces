#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=5e3+51,MOD=998244353;
ll n,m,kk,res,invl,binom=1,fct=1,pw;
ll st[MAXN][MAXN];
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
	n=read(),m=read(),kk=read(),st[0][0]=1,invl=qpow(m,MOD-2),pw=qpow(m,n);
	for(register int i=1;i<=kk;i++)
	{
		for(register int j=1;j<=i;j++)
		{
			st[i][j]=(st[i-1][j-1]+(li)j*st[i-1][j])%MOD;
		}
	}
	for(register int i=0;i<=kk;i++)
	{
		res=(res+(li)st[kk][i]*fct%MOD*binom%MOD*pw)%MOD,pw=(li)pw*invl%MOD;
		fct=(li)fct*(i+1)%MOD,binom=(li)binom*(n-i)%MOD*qpow(i+1,MOD-2)%MOD;
	}
	printf("%d\n",(li)res*qpow(invl,n)%MOD);
}
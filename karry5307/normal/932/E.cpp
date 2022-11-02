#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=5e3+51,MOD=1e9+7;
ll num,k,cur,cfact,res,pw=500000004;
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
inline void setup(ll cnt)
{
	st[0][0]=1;
	for(register int i=1;i<=cnt;i++)
	{
		for(register int j=1;j<=i;j++)
		{
			st[i][j]=(st[i-1][j-1]+(li)st[i-1][j]*j%MOD)%MOD;
		}
	}
}
int main()
{
	num=read(),setup(k=read()),cur=qpow(2,num),cfact=1;
	for(register int i=0;i<=k;i++)
	{
		res=(res+(li)cfact*st[k][i]%MOD*cur%MOD)%MOD;
		cfact=(li)cfact*(num-i)%MOD,cur=(li)cur*pw%MOD;
	}
	printf("%d",res);
}
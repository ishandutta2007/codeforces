#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll MAXN=3e3+51,MOD=1e9+7;
ll num,k,pw,res=1;
ll dp[62][10051];
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
inline ll calc(ll p,ll x,ll y)
{
	if(!x)
	{
		return (dp[x][y]=1);
	}	
	if(!y)
	{
		if(!dp[x][y])
		{
			dp[x][y]=calc(p,x-1,y)*p%MOD;
		}
		return dp[x][y];
	}
	ll res=0;
	for(register int k=0;k<=x;k++)
	{
		if(!dp[k][y-1])
		{
			dp[k][y-1]=calc(p,k,y-1);
		}
		res=(res+dp[k][y-1])%MOD;
	}
	return res*qpow(x+1,MOD-2)%MOD;
} 
int main()
{
	num=read(),k=read();
	for(register int i=2;i<=sqrt(num);i++)
	{
		if(!(num%i))
		{
			pw=0;
			while(!(num%i))
			{
				pw++,num/=i;
			}
			memset(dp,0,sizeof(dp)),res=res*calc(i,pw,k)%MOD;
		}
	}
	memset(dp,0,sizeof(dp));
	if(num>1)
	{
		res=res*calc(num,1,k)%MOD;
	}
	printf("%lld\n",res);
}
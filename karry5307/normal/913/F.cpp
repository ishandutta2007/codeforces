#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e3+51,MOD=998244353;
ll cnt,numer,denom,p,cur;
ll pw[MAXN*MAXN],pw2[MAXN*MAXN],dp[MAXN][MAXN];
ll dp1[MAXN],dp2[MAXN],dp3[MAXN];
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
    li res=1;
    while(exponent)
    {
        if(exponent&1)
        {
            res=1ll*res*base%MOD;
        }
        base=1ll*base*base%MOD,exponent>>=1;
    }
    return res;
}
int main()
{
	cnt=read(),numer=read(),denom=read(),p=(li)numer*qpow(denom,MOD-2)%MOD;
	pw[0]=pw2[0]=dp[0][0]=1;
	if(cnt<=2)
	{
		return printf("%d\n",cnt-1),0;
	}
	for(register int i=1;i<=cnt*cnt;i++)
	{
		pw[i]=(li)pw[i-1]*p%MOD,pw2[i]=(li)pw2[i-1]*(MOD+1-p)%MOD;
	}
	for(register int i=1;i<=cnt;i++)
	{
		dp[i][0]=1;
		for(register int j=1;j<=i;j++)
		{
			dp[i][j]=(li)dp[i-1][j-1]*pw2[i-j]%MOD;
			dp[i][j]=(dp[i][j]+(li)dp[i-1][j]*pw[j]%MOD)%MOD;
		}
	}
	for(register int i=1;i<=cnt;i++)
	{
		dp1[i]=1;
		for(register int j=1;j<i;j++)
		{
			dp1[i]=(dp1[i]+MOD-(li)dp1[j]*dp[i][j]%MOD)%MOD;
		}
	}
	for(register int i=3;i<=cnt;i++)
	{
		cur=0;
		for(register int j=1;j<i;j++)
		{
			cur=(cur+(li)(dp2[j]+dp3[i-j])*dp1[j]%MOD*dp[i][j]%MOD)%MOD;
		}
		dp2[i]=(li)qpow(MOD+1-dp1[i],MOD-2)*((i*(i-1)/2+cur)%MOD)%MOD;
		dp3[i]=((li)dp1[i]*dp2[i]%MOD+cur)%MOD;
	}
	printf("%d\n",dp2[cnt]);
}
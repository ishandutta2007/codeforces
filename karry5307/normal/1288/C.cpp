#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=1e3+51,MOD=1e9+7;
ll x,y,res;
ll dp[MAXN][MAXN];
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
	x=read(),y=read();
	for(register int i=1;i<=x;i++)
	{
		dp[1][i]=1;
	}
	for(register int i=2;i<=y;i++)
	{
		for(register int j=1;j<=x;j++)
		{
			for(register int k=1;k<=j;k++)
			{
				dp[i][j]=(dp[i][j]+dp[i-1][k])%MOD;
			}
		}
	}
	for(register int i=1;i<=x;i++)
	{
		for(register int j=i;j<=x;j++)
		{
			res=(res+(li)dp[y][i]*dp[y][x-j+1]%MOD)%MOD;
		}
	}
	printf("%d\n",res);
}
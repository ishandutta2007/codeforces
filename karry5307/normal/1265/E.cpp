#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51,MOD=998244353;
ll cnt;
ll p[MAXN],dp[MAXN]; 
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
            res=1ll*res*base%MOD;
        }
        base=1ll*base*base%MOD,exponent>>=1;
    }
    return res;
}
int main()
{
	cnt=read();
	for(register int i=1;i<=cnt;i++)
	{
		p[i]=read();
	}
	dp[0]=1;
	for(register int i=1;i<=cnt;i++)
	{
		dp[i]=(li)dp[i-1]*100%MOD*qpow(p[i],MOD-2)%MOD;
		dp[i]=(dp[i]+1)%MOD; 
	}
	printf("%lld\n",(li)(dp[cnt]-1+MOD)%MOD);
}
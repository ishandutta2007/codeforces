#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51;
ll test,h,cnt;
ll x[MAXN],dp[MAXN];
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
inline void solve()
{
	h=read(),cnt=read(),dp[0]=dp[1]=0;
	for(register int i=1;i<=cnt;i++)
	{
		x[cnt-i+1]=read();
	}
	for(register int i=2;i<=cnt;i++)
	{
		dp[i]=x[i-1]==(x[i-2]+1)?dp[i-2]:dp[i-1]+1;
	}
	printf("%d\n",dp[cnt]);
}
int main()
{
	test=read();
	for(register int i=0;i<test;i++)
	{
		solve();
	}
}
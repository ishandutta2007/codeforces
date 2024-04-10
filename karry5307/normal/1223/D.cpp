#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=3e5+51;
ll test,cnt,res;
ll disc[MAXN],x[MAXN],dp[MAXN],h[MAXN],t[MAXN];
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
	cnt=read(),res=0;
	for(register int i=1;i<=cnt;i++)
	{
		x[i]=read();
		if(!h[x[i]])
		{
			h[x[i]]=i;
		}
		t[x[i]]=i;
	}
	sort(x+1,x+cnt+1),cnt=unique(x+1,x+cnt+1)-x-1;
	for(register int i=1;i<=cnt;i++)
	{
		if(h[x[i]]>t[x[i-1]])
		{
			dp[x[i]]=dp[x[i-1]]+1;
		}
		else
		{
			dp[x[i]]=1;
		}
		res=max(res,dp[x[i]]);
	}
	printf("%d\n",cnt-res);
	for(register int i=1;i<=cnt;i++)
	{
		h[x[i]]=t[x[i]]=0;
	}
}
int main()
{
	test=read();
	for(register int i=0;i<test;i++)
	{
		solve();
	}
}
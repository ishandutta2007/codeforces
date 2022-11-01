#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll MAXN=3e3+51;
ll test,n,mx,res;
ll x[MAXN],pr[MAXN][MAXN];
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
	n=read(),mx=res=0;
	for(register int i=1;i<=n;i++)
	{
		mx=max(mx,x[i]=read());
	}
	for(register int i=1;i<=n;i++)
	{
		for(register int j=1;j<=mx;j++)
		{
			pr[i][j]=pr[i-1][j];
		}
		pr[i][x[i]]++;
	}
	for(register int i=1;i<=n;i++)
	{
		for(register int j=i+1;j<=n;j++)
		{
			res+=pr[i-1][x[j]]*(pr[n][x[i]]-pr[j][x[i]]);
		}
	}
	for(register int i=1;i<=n;i++)
	{
		for(register int j=1;j<=mx;j++)
		{
			pr[i][j]=0;
		}
	}
	printf("%lld\n",res);
}
int main()
{
	test=read();
	for(register int i=0;i<test;i++)
	{
		solve();
	}
}
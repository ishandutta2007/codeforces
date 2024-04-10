#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51,inf=0x3f3f3f3f;
ll test,n;
ll x[MAXN],f[MAXN],g[MAXN];
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
	n=read();
	for(register int i=1;i<=n;i++)
	{
		x[i]=read(),f[i]=g[i]=inf;
	}
	f[1]=inf,g[1]=f[2]=x[1],g[2]=x[1]+x[2];
	for(register int i=3;i<=n;i++)
	{
		f[i]=min(f[i],min(g[i-1],i>1?g[i-2]:inf));
		g[i]=min(g[i],min(f[i-1]+x[i],i>1?f[i-2]+x[i-1]+x[i]:inf));
	}
	printf("%d\n",min(f[n],g[n]));
}
int main()
{
	test=read();
	for(register int i=0;i<test;i++)
	{
		solve();
	}
}
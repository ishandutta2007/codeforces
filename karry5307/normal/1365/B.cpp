#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51; 
ll test,n,p,u;
ll x[MAXN];
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
		x[i]=read();
	}
	u=read(),p=0;
	for(register int i=1;i<n;i++)
	{
		p|=(read()!=u);
	}
	if(p==1)
	{
		return (void)puts("Yes");
	}
	for(register int i=2;i<=n;i++)
	{
		if(x[i]<x[i-1])
		{
			return (void)puts("No");
		}
	}
	puts("Yes");
}
int main()
{
	test=read();
	for(register int i=0;i<test;i++)
	{
		solve();
	}
}
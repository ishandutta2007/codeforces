#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51;
ll test,n,s;
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
inline ll calc(ll p)
{
	ll x=(p+1)/2+1;
	return p&1?x*x-x:x*x;
}
inline void solve()
{
	n=read();
	if(n==1)
	{
		return (void)puts("0");
	}
	s=2*sqrt(n);
	for(register int i=s-5;i<=s+5;i++)
	{
		if(calc(i-1)<n&&calc(i)>=n)
		{
			return (void)printf("%d\n",i);
		}
	}
}
int main()
{
	test=read();
	for(register int i=1;i<=test;i++)
	{
		solve();
	}
}
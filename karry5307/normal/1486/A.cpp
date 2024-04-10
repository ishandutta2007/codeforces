#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll MAXN=2e5+51;
ll test,n;
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
	if(n==1)
	{
		return (void)puts("Yes");
	}
	for(register int i=1;i<=n-1;i++)
	{
		if(x[i]<i-1)
		{
			return (void)puts("No");
		}
		x[i+1]+=(x[i]-(i-1)),x[i]=i-1;
	}
	puts(x[n]>x[n-1]?"Yes":"No");
}
int main()
{
    test=read();
    for(register int i=0;i<test;i++)
	{
		solve();
	} 
}
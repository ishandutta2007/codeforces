#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=4e5+51;
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
	puts(x[1]<x[n]?"YES":"NO");
}
int main()
{
	test=read();
	for(register int i=0;i<test;i++)
	{
		solve();
	}
}
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll MAXN=2e5+51;
unordered_map<ll,ll>mp;
ll test,x;
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
	x=read();
	for(register int i=1;i<=(ll)cbrt(x);i++)
	{
		if(mp[x-(ll)i*i*i])
		{
			return (void)puts("Yes");
		}
	}
	puts("No");
}
int main()
{
	for(register int i=1;i<=10000;i++)
	{
		mp[(ll)i*i*i]=1;
	}
	test=read();
	for(register int i=0;i<test;i++)
	{
		solve();
	}
}
#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51;
ll test,n,mn,mn2;
li res;
ll x[MAXN],y[MAXN];
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
	n=read(),mn=mn2=0x3f3f3f3f,res=0;
	for(register int i=1;i<=n;i++)
	{
		mn=min(mn,x[i]=read());
	}
	for(register int i=1;i<=n;i++)
	{
		mn2=min(mn2,y[i]=read());
	}
	for(register int i=1;i<=n;i++)
	{
		res+=max(x[i]-mn,y[i]-mn2);
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
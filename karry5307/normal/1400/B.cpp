#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll MAXN=2e5+51;
ll test,p,f,cs,cw,s,w,syk;
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
inline ll calc(ll x)
{
	if(s*x>p)
	{
		return 0;
	}
	ll c=min(cw,(p-s*x)/w),c2=min(cs-x,f/s),c3=min(cw-c,(f-s*c2)/w);
	return x+c+c2+c3;
}
inline void solve()
{
	p=read(),f=read(),cs=read(),cw=read(),s=read(),w=read(),syk=0;
	s>w?swap(s,w),swap(cs,cw):(void)1;
	for(register int i=0;i<=cs;i++)
	{
		syk=max(syk,calc(i));
	}
	printf("%lld\n",syk);
}
int main()
{
	test=read();
	for(register int i=0;i<test;i++)
	{
		solve();
	}
}
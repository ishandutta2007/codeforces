#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51;
ll n;
li sm;
ll x[MAXN],y[MAXN],res[MAXN],rx[MAXN],ry[MAXN];
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
inline void calc(ll bit)
{
	ll r0=0,r1=0;
	for(register int i=1;i<=n;i++)
	{
		(res[i]>>bit)&1?r1++:r0++;
	}
	for(register int i=1;i<=n;i++)
	{
		rx[i]+=(1<<bit)*((res[i]>>bit)&1?r1:0);
		ry[i]+=(1<<bit)*((res[i]>>bit)&1?n:r1);
	}
}
int main()
{
    n=read();
    for(register int i=1;i<=n;i++)
    {
    	x[i]=read(),sm+=x[i];
	}
	for(register int i=1;i<=n;i++)
    {
    	y[i]=read(),sm+=y[i];
	}
	if(sm%(2*n))
	{
		return puts("-1"),0;
	}
	sm/=2*n;
	for(register int i=1;i<=n;i++)
	{
		res[i]=(x[i]+y[i]-sm)/n;
	}
	for(register int i=0;i<=31;i++)
	{
		calc(i);
	}
	for(register int i=1;i<=n;i++)
	{
		if(x[i]!=rx[i]||y[i]!=ry[i])
		{
			return puts("-1"),0;
		}
	}
	for(register int i=1;i<=n;i++)
	{
		printf("%d ",res[i]);
	}
}
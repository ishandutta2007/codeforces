#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll MAXN=2e5+51,inf=1e18;
ll n,kk,l,r,mid,sm;
ll u[MAXN],v[MAXN];
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
inline ll f(ll u,ll x)
{
	return u==x?inf:u-3*x*x+3*x-1;
}
inline ll calc(ll x,ll lim)
{
	ll l=1,r=u[x],mid,res=u[x];
	while(l<=r)
	{
		mid=(l+r)>>1;
		f(u[x],mid)<=lim?r=mid-1,res=mid:l=mid+1;
	}
	return res;
}
inline ll check(ll mid)
{
	sm=0;
	for(register int i=1;i<=n;i++)
	{
		sm+=(v[i]=calc(i,mid));
	}
	return sm<kk;
}
int main()
{
	n=read(),kk=read();
	for(register int i=1;i<=n;i++)
	{
		u[i]=read(),l=min(l,f(u[i],u[i]-1)),r=max(r,f(u[i],0));
	}
	while(r-l>=2)
	{
		mid=(l+r)>>1;
		check(mid)?r=mid:l=mid;
	}
	r=check(l)?l:r,check(r),kk-=sm;
	for(register int i=1;i<=n;i++)
	{
		kk&&v[i]<u[i]&&f(u[i],v[i])==r?v[i]++,kk--:1;
	}
	for(register int i=1;i<=n;i++)
	{
		printf("%lld ",v[i]);
	}
}
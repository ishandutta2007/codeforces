#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll MAXN=2e5+51;
ll n,c0,c1,res,l,r,mid,rr,x,y,z;
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
inline ll binom(ll m,ll n)
{
	if(m<n)
	{
		return 0;
	}
	ll res=1;
	for(register int i=m,j=1;j<=n;i--,j++)
	{
		res=res*i/j;
	}
	return res;
}
inline ll check(ll mid)
{
	ll x=mid/c1,y=0,sm=0;
	for(register int i=x;sm<n&&i>=0;i--)
	{
		y=(mid-c1*i)/c0,sm+=binom(i+y+1,i+1);
	}
	return sm>=n;
}
int main()
{
	n=read()-1,c0=read(),c1=read(),c0>c1?swap(c0,c1):(void)1;
	if(!c0)
	{
		return printf("%lld\n",n*c1),0;
	}
	l=0,r=c1*31;
	while(l<=r)
	{
		mid=(l+r)>>1;
		check(mid)?rr=mid,r=mid-1:l=mid+1;
	}
	res=n*(c0+c1),x=(--rr)/c1,y=0;
	for(register int i=x;i>=0;i--)
	{
		z=binom(i+(y=(rr-c1*i)/c0)+1,i+1),n-=z;
		res+=(z*y-binom(i+y+1,i+2))*c0+i*z*c1;
	}
	printf("%lld\n",res+n*(rr+1));
}
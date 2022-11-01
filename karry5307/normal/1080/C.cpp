#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll MAXN=2e5+51;
ll test,n,m,x1,y1,x2,y2,x3,y3,x4,y4,s,u,d,l,r;
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
inline ll calcBlack(ll xl,ll yl,ll xr,ll yr)
{
	ll n=xr-xl+1,m=yr-yl+1;
	return n*(m/2)+((m&1)?(xl+yl&1)*(n&1)+(n/2):0);
}
inline ll calcWhite(ll xl,ll yl,ll xr,ll yr)
{
	return (xr-xl+1)*(yr-yl+1)-calcBlack(xl,yl,xr,yr);
}
inline void solve()
{	
	n=read(),m=read(),swap(n,m),s=calcWhite(1,1,n,m);
	x1=read(),y1=read(),x2=read(),y2=read();
	x3=read(),y3=read(),x4=read(),y4=read();
	u=max(x1,x3),d=min(x2,x4),l=max(y1,y3),r=min(y2,y4);
	s+=calcBlack(x1,y1,x2,y2)-calcWhite(x3,y3,x4,y4);
	s-=(u<=d&&l<=r?calcBlack(u,l,d,r):0),printf("%lld %lld\n",s,n*m-s);
}
int main()
{
	test=read();
	for(register int i=0;i<test;i++)
	{
		solve();
	}	
}
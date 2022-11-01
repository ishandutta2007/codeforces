#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll MAXN=2e5+51;
ll xt,yt,cx,cy,dx,dy,xs,ys,t,tot,res,curx,cury,curt;
ll x[MAXN],y[MAXN],prefix[MAXN];
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
inline ll calcLeft(ll x,ll t)
{
	ll res=1,c;
	while(t>=(c=prefix[x]-prefix[x-1])&&x>1)
	{
		t-=c,x--,res++;
	}
	return res;
}
inline ll calcRight(ll x,ll t)
{
	ll res=1,c;
	while(t>=(c=prefix[x+1]-prefix[x])&&x<tot)
	{
		t-=c,x++,res++;
	}
	return res;
}
int main()
{
	xt=read(),yt=read(),cx=read(),cy=read(),dx=read(),dy=read();
	xs=read(),ys=read(),t=read(),x[++tot]=xt,y[tot]=yt;
	for(register int i=2;i;i++)
	{
		x[++tot]=cx*x[i-1]+dx,y[tot]=cy*y[i-1]+dy;
		prefix[tot]=prefix[tot-1]+x[i]-x[i-1]+y[i]-y[i-1];
		if(x[tot]>=2e16||y[tot]>=2e16)
		{
			break;
		}
	}
	for(register int i=1;i<=tot;i++)
	{
		if((curt=llabs(x[i]-xs)+llabs(y[i]-ys))>t)
		{
			continue;
		}
		curx=x[i],cury=y[i],curt=t-curt;
		res=max(res,max(calcRight(i,curt),calcLeft(i,curt)));
	}
	printf("%lld\n",res);
}
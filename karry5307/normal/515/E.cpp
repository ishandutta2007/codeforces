#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll MAXN=2e5+51,inf=0x3f3f3f3f3f3f3f3f;
ll n,m,sm,c,l,r;
ll d[MAXN],h[MAXN],u[MAXN],v[MAXN],lg[MAXN];
ll mn[MAXN][20],mx[MAXN][20];
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
inline ll gmx(ll x,ll y)
{
	return u[x]>u[y]?x:y;
}
inline ll gmn(ll x,ll y)
{
	return v[x]<v[y]?x:y;
}
inline ll queryMax(ll l,ll r)
{
	if(l>r)
	{
		return 0;
	}
	ll c=lg[r-l+1];
	return gmx(mx[l][c],mx[r-(1<<c)+1][c]);
}
inline ll queryMin(ll l,ll r)
{
	if(l>r)
	{
		return 0;
	}
	ll c=lg[r-l+1];
	return gmn(mn[l][c],mn[r-(1<<c)+1][c]);
}
inline ll query(ll l,ll r)
{
	ll x=queryMax(l,r),y=queryMin(l,r);
	ll xt=gmx(queryMax(l,x-1),queryMax(x+1,r));
	ll yt=gmn(queryMin(l,x-1),queryMin(x+1,r));
	return x!=y?u[x]-v[y]:max(u[xt]-v[y],u[x]-v[yt]);
}
int main()
{
	n=read(),m=read(),u[0]=-inf,v[0]=inf;
	for(register int i=1;i<=n;i++)
	{
		d[i%n+1]=d[i%n+n+1]=read();
	}	
	for(register int i=1;i<=n;i++)
	{
		h[i]=h[i+n]=read()<<1;
	}
	for(register int i=1;i<=2*n;i++)
	{
		sm+=d[i],u[i]=sm+h[i],v[i]=sm-h[i],mx[i][0]=mn[i][0]=i;
		lg[i]=(1<<c+1)==i?++c:c;
	}
	for(register int j=1;(1<<j)<=2*n;j++)
	{
		for(register int i=1;i+(1<<j)-1<=2*n;i++)
		{
			mx[i][j]=gmx(mx[i][j-1],mx[i+(1<<j-1)][j-1]);
			mn[i][j]=gmn(mn[i][j-1],mn[i+(1<<j-1)][j-1]);
		}
	}
	for(register int i=1;i<=m;i++)
	{
		l=read(),r=read(),l=l<=r?n+l-1:l-1;
		printf("%lld\n",query(r+1,l));
	}
}
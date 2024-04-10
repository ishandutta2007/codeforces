#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef double db;
const ll MAXN=2e5+51;
struct Point{
	ll x,y;
	inline bool operator <(const Point &rhs)const
	{
		return x==rhs.x?y<rhs.y:x<rhs.x;
	}
};
Point pt[MAXN];
ll n;
ll x[MAXN],prefix[MAXN],rr[MAXN];
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
inline ll dist(ll u,ll v)
{
	ll dx=pt[u].x-pt[v].x,dy=pt[u].y-pt[v].y;
	return dx*dx+dy*dy;
}
inline ll calc(ll l,ll r)
{
	ll res,mid,tot=0;
	db c;
	if(l+1>=r)
	{
		return l==r?1e18:dist(l,r);
	}
	mid=(l+r)>>1,res=min(calc(l,mid),calc(mid+1,r)),c=sqrt(1.0*res);
	for(register int i=l;i<=r;i++)
	{
		abs(pt[mid].x-pt[i].x)<=c?rr[++tot]=i:1;
	}
	sort(rr+1,rr+tot+1,[&](ll x,ll y){return pt[x].y<pt[y].y;});
	for(register int i=1;i<=tot;i++)
	{
		for(register int j=i+1;j<=tot&&pt[rr[j]].y-pt[rr[i]].y<=c;j++)
		{
			res=min(res,dist(rr[i],rr[j]));
		}
	}
	return res;
}
int main()
{
	n=read();
	for(register int i=1;i<=n;i++)
	{
		prefix[i]=prefix[i-1]+(x[i]=read()),pt[i]=(Point){i,prefix[i]};
	}
	sort(pt+1,pt+n+1),printf("%lld\n",calc(1,n));
}
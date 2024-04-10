#include<bits/stdc++.h>
#pragma GCC optimize("Ofast,unroll-loops")
using namespace std;
typedef int ll;
typedef long long int li;
typedef long double db;
const ll MAXN=2e5+51;
struct Query{
	ll x,y,id;
	inline bool operator <(const Query &rhs)const
	{
		return y<rhs.y;
	}
};
Query qry[MAXN];
ll n,m,x,y,tp,ptr,l,r,mid,rr;
ll c[MAXN],pr[MAXN],st[MAXN],res[MAXN];
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
inline db slope(ll u,ll v)
{
	return 1.0L*(pr[u]-pr[v]-1.0L*c[u]*u+1.0L*c[v]*v)/(c[u]-c[v]);
}
inline ll calc(ll x)
{
	ll l=1,r=tp,mid;
	while(l<r)
	{
		mid=(l+r)>>1;
		st[mid]<x?l=mid+1:r=mid;
	}
	return l;
}
int main()
{
	n=read();
	for(register int i=1;i<=n;i++)
	{
		pr[i]=pr[i-1]+(c[i]=read());
	}
	m=read();
	for(register int i=1;i<=m;i++)
	{
		x=read(),y=read(),qry[i]=(Query){x,y,i};
	}
	sort(qry+1,qry+m+1),ptr=1;
	for(register int i=1;i<=n;i++)
	{
		while(tp&&c[st[tp]]>=c[i])
		{
			tp--;
		}
		while(tp>1&&slope(st[tp],i)>=slope(st[tp-1],i))
		{
			tp--;
		}
		st[++tp]=i;
		while(qry[ptr].y==i&&ptr<=m)
		{
			x=qry[ptr].x,y=qry[ptr].y,l=calc(y-x),r=tp;
			while(l<r)
			{
				mid=(l+r)>>1;
				slope(st[mid],st[mid+1])<x-y?r=mid:l=mid+1;
			}
			l=st[l],r=qry[ptr].y,res[qry[ptr++].id]=pr[r]-pr[l]+(x-r+l)*c[l];
		}
	}
	for(register int i=1;i<=m;i++)
	{
		printf("%d\n",res[i]);
	}
}
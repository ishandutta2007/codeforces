#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51;
struct Item{
	ll op,l,r;
};
Item it[MAXN];
ll n,totd,rr,x,y;
ll dsc[MAXN],ffa[MAXN],l[MAXN],r[MAXN];
vector<ll>v[MAXN<<2];
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
inline ll find(ll x)
{
	return x==ffa[x]?x:ffa[x]=find(ffa[x]);
}
#define ls node<<1
#define rs (node<<1)|1
inline void query(ll l,ll r,ll pos,ll x,ll node)
{
	ll c;
	if(!v[node].empty())
	{
		for(register int i:v[node])
		{
			c=find(i),ffa[c]=x;
			::l[x]=min(::l[x],::l[c]),::r[x]=max(::r[x],::r[c]);
		}
		v[node].clear(),v[node].push_back(x);
	}
	if(l==r)
	{
		return;
	}
	ll mid=(l+r)>>1;
	pos<=mid?query(l,mid,pos,x,ls):query(mid+1,r,pos,x,rs);
}
inline void add(ll l,ll r,ll ql,ll qr,ll x,ll node)
{
	if(l==ql&&r==qr)
	{
		return v[node].push_back(x);
	}
	ll mid=(l+r)>>1;
	if(qr<=mid||ql>mid)
	{
		return qr<=mid?add(l,mid,ql,qr,x,ls):add(mid+1,r,ql,qr,x,rs);
	}
	add(l,mid,ql,mid,x,ls),add(mid+1,r,mid+1,qr,x,rs);
}
int main()
{
	n=read();
	for(register int i=1;i<=n;i++)
	{
		it[i].op=read(),it[i].l=read(),it[i].r=read();
		if(it[i].op==1)
		{
			dsc[++totd]=it[i].l,dsc[++totd]=it[i].r;
		}
	}
	sort(dsc+1,dsc+totd+1),totd=unique(dsc+1,dsc+totd+1)-dsc-1;
	for(register int i=1;i<=n;i++)
	{
		if(it[i].op==1)
		{
			it[i].l=lower_bound(dsc+1,dsc+totd+1,it[i].l)-dsc;
			it[i].r=lower_bound(dsc+1,dsc+totd+1,it[i].r)-dsc;
			rr++,ffa[rr]=rr,l[rr]=it[i].l,r[rr]=it[i].r;
			query(1,totd,it[i].l,rr,1),query(1,totd,it[i].r,rr,1);
			it[i].r-it[i].l>1?add(1,totd,it[i].l+1,it[i].r-1,rr,1):(void)1;
		}	
		if(it[i].op==2)
		{
			x=find(it[i].l),y=find(it[i].r);
			if((l[x]>l[y]&&l[x]<r[y])||(r[x]>l[y]&&r[x]<r[y])||x==y)
			{
				puts("YES");
				continue;
			}
			puts("NO");
		}
	}
}
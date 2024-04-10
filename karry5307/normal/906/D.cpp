#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51;
struct Item{
	ll x,flg;
};
struct BIT{
	ll x[MAXN];
	inline void add(ll pos,ll val);
	inline ll query(ll pos);
};
BIT bit;
unordered_map<ll,ll>mp;
ll n,qcnt,MOD,x,l,r;
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
inline Item qpow(ll base,ll exponent,ll MOD)
{
	ll res=1,flg=0;
	while(exponent)
	{
		if(exponent&1)
		{
			flg|=((li)res*base>=MOD),res=(li)res*base%MOD;
		}
		flg|=((li)base*base>=MOD),base=(li)base*base%MOD,exponent>>=1;
	}
	return (Item){res,flg};
}
inline void BIT::add(ll pos,ll val)
{
	for(;pos<=n;pos+=pos&-pos)
	{
		x[pos]+=val;
	}
}
inline ll BIT::query(ll pos)
{
	ll res=0;
	for(;pos;pos-=pos&-pos)
	{
		res+=x[pos];
	}
	return res;
}
inline ll phi(ll x)
{
	ll res=x;
	for(register int i=2;i<=sqrt(x);i++)
	{
		x%i==0?res=res/i*(i-1):1;
		while(x%i==0)
		{
			x/=i;
		}
	}
	return x!=1?res/x*(x-1):res;
}
inline Item query(ll l,ll r,ll p)
{
	Item it;
	ll x;
	if(p==1||l==r)
	{
		return p==1?(Item){0,1}:(x=bit.query(l),(Item){x%p,x>=p});
	}
	it=query(l+1,r,mp[p]),x=it.x+it.flg*mp[p];
	return qpow(bit.query(l),x,p);
}
int main()
{
	n=read(),x=MOD=read();
	while(x!=1)
	{
		x=(mp[x]=phi(x));
	}
	for(register int i=1;i<=n;i++)
	{
		x=read(),bit.add(i,x),bit.add(i+1,-x);
	}
	qcnt=read();
	for(register int i=1;i<=qcnt;i++)
	{
		l=read(),r=read(),printf("%d\n",query(l,r,MOD).x);
	}
}
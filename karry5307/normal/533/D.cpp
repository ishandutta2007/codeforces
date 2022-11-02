#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=1e5+51;
struct BIT{
	ll x[MAXN];
	inline void add(ll pos,ll val);
	inline ll query(ll pos);
};
BIT bit;
ll n,tp,res,totd,r;
ll x[MAXN],d[MAXN],st[MAXN],f[MAXN],g[MAXN];
li dsc[MAXN];
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
inline void BIT::add(ll pos,ll val)
{
	for(;pos<=totd;pos+=pos&-pos)
	{
		x[pos]=min(x[pos],val);
	}
}
inline ll BIT::query(ll pos)
{
	ll res=0x3f3f3f3f;
	for(;pos;pos-=pos&-pos)
	{
		res=min(res,x[pos]);
	}
	return res;
}
int main()
{
	n=read(),memset(bit.x,0x3f,sizeof(bit.x));
	for(register int i=0;i<=n+1;i++)
	{
		x[i]=read();
	}
	for(register int i=1;i<=n;i++)
	{
		d[i]=read();
	}
	for(register int i=1;i<=n;i++)
	{
		while(tp&&x[i]>(li)2*d[st[tp]]+x[f[st[tp]]])
		{
			tp--;
		}
		f[i]=st[tp];
		while(tp&&(li)2*d[i]+x[f[i]]>=(li)2*d[st[tp]]+x[f[st[tp]]])
		{
			tp--;
		}
		st[++tp]=i;
	}
	st[tp=0]=n+1,res=x[n+1];
	for(register int i=n;i;i--)
	{
		while(tp&&x[i]<x[g[st[tp]]]-(li)2*d[st[tp]])
		{
			tp--;
		}
		g[i]=st[tp];
		while(tp&&x[g[i]]-(li)2*d[i]<=x[g[st[tp]]]-(li)2*d[st[tp]])
		{
			tp--;
		}
		st[++tp]=i;
	}
	for(register int i=1;i<=n;i++)
	{
		if(x[g[i]]-x[f[i]]<=2*d[i])
		{
			return puts("0"),0;
		}
	}
	for(register int i=1;i<=n;i++)
	{
		res=min(res,x[g[i]]-x[f[i]]);
		x[g[i]]-x[i]<(li)2*d[i]?dsc[++totd]=x[g[i]]-(li)2*d[i]:1;
		f[i]==0&&x[g[i]]-x[i]<(li)2*d[i]?res=min(res,x[i]):1;
		g[i]==n+1&&x[i]-x[f[i]]<(li)2*d[i]?res=min(res,x[n+1]-x[i]):1;
	}
	sort(dsc+1,dsc+totd+1),totd=unique(dsc+1,dsc+totd+1)-dsc-1;
	for(register int i=n;i;i--)
	{
		if(x[i]-x[f[i]]<(li)2*d[i])
		{
			r=upper_bound(dsc+1,dsc+totd+1,x[f[i]]+(li)2*d[i])-dsc-1;
			if((r=bit.query(r))!=0x3f3f3f3f)
			{
				res=min(res,r-x[i]);
			}
		}
		if(x[g[i]]-x[i]<(li)2*d[i])
		{
			r=lower_bound(dsc+1,dsc+totd+1,x[g[i]]-(li)2*d[i])-dsc;
			bit.add(r,x[i]);
		}
	}
	printf("%.1lf\n",res*0.5);
}
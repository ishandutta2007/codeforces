#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e5+51;
ll n,m,MOD,u,v,totd,prod;
ll ffa[MAXN],bel[MAXN],sz[MAXN];
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
inline ll qpow(ll base,ll exponent)
{
    ll res=1;
    while(exponent)
    {
        if(exponent&1)
        {
            res=(li)res*base%MOD;
        }
        base=(li)base*base%MOD,exponent>>=1;
    }
    return res;
}
inline ll find(ll x)
{
	return x==ffa[x]?x:ffa[x]=find(ffa[x]);
}
int main()
{
	n=read(),m=read(),MOD=read(),prod=1;
	for(register int i=1;i<=n;i++)
	{
		ffa[i]=i;
	}
	for(register int i=1;i<=m;i++)
	{
		u=find(read()),v=find(read()),u!=v?ffa[v]=u:1;
	}
	for(register int i=1;i<=n;i++)
	{
		find(i)==i?bel[i]=++totd:1;
	}
	if(totd==1)
	{
		return puts(MOD==1?"0":"1"),0;
	}
	for(register int i=1;i<=n;i++)
	{
		sz[bel[find(i)]]++;
	}
	for(register int i=1;i<=totd;i++)
	{
		prod=(li)prod*sz[i]%MOD;
	}
	printf("%d\n",(li)prod*qpow(n,totd-2)%MOD);
}
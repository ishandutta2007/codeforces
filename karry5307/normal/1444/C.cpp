#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
typedef pair<ll,ll> pii;
const ll MAXN=5e5+51;
struct DSU{
	ll ffa[MAXN*2];
	inline ll find(ll x);
	inline ll check(ll x);
	inline ll merge(ll x,ll y);
};
DSU d[2];
map<pii,ll>mp;
ll n,m,kk,u,v,u2,v2,totd,idx,r;
li res;
pii pr;
ll col[MAXN],g[MAXN];
pii id[MAXN];
vector<pii>vg[MAXN];
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
// 1~n color black n+1~2n color white
inline ll DSU::find(ll x)
{
	return x==ffa[x]?x:ffa[x]=find(ffa[x]);
}
inline ll DSU::check(ll x)
{
	return find(x)==find(x+n);
}
inline ll DSU::merge(ll u,ll v)
{
	ffa[find(v+n)]=find(u),ffa[find(v)]=find(u+n);
}
int main()
{
	n=read(),m=read(),r=kk=read();
	for(register int i=1;i<=n;i++)
	{
		col[i]=read(),d[0].ffa[i]=i,d[0].ffa[i+n]=i+n;
	}
	for(register int i=1;i<=m;i++)
	{
		u=read(),v=read(),col[u]>col[v]?swap(u,v):(void)1;
		pr=(pii){col[u],col[v]};
		mp.find(pr)==mp.end()?id[mp[pr]=++totd]=pr,1:1;
		vg[mp[pr]].push_back({u,v});
	}
	for(register int i=1;i<=n;i++)
	{
		if(mp.find({i,i})!=mp.end())
		{
			idx=mp[{i,i}];
			for(auto j:vg[idx])
			{
				tie(u,v)=j,d[0].merge(u,v);
				if(d[0].check(u)||d[0].check(v))
				{
					r--,g[i]=1;
					break;
				}
			}	
		}
	}
	res=(li)r*(r-1)/2;
	for(register int i=1;i<=totd;i++)
	{
		tie(u,v)=id[i];
		if(u!=v&&!g[u]&&!g[v])
		{
			for(auto j:vg[i])
			{
				tie(u,v)=j;
				d[1].ffa[u]=d[0].find(u),d[1].ffa[u+n]=d[0].find(u+n);
				d[1].ffa[v]=d[0].find(v),d[1].ffa[v+n]=d[0].find(v+n);
				u2=d[0].find(u),d[1].ffa[u2]=u2;
				v2=d[0].find(v),d[1].ffa[v2]=v2;
				u2=d[0].find(u+n),d[1].ffa[u2]=u2;
				v2=d[0].find(v+n),d[1].ffa[v2]=v2;
			}
			for(auto j:vg[i])
			{
				tie(u,v)=j,d[1].merge(u,v);
				if(d[1].check(u)||d[1].check(v))
				{
					res--;
					break;
				}
			}
		}
	}
	printf("%lld\n",res);
}
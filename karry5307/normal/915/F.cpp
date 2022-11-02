#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=1e6+51;
struct Edge{
	ll from,to,mn,mx;
	inline bool operator <(const Edge &rhs)const
	{
		return mn>rhs.mn;
	}
	inline bool operator >(const Edge &rhs)const
	{
		return mx<rhs.mx;
	}
};
Edge ed[MAXN];
ll n,from,to;
li mx,mn;
ll x[MAXN],ffa[MAXN],sz[MAXN];
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
inline void merge(ll x,ll y)
{
	ll fx=find(x),fy=find(y);
	fx!=fy?ffa[fy]=fx,sz[fx]+=sz[fy],sz[fy]=0:1;
}
int main()
{
	n=read();
	for(register int i=1;i<=n;i++)
	{
		x[i]=read(),ffa[i]=i,sz[i]=1;
	}
	for(register int i=1;i<n;i++)
	{
		from=read(),to=read();
		ed[i]=(Edge){from,to,min(x[from],x[to]),max(x[from],x[to])};
	}
	sort(ed+1,ed+n);
	for(register int i=1;i<n;i++)
	{
		mn+=(li)sz[find(ed[i].from)]*sz[find(ed[i].to)]*ed[i].mn;
		merge(ed[i].from,ed[i].to);
	}
	sort(ed+1,ed+n,greater<Edge>());
	for(register int i=1;i<=n;i++)
	{
		ffa[i]=i,sz[i]=1;
	}
	for(register int i=1;i<n;i++)
	{
		mx+=(li)sz[find(ed[i].from)]*sz[find(ed[i].to)]*ed[i].mx;
		merge(ed[i].from,ed[i].to);
	}
	printf("%lld\n",mx-mn);
}
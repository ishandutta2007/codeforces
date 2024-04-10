#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll MAXN=2e5+51;
struct Edge{
	ll to,prev,dist,v;
};
struct Tuple{
	ll x,y,v;
	inline bool operator <(const Tuple &rhs)const
	{
		return this->v>rhs.v;
	}
};
Edge ed[MAXN<<1];
multiset<Tuple>st;
Tuple tp;
ll test,n,s,cur,res,p,tot,from,to,dist;
ll last[MAXN],fa[MAXN],sz[MAXN],deg[MAXN];
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
inline void addEdge(ll from,ll to,ll dist)
{
	ed[++tot].prev=last[from];
	ed[tot].to=to;
	ed[tot].dist=dist;
	last[from]=tot;
}
inline void dfs(ll node,ll f)
{
	fa[node]=f,sz[node]=(deg[node]==1);
	for(register int i=last[node];i;i=ed[i].prev)
	{
		if(ed[i].to!=f)
		{
			dfs(ed[i].to,node),sz[node]+=(ed[i].v=sz[ed[i].to]);
		}
	}
}
inline Tuple get(ll x,ll y)
{
	return Tuple{x,y,(x-x/2)*y};
}
inline void solve()
{
	n=read(),s=read(),cur=res=0;
	for(register int i=0;i<n-1;i++)
	{
		deg[from=read()]++,deg[to=read()]++,dist=read();
		addEdge(from,to,dist),addEdge(to,from,dist);
	}
	dfs(1,0),st.clear();
	for(register int i=1;i<=tot;i+=2)
	{
		p=ed[i].v?i:i+1;
		st.insert(get(ed[p].dist,ed[p].v)),cur+=ed[p].dist*ed[p].v;
	}
	while(1)
	{
		if(cur<=s)
		{
			break;
		}
		tp=*st.begin(),st.erase(st.begin()),res++;
		cur-=tp.v,st.insert(get(tp.x/2,tp.y));
	}
	printf("%lld\n",res),memset(last,0,sizeof(last)),tot=0;
	memset(deg,0,sizeof(deg));
}
int main()
{
	test=read();
	for(register int i=0;i<test;i++)
	{
		solve();
	}
}
#include<bits/stdc++.h>
using namespace std;
typedef int ll;
typedef long long int li;
const ll MAXN=2e3+51;
struct Edge{
	ll u,v,w;
	inline bool operator <(const Edge &rhs)const
	{
		return w>rhs.w;
	}
};
Edge ed[MAXN*MAXN/2];
ll test,n,m,tot,u,v,blk;
ll ffa[MAXN];
char ch[MAXN];
bitset<MAXN>bs[MAXN];
vector<ll>vg[MAXN];
vector<Edge>v2;
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
inline void solve()
{
	n=read(),m=read(),tot=0,v2.clear();
	for(register int i=1;i<=n;i++)
	{
		vg[i].clear(),bs[i].reset(),ffa[i]=i;
	}
	for(register int i=1;i<=m;i++)
	{
		scanf("%s",ch+1);
		for(register int j=1;j<=n;j++)
		{
			ch[j]&1?bs[j].set(i),1:1;
		}
	}
	for(register int i=1;i<=n;i++)
	{
		for(register int j=i+1;j<=n;j++)
		{
			ed[++tot]=(Edge){i,j,(bs[i]&bs[j]).count()};
		}
	}
	sort(ed+1,ed+tot+1);
	for(register int i=1;i<=tot;i++)
	{
		if(find(u=ed[i].u)!=find(v=ed[i].v))
		{
			ffa[find(v)]=find(u),vg[u].push_back(v),vg[v].push_back(u);
			v2.push_back({u,v});
		}
	}
	for(register int i=1;i<=m;i++)
	{
		blk=0;
		for(register int j=1;j<=n;j++)
		{
			ffa[j]=bs[j][i]?j:0;
		}
		for(auto j:v2)
		{
			if(bs[j.u][i]&&bs[j.v][i])
			{
				ffa[find(j.v)]=find(j.u);
			}
		}
		for(register int j=1;j<=n;j++)
		{
			ffa[j]?blk+=(find(j)==j):1;
		}
		if(blk!=1)
		{
			return (void)puts("NO");
		}
	}
	puts("YES");
	for(auto i:v2)
	{
		printf("%d %d\n",i.u,i.v);
	}
}
int main()
{
    test=read();
    for(register int i=0;i<test;i++)
    {
    	solve();
	}
}
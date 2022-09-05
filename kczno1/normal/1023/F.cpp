#include<bits/stdc++.h>
using namespace std;

typedef long long s64;
typedef pair<int,int> pii;
#define rep(i,l,r) for(int i=l;i<=r;++i)
const int N=5e5+5;
namespace BING
{
int fa[N];
int find(int x)
{
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
};
namespace TREE
{
vector<pii>lk[N];
int fa[N],deep[N],sz[N],son[N],top[N];
void add_e(int x,int y,int w)
{
	lk[x].push_back({y,w});
	lk[y].push_back({x,w});
}
void dfs(int x,int fr,int dep)
{
	fa[x]=fr;deep[x]=dep;
	sz[x]=1;
	for(auto e:lk[x])
	{
		int y=e.first;
		if(y==fr)continue;
		BING::fa[y]=e.second?x:y;
		dfs(y,x,dep+1);
		sz[x]+=sz[y];
		if(sz[y]>sz[son[x]])son[x]=y;
	}
}
void init(int n)
{
	BING::fa[1]=1;
	dfs(1,0,0);
	rep(x,1,n)
	if(x!=son[fa[x]])
	for(int y=x;y;y=son[y])top[y]=x;
}
int get_lca(int x,int y)
{
	while(top[x]!=top[y])
	if(deep[top[x]]>deep[top[y]])x=fa[top[x]];
	else y=fa[top[y]];
	return deep[x]<deep[y]?x:y;
}
};
s64 ans;int cnt;
void mark(int x,int to,int w)
{
	while(x=BING::find(x),TREE::deep[x]>TREE::deep[to])
	{
		++cnt;
		ans+=w;
		BING::fa[x]=TREE::fa[x];
	}
}
int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);
#endif
	int n,k,m;
	cin>>n>>k>>m;
	rep(i,1,n)BING::fa[i]=i;
	rep(i,1,k)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		TREE::add_e(x,y,0);
		BING::fa[BING::find(x)]=BING::find(y);
	}
	vector<pair<pii,int> >vec_e;
	rep(i,1,m)
	{
		int x,y,w;
		scanf("%d%d%d",&x,&y,&w);
		if(BING::find(x)==BING::find(y))
		{
			vec_e.push_back({{x,y},w});
		}
		else
		{
			BING::fa[BING::find(x)]=BING::find(y);
			TREE::add_e(x,y,1);
		}
	}
	TREE::init(n);
	for(auto e:vec_e)
	{
		int x=e.first.first,y=e.first.second,w=e.second;
		int lca=TREE::get_lca(x,y);
		mark(x,lca,w);
		mark(y,lca,w);
	}
	if(cnt<k)puts("-1");
	else printf("%lld\n",ans);
}
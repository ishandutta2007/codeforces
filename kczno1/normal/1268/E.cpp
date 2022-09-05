#include<bits/stdc++.h>
using namespace std;

template <typename T> void chmin(T&x,const T &y)
{
	if(x>y)x=y;
}
template <typename T> void chmax(T &x,const T &y)
{
	if(x<y)x=y;
}
typedef int64_t s64;
typedef uint64_t u64;
typedef uint32_t u32;
typedef pair<int,int> pii;
#define rep(i,l,r) for(int i=l;i<=r;++i)
#define per(i,r,l) for(int i=r;i>=l;--i)
#define rep0(i,l,r) for(int i=l;i<r;++i)
#define gc (c=getchar())
int read()
{
	char c;
	while(gc<'-');
	if(c=='-')
	{
		int x=gc-'0';
		while(gc>='0')x=x*10+c-'0';
		return -x;
	}
	int x=c-'0';
	while(gc>='0')x=x*10+c-'0';
	return x;
}
#undef gc

const int N=5e5+5;
vector<pii>lk[N];
pii edge[N];int to_edge[N],offset[N];
int dfn[N],low[N],tot,fa[N],w_to_fa[N],dp[N];

void tarjan(int x)
{
	//cerr<<x<<endl; 
	dfn[x]=low[x]=++tot;
	for(auto e:lk[x])
	{
		int y,w;
		tie(y,w)=e;
		if(y==fa[x])continue;
		if(!dfn[y])
		{
			fa[y]=x;w_to_fa[y]=w;
			tarjan(y);
			chmin(low[x],low[y]);
		}
		else chmin(low[x],dfn[y]);
	}
	for(auto e:lk[x])
	{
		int y,w;
		tie(y,w)=e;
		if(low[y]>=dfn[x]&&fa[y]!=x)
		{
			vector<int>e;
			e.push_back(w);
			for(int z=y;/*cerr<<z<<endl,*/z!=x;z=fa[z])e.push_back(w_to_fa[z]);
			rotate(e.begin(),min_element(e.begin(),e.end()),e.end());
			int p=0;
			while(p+1<e.size()&&e[p+1]>e[p])++p;
			int i=p;
			while(i+1<e.size()&&e[i+1]<e[i])++i;
			if(i+1==e.size())to_edge[e[p]]=e[0];
		}
	}
}

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
#endif
	int n,m;
	cin>>n>>m;
	rep(i,1,m)
	{
		int x=read(),y=read();
		edge[i]=pii(x,y);
		lk[x].push_back(pii(y,i));
		lk[y].push_back(pii(x,i));
	}
	tarjan(1);
	rep(i,1,n)dp[i]=1;
	per(i,m,1)
	{
		int x,y;
		tie(x,y)=edge[i];
		int sum=dp[x]+dp[y]-offset[i];
		dp[x]=dp[y]=sum;
		offset[to_edge[i]]=sum;
	}
	rep(i,1,n)printf("%d ",dp[i]-1);
}
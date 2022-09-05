//#pragma GCC target("avx,avx2")	
#include<bits/stdc++.h>
//#include<immintrin.h>
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
char readc()
{
	char c;
	while(isspace(gc));
	return c;
}
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

const int N=3e5+5,T=N*100;
struct Node
{
	int cl,cr;u64 tag;
}node[T];int node_cnt,rt[N];
int n,a[N];
vector<int> a_lk[N],lk[N];u64 b[N];
int fa[N],dep[N],sz[N],son[N],top[N],dfn[N];
void dfs(int x,int fr)
{
	static int tot;
	dfn[x]=++tot;
	dep[x]=dep[fr]+1;
	sz[x]=1;
	fa[x]=fr;
	for(auto y:lk[x])
	if(y!=fr)
	{
		dfs(y,x);
		if(sz[y]>sz[son[x]])son[x]=y;
		sz[x]+=sz[y];
	}
}
int get_lca(int x,int y)
{
	while(top[x]!=top[y])
	if(dep[top[x]]>dep[top[y]])x=fa[top[x]];
	else y=fa[top[y]];
	return dep[x]<dep[y]?x:y;
}

int ql,qr;u64 x;
#define mid ((l+r)/2)
void add_dfs(int &k,int l,int r)
{
	int rt=++node_cnt;
	node[rt]=node[k];
	if(ql<=l&&qr>=r)node[rt].tag^=x;
	else 
	{
		if(ql<=mid)add_dfs(node[rt].cl,l,mid);
		if(qr>mid)add_dfs(node[rt].cr,mid+1,r);
	}
	k=rt;
}
void add(int &k,int l,int r,u64 _x)
{
	ql=l;qr=r;x=_x;
	add_dfs(k,1,n);
}
u64 query(int k,int x)
{
	int l=1,r=n;
	u64 ans=0;
	while(1)
	{
		ans^=node[k].tag;
		if(l==r)break;
		if(x<=mid){k=node[k].cl;r=mid;}
		else {k=node[k].cr;l=mid+1;}
	}
	return ans;
}

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
#endif
	int m;
	cin>>n>>m;
	mt19937 rng(/*time(0)*/0);
	rep(i,1,n)
	{
		a_lk[a[i]=read()].push_back(i);
		b[i]=((u64)rng()<<32)^rng();
	}
	rep(i,1,n-1)
	{
		int x=read(),y=read();
		lk[x].push_back(y);
		lk[y].push_back(x);
	}
	dfs(1,0);
	rep(x,1,n)
	if(x!=son[fa[x]])
		for(int y=x;y;y=son[y])top[y]=x;
	rep(i,1,n)
	{
		rt[i]=rt[i-1];
		for(auto x:a_lk[i])add(rt[i],dfn[x],dfn[x]+sz[x]-1,b[i]);
	}
	while(m--)
	{
		int x=read(),y=read(),l=read(),r=read();
		int a_lca=a[get_lca(x,y)];
		u64 br=query(rt[r],dfn[x])^query(rt[r],dfn[y]);
		u64 bl=query(rt[l-1],dfn[x])^query(rt[l-1],dfn[y]);
		if(a_lca<=r)br^=b[a_lca];
		if(a_lca<l)bl^=b[a_lca];
		if(bl==br)puts("-1");
		else 
		{
			while(l<r)
			{
				bl=query(rt[mid],dfn[x])^query(rt[mid],dfn[y]);
				if(a_lca<=mid)bl^=b[a_lca];
				if(bl==br)r=mid;
				else l=mid+1;
			}
			printf("%d\n",l);
		}	
	}
}
 
/* stuff you should look for
	* int overflow, array bounds, uppercase/lowercase 
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/
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

const int N=2e5+5;
vector<int>lk[N];
int fa[N],sz[N],dep[N],son[N],top[N],dfn[N],q[N];

void dfs1(int x,int fr)
{
	fa[x]=fr;sz[x]=1;dep[x]=dep[fr]+1;
	for(auto y:lk[x])
	if(y!=fr)
	{
		dfs1(y,x);
		sz[x]+=sz[y];
		if(sz[y]>sz[son[x]])son[x]=y;
	}
}
void dfs2(int x,int ntop)
{
	static int tot=0;
	dfn[x]=++tot;q[tot]=x;
	top[x]=ntop;
	if(!son[x])return ;
	dfs2(son[x],ntop);
	for(auto y:lk[x])
	if(y!=fa[x]&&y!=son[x])dfs2(y,y);
}
int jump(int x,int d)
{
	if(dep[x]<=d)return 1;
	while(dep[x]-dep[top[x]]<d)
	{
		d-=dep[x]-dep[top[x]]+1;
		x=fa[top[x]];
	}
	return q[dfn[x]-d];
}
int get_lca(int x,int y)
{
	while (top[x]!=top[y])
	if(dep[top[x]]>dep[top[y]])x=fa[top[x]];
	else y=fa[top[y]];
	return dep[x]<dep[y]?x:y;
}
int get_dis(int x,int y)
{
	if(!(x&&y))return -1;
	return dep[x]+dep[y]-2*dep[get_lca(x,y)];
}

struct BIT
{
	int n,c[N];
	void add(int i,int w)
	{
		for(;i<=n;i+=i&-i)c[i]+=w;
	}
	int query_pre(int i)
	{
		int ans=0;
		for(;i;i-=i&-i)ans+=c[i];
		return ans;
	}
	int query(int l,int r)
	{
		return query_pre(r)-query_pre(l-1);
	}
}bit;

namespace SegmentTree
{
struct Tri
{
	int x,y,d;
	Tri ()
	{
		x=y=0;d=-1;
	}
	Tri (int _x,int _y)
	{
		x=_x;y=_y;
		d=get_dis(x,y);
	}
};
bool operator <(const Tri &a,const Tri &b) 
{
	return a.d<b.d;
}
Tri operator +(const Tri &a,const Tri &b)
{
	return max({a,b,Tri(a.x,b.y),Tri(a.x,b.x),Tri(a.y,b.x),Tri(a.y,b.y)});
}
Tri a[N*3];int n,d;
void init(int _n)
{
	n=_n;
	for(d=1;d<n+2;d<<=1);
}
Tri query_diameter(int l,int r)
{
	Tri ans;
	l+=d-1;r+=d+1;
	while(l+1<r)
	{
		if(l%2==0)ans=ans+a[l+1];
		if(r%2)ans=ans+a[r-1];
		l>>=1;r>>=1;
	}
	return ans;
}
int cnt[N];
void add(int x,int w)
{
	int i=dfn[x]+d;
	cnt[x]+=w;
	a[i]=cnt[x]?Tri(x,x):Tri(0,0);
	while(i>>=1)a[i]=a[i*2]+a[i*2+1];
}
};

template <typename T>
struct Heap
{
priority_queue<T> a,b;
void push(const T &x){a.push(x);}
void erase(const T &x){b.push(x);}
T top()
{
	while(!b.empty() && a.top()==b.top()){a.pop();b.pop();}
	return a.top();
}
int size()
{
	return a.size()-b.size();
}
};

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
#endif
	int n=read(),m=read();
	bit.n=n;SegmentTree::init(n);
	rep(i,1,n-1)
	{
		int x=read(),y=read();
		lk[x].push_back(y);
		lk[y].push_back(x);
	}
	dfs1(1,0);
	dfs2(1,1);
	Heap<pii> heap;
	while(m--)
	{
		int op=read();
		if(op==3)
		{
			int d=read();
			int v=jump(heap.top().second,d);
			int v1=jump(v,d);
			if(bit.query(dfn[v1],dfn[v1]+sz[v1]-1) < heap.size())
			{
				puts("No");
				continue;
			}
			auto diameter=SegmentTree::query_diameter(dfn[v1],dfn[v1]+sz[v1]-1);
			if(get_dis(v,diameter.x)>d || get_dis(v,diameter.y)>d)
				puts("No");
			else 	
				puts("Yes");
		}
		else 
		{
			int x=read(),y=read();
			int w=op==1?1:-1;
			int lca=get_lca(x,y);
			bit.add(dfn[x],w);bit.add(dfn[y],w);bit.add(dfn[lca],-w);
			SegmentTree::add(lca,w);
			pii pr=pii(dep[lca],lca);
			if(w==1)heap.push(pr);
			else heap.erase(pr);
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
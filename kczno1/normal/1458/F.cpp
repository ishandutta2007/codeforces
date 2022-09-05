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

namespace BIT
{
int n,c0[N];s64 c1[N];
void add_suf(int x,int w)
{
	for(int i=x;i<=n;i+=i&-i)
	{
		c0[i]+=w;
		c1[i]+=w*x;
	}
}
void add(int l,int r,int w)
{
	add_suf(l,w);
	add_suf(r+1,-w);
}
s64 query_pre(int x)
{
	int s0=0;s64 s1=0;
	for(int i=x;i;i-=i&-i)
	{
		s0+=c0[i];s1+=c1[i];
	}
	return s64(s0)*(x+1)-s1;
}
s64 query(int l,int r)
{
	return query_pre(r)-query_pre(l-1);
}
};

void dfs1(int x,int fr)
{
	sz[x]=1;fa[x]=fr;dep[x]=dep[fr]+1;
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
	dfn[x]=++tot;
	q[tot]=x;
	top[x]=ntop;
	if(!son[x])return ;
	dfs2(son[x],ntop);
	for(auto y:lk[x])
	if(y!=fa[x]&&y!=son[x])dfs2(y,y);
}

int get_lca(int x,int y)
{
	while(top[x]!=top[y])
	if(dep[top[x]]>dep[top[y]])x=fa[top[x]];
	else y=fa[top[y]];
	return dep[x]<dep[y]?x:y;
}
int dis(int x,int y)
{
	return dep[x]+dep[y]-dep[get_lca(x,y)]*2;
}
bool contain(pii a,pii b)
{
	return dis(b.first,a.first)<=a.second-b.second;
}
int jump(int x,int d)
{
	while(dep[x]-dep[top[x]]+1<=d)
	{
		d-=dep[x]-dep[top[x]]+1;
		x=fa[top[x]];
	}
	return q[dfn[x]-d];
}
int move_to(int x,int y,int d)
{
	int lca=get_lca(x,y);
	if(dep[x]-d>=dep[lca])return jump(x,d);
	return jump(y,dep[x]+dep[y]-2*dep[lca]-d);
}
pii merge(pii a,pii b)
{
	if(contain(a,b))return a;
	if(contain(b,a))return b;
	int r1=(a.second+b.second+dis(a.first,b.first))/2;
	return {move_to(a.first,b.first,r1-a.second),r1};
}
void add_to_rt(int x,int w)
{
	while(x)
	{
		BIT::add(dfn[top[x]],dfn[x],w);
		x=fa[top[x]];
	}
}
s64 query_to_rt(int x)
{
	s64 ans=0;
	while(x)
	{
		ans+=BIT::query(dfn[top[x]],dfn[x]);
		x=fa[top[x]];
	}
	return ans;
}
s64 work(int l,int r)
{
	if(l>=r)return 0;
	int m=(l+r)/2;
	static pii c[N];
	c[m+1]={m+1,0};
	rep(i,m+2,r)
		c[i]=merge(c[i-1],{i,0});
	c[m]={m,0};
	per(i,m-1,l)
		c[i]=merge(c[i+1],{i,0});
	static s64 sum_dep[N],sum_r[N];
	sum_dep[m]=sum_r[m]=0;
	rep(i,m+1,r)
	{
		sum_dep[i]=sum_dep[i-1]+dep[c[i].first];
		sum_r[i]=sum_r[i-1]+c[i].second;
	}

	s64 ans=0;
	int l1=m+1,r1=m;
	per(i,m,l)
	{
		while(l1<=r&&contain(c[i],c[l1]))
		{
			add_to_rt(c[l1].first,-1);
			++l1;
		}
		while(r1<l1-1||(r1<r&&!contain(c[r1+1],c[i])))
		{
			++r1;
			add_to_rt(c[r1].first,1);
		}
		ans+=(s64)c[i].second*(l1-(m+1))+sum_r[r]-sum_r[r1];

		if(l1<=r1)
			ans+=((s64)(r1-l1+1)*dep[c[i].first]+sum_dep[r1]-sum_dep[l1-1]-2*query_to_rt(c[i].first)
				+sum_r[r1]-sum_r[l1-1]+(s64)c[i].second*(r1-l1+1))/2;
	}
	rep(i,l1,r1)add_to_rt(c[i].first,-1);
	return ans+work(l,m)+work(m+1,r);
}

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
#endif
	int n=read();
	rep(i,1,n-1)
	{
		int x=read(),y=read();
		auto add_e=[&](int x,int y)
		{
			lk[x].push_back(y);
			lk[y].push_back(x);
		};
		add_e(x,n+i);
		add_e(y,n+i);
	}
	BIT::n=2*n-1;
	dfs1(1,0);		
	dfs2(1,1);

	cout<<work(1,n)<<endl;
}
 
/* stuff you should look for
	* int overflow, array bounds, uppercase/lowercase 
	* special cases (n=1?)
	* do smth instead of nothing and stay organized
	* WRITE STUFF DOWN
	* DON'T GET STUCK ON ONE APPROACH
*/
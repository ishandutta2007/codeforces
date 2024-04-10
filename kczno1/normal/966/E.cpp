#pragma GCC target("avx,avx2")	
#include<bits/stdc++.h>
#include<immintrin.h>
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

const int N=1e5+5;
vector<int>lk[N];
int n,fa[N],deep[N],sz[N],son[N],top[N],dfn[N];
namespace ARR
{
__m256i _zero,_ans,_w,_a[N/8+5];
int *a=(int*)_a;
void init()
{
	rep(i,1,n)a[dfn[i]]=read()+1;
}
void add(int l,int r,int w)
{
	for(;l%8&&l<=r;++l)a[l]+=w;
	for(;(r+1)%8&&l<=r;--r)a[r]+=w;
	if(l>r)return ;
	l/=8;r/=8;
	_w=_mm256_set_epi32(w,w,w,w,w,w,w,w);
	for(;l<=r;++l)_a[l]=_mm256_add_epi32(_a[l],_w);
}
int query(int l,int r)
{
	int ans=0;
	for(;l%8&&l<=r;++l)ans+=a[l]>0;
	for(;(r+1)%8&&l<=r;--r)ans+=a[r]>0;
	if(l>r)return ans;
	l/=8;r/=8;
	_zero=_mm256_setzero_si256(),_ans=_mm256_setzero_si256();
	for(;l<=r;++l)_ans=_mm256_add_epi32(_ans,_mm256_cmpgt_epi32(_a[l],_zero));
	rep(i,0,7)ans-=((int*)(&_ans))[i];
	return ans;
}
};
void dfs1(int x,int fr,int dep)
{
	fa[x]=fr;deep[x]=dep;sz[x]=1;
	for(auto y:lk[x])
	if(y!=fr)
	{
		dfs1(y,x,dep+1);
		sz[x]+=sz[y];
		if(sz[y]>sz[son[x]])son[x]=y;
	}
}
void dfs2(int x)
{
	static int tot=0;
	top[x]=(x==son[fa[x]])?top[fa[x]]:x;
	dfn[x]=++tot;
	if(!son[x])return ;
	dfs2(son[x]);
	for(auto y:lk[x])
	if(y!=fa[x]&&y!=son[x])dfs2(y);
}

#define fx top[x]
#define fy top[y]
void add(int x,int y,int w)
{
	while(fx!=fy)
	{
		if(deep[fx]<deep[fy])swap(x,y);
		ARR::add(dfn[fx],dfn[x],w);
		x=fa[fx];
	}
	if(deep[x]<deep[y])swap(x,y);
	ARR::add(dfn[y],dfn[x],w);
}
int query(int x,int y)
{
	int ans=0;
	while(fx!=fy)
	{
		if(deep[fx]<deep[fy])swap(x,y);
		ans+=ARR::query(dfn[fx],dfn[x]);
		x=fa[fx];
	}
	if(deep[x]<deep[y])swap(x,y);
	return ans+ARR::query(dfn[y],dfn[x]);
}
int query(int x)
{
	return ARR::query(dfn[x],dfn[x]+sz[x]-1);
}

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);
#endif
	n=read(); 
	int m=read();
	rep(i,1,n-1)
	{
		int x=i+1,y=read();
		lk[x].push_back(y);
		lk[y].push_back(x); 
	}
	dfs1(1,0,1);
	dfs2(1);
	ARR::init();
	rep(query_id,1,m)
	{
		int x=read(),w=1;
		if(x<0){x=-x;w=-w;}
		add(x,x,N*w);
		add(x,1,-w);
		printf("%d%c",n-query(1)," \n"[query_id==m]);
	}
}
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

const int N=4e5+5,M=3e5+5,Q=5e5+5;
int p[N],fa[N];
int find(int x)
{
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
pii e[M];bool mark[M];
struct Query
{
	int ty,v;
}query[Q];
namespace TREE
{
int lk[N][2],n,dfn[N],en[N];
int tot;
void dfs(int x)
{
	if(!lk[x][0])
	{
		dfn[x]=en[x]=++tot;
		return ;
	}
	dfn[x]=tot+1;
	rep(i,0,1)dfs(lk[x][i]);
	en[x]=tot;
}
void init()
{
	rep(i,1,n)
	if(fa[i]==i)dfs(i);
}
};
namespace SEG
{
int mx[N*3],n,d;
void init(int _n)
{
	n=_n;
	for(d=1;d<n;d<<=1);--d;
	rep(i,1,n)mx[d+TREE::dfn[i]]=p[i];
	per(i,(n+d)/2,1)mx[i]=max(mx[i*2],mx[i*2+1]);
}
int query(int l,int r)
{
	l+=d;r+=d;
	int ans=l;
	if(l<r)		
	{
		auto C=[&](int x)
		{
			if(mx[x]>mx[ans])ans=x;
		};
		C(r);
		while(l+1!=r)
		{
			if(l%2==0)C(l+1);
			if(r%2)C(r-1);
			l>>=1;r>>=1;
		}
		while(ans<=d)ans=mx[ans*2]==mx[ans]?ans*2:ans*2+1;
	}
	int tmp=mx[ans];
	mx[ans]=0;
	for(int i=ans;i>>=1;)mx[i]=max(mx[i*2],mx[i*2+1]);
	return tmp;
}
};

void merge(const pii &e)
{
	int x=find(e.first),y=find(e.second);
	if(x!=y)
	{
		fa[x]=fa[y]=++TREE::n;
		TREE::lk[TREE::n][0]=x;
		TREE::lk[TREE::n][1]=y;
	}
}

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
#endif
	int n,m,q;
	cin>>n>>m>>q;
	rep(i,1,n)p[i]=read();
	rep(i,1,m)e[i]=pii(read(),read());
	rep(i,1,n*2)fa[i]=i;
	rep(i,1,q)
	{
		query[i].ty=read();
		query[i].v=read();
		if(query[i].ty==2)mark[query[i].v]=1;
	}
	TREE::n=n;
	rep(i,1,m)
	if(!mark[i])
		merge(e[i]);
	per(i,q,1)
	{
		if(query[i].ty==1)query[i].v=find(query[i].v);
		else merge(e[query[i].v]);
	}
	TREE::init();
	SEG::init(n);
	rep(i,1,q)
	if(query[i].ty==1)
	{
		int v=query[i].v;
		printf("%d\n",SEG::query(TREE::dfn[v],TREE::en[v]));
	}
}
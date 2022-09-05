//by kcz 1552920354@qq.com
//if you find any bug in my code
//please tell me
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
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned short us;
typedef unsigned int ui;
typedef long double ld;
#define rep(i,l,r) for(int i=l;i<=r;++i)
#define per(i,r,l) for(int i=r;i>=l;--i)
#define pb push_back
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
struct point
{
	ll x,y;
	ll qiu(const ll &k)
	{
		return k*x+y;
	}
};
ld operator *(const point &p1,const point &p2)
{
	return (ld)p1.x*p2.y-(ld)p2.x*p1.y;
}
point operator -(const point &p1,const point &p2)
{
	return (point){p1.x-p2.x,p1.y-p2.y};
}
const int T=1e7+5,N=1e5+5,L=20;
const ll inf=1e18;
point tq[T],*tot=tq;
void New(point* &a,int n)
{
	a=tot;
	tot+=n;
}
int a[N],b[N];ll dp[N];
struct TU
{
point *q;int n;
void init(const point &p)
{
	New(q,1);
	n=1;
	*q=p;
}
void push(const point &p)
{
	while(n>=1&&q[n-1].x==p.x&&q[n-1].y>p.y)--n;
	while(n>=2&&(q[n-1]-q[n-2])*(p-q[n-2])<0)--n;
	if(!(n>=1&&q[n-1].x==p.x&&q[n-1].y<=p.y))q[n++]=p;
}
ll qiu(const ll &k)
{
	if(n<5)
	{
		ll ans=inf;
		rep(i,0,n-1)chmin(ans,q[i].qiu(k));
		return ans;
	}
	int l=0,r=n-1;
	while(l!=r)
	{
		int mid=l+r>>1;
		if(q[mid].qiu(k)<q[mid+1].qiu(k))r=mid;
		else l=mid+1;
	}
	return q[l].qiu(k);
}
};
TU merge(TU a,TU b)
{
	TU ans;
	ans.n=0;
	New(ans.q,a.n+b.n);

	int h1=0,h2=0;
	while(h1<a.n||h2<b.n)
	if(h1<a.n&&(h2==b.n||a.q[h1].x<b.q[h2].x))ans.push(a.q[h1++]);
	else ans.push(b.q[h2++]);
	return ans;
}
struct F
{
TU a[L];int sz[L],top;
void add(const point &p)
{
	++top;
	sz[top]=1;
	a[top].init(p);
	while(sz[top]==sz[top-1])
	{
		a[top-1]=merge(a[top-1],a[top]);
		sz[top-1]*=2;
		--top;
	}
}
ll qiu(const ll &k)
{
	ll ans=inf;	
	rep(i,1,top)chmin(ans,a[i].qiu(k));
	return ans;
}
};
F f1;
int n;
vector<int>lk[N];
namespace TREE
{
int dfn[N],q[N],tot;
int sz[N],son[N];
void dfs(int x,int fr)
{
	++tot;
	dfn[x]=tot;
	q[tot]=x;
	sz[x]=1;
	for(vector<int>::iterator it=lk[x].begin();it!=lk[x].end();++it)
	{
		int y=*it;
		if(y==fr)continue;
		dfs(y,x);
		sz[x]+=sz[y];
		if(sz[y]>sz[son[x]])son[x]=y;
	}
}
void add(int x)
{
	f1.add((point){b[x],dp[x]});
}
void dfs2(int x,int fr)
{
	if(son[x])
	{
		for(vector<int>::iterator it=lk[x].begin();it!=lk[x].end();++it)
		{
			int y=*it;
			if(y==fr||y==son[x])continue;
			dfs2(y,x);
			f1.top=0;::tot=tq;
		}
		dfs2(son[x],x);
		rep(i,dfn[x]+1,dfn[son[x]]-1)add(q[i]);
		rep(i,dfn[son[x]]+sz[son[x]],dfn[x]+sz[x]-1)add(q[i]);
		dp[x]=f1.qiu(a[x]);
	}
	add(x);
}
};

int main()
{
//	freopen("1.in","r",stdin);freopen("1.out","w",stdout);
	cin>>n;
	rep(i,1,n)scanf("%d",a+i);
	rep(i,1,n)scanf("%d",b+i);
	rep(i,1,n-1)
	{
		int x,y;
		scanf("%d%d",&x,&y);
		lk[x].pb(y);lk[y].pb(x);
	}
	TREE::dfs(1,0);
	TREE::dfs2(1,0);
	rep(i,1,n)printf("%I64d ",dp[i]);
}
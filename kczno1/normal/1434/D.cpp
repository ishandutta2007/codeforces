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

const int N=1e6+5;
pair<int,bool> tmp_dep_col[N];
struct Seg
{
struct Node
{
	int MX[2],LM[2],MR[2],M,LMR;
	bool rev;
	void init(int x,bool c)
	{
		MX[c]=x;LM[c]=MR[c]=-x;
		MX[c^1]=LM[c^1]=MR[c^1]=-1e9;
		M=-2*x;
		LMR=rev=0;
	}
	void rever()
	{
		rev^=1;
		swap(MX[0],MX[1]);
		swap(LM[0],LM[1]);
		swap(MR[0],MR[1]);
	}
};	
Node a[N*4];int n;
#define cl (k*2)
#define cr (cl+1) 
#define mid ((l+r)/2)
void push_up(int k)
{
	a[k].LMR=max(a[cl].LMR,a[cr].LMR);
	rep(i,0,1)
	{
		a[k].MX[i]=max(a[cl].MX[i],a[cr].MX[i]);
		a[k].LM[i]=max({a[cl].LM[i],a[cr].LM[i],a[cl].MX[i]+a[cr].M});
		a[k].MR[i]=max({a[cl].MR[i],a[cr].MR[i],a[cr].MX[i]+a[cl].M});
		chmax(a[k].LMR,max(a[cl].LM[i]+a[cr].MX[i],a[cl].MX[i]+a[cr].MR[i]));
	}
	a[k].M=max(a[cl].M,a[cr].M);
	if(a[k].rev)
	{
		swap(a[k].MX[0],a[k].MX[1]);
		swap(a[k].LM[0],a[k].LM[1]);
		swap(a[k].MR[0],a[k].MR[1]);
	}
}
void init(int k,int l,int r)
{
	if(l==r)
	{
		a[k].init(tmp_dep_col[l].first,tmp_dep_col[l].second);
	}
	else 
	{
		init(cl,l,mid);
		init(cr,mid+1,r);
		push_up(k);
	}
}
void init(int _n)
{
	init(1,1,n=_n);
}
int ql,qr;
void rever_dfs(int k,int l,int r)
{
	if(ql<=l&&qr>=r)
	{
		a[k].rever();
		return ;
	}
	if(ql>r||qr<l)return ;
	rever_dfs(cl,l,mid);
	rever_dfs(cr,mid+1,r);
	push_up(k);
}
void rever(int l,int r)
{
	ql=l;qr=r;
	rever_dfs(1,1,n);
}
}seg;

vector<pii>lk[N];

int dfn[N],tot,en[N],dep[N];bool col[N];
void dfs(int x,int fr)
{
	dfn[x]=++tot;
	dep[x]=dep[fr]+1;
	tmp_dep_col[tot]={dep[x],col[x]};
	for(auto e:lk[x])
	if(e.first!=fr)
	{
		col[e.first]=col[x]^e.second;
		dfs(e.first,x);
		tmp_dep_col[++tot]={dep[x],col[x]};
	}
	en[x]=tot;
}

void rever(int x)
{
	seg.rever(dfn[x],en[x]);
}

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
#endif
	int n=read();
	static int u[N],v[N];
	rep(i,1,n-1)
	{
		u[i]=read();v[i]=read();int t=read();
		lk[u[i]].push_back({v[i],t});
		lk[v[i]].push_back({u[i],t});
	}

	dfs(1,0);
	seg.init(tot);

#ifdef kcz
	printf("%d\n",seg.a[1].LMR);
#endif
	int m=read();
	while(m--)
	{
		int i=read();
		rever(dfn[v[i]]<dfn[u[i]]?u[i]:v[i]);
		printf("%d\n",seg.a[1].LMR);
	}
}
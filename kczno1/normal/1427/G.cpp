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

const int N=200+5,U=N*N;
int a[N][N];

namespace FLOW
{
const int N=::N*::N;
struct Edge
{
	int to,f,rev;
};
vector<Edge>lk[N];
int n,S,T;
void add_e(int x,int y,int f,int nf)
{
	lk[x].push_back({y,f,lk[y].size()});
	lk[y].push_back({x,nf,lk[x].size()-1});
}
int g[N],nh[N];
bool bfs()
{
	rep(i,1,n)g[i]=N;
	deque<int>q;
	q.push_back(T);g[T]=0;
	while(!q.empty())
	{
		int x=q.front();q.pop_front();
		if(x==S)return 1;
		for(auto e:lk[x])
		if(lk[e.to][e.rev].f&&g[e.to]==N)
		{
			g[e.to]=g[x]+1;
			q.push_back(e.to);
		}
	}
	return 0;
}
int dfs(int x,int f)
{
	if(x==T)return f;
	int f0=f;
	for(;nh[x]<lk[x].size();++nh[x])
	{
		auto &e=lk[x][nh[x]];
		if(e.f&&g[e.to]==g[x]-1)
		{
			int del=dfs(e.to,min(f,e.f));
			f-=del;e.f-=del;lk[e.to][e.rev].f+=del;
			if(!f)break;
		}
	}
	return f0-f;
}
int max_flow()
{
	int ans=0;
	while(bfs())
	{
		rep(i,1,n)nh[i]=0;
		ans+=dfs(S,2e9);
		//cout<<ans<<endl;
	}
	return ans;
}
};

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
#endif
	int n;
	cin>>n;
	auto dy_id=[&](int i,int j)->int
	{
		return (i-1)*n+j;
	};
	FLOW::T=FLOW::n=n*n+2;
	FLOW::S=n*n+1;
	vector<pii>b;
	rep(i,1,n)
	rep(j,1,n)
	{
		a[i][j]=read();
		if(a[i][j]>0)
		{
			b.push_back(pii(a[i][j],dy_id(i,j)));
			FLOW::add_e(dy_id(i,j),FLOW::T,U,0);
		}
		if(a[i][j]!=-1)
		{
			if(i>1&&a[i-1][j]!=-1)FLOW::add_e(dy_id(i,j),dy_id(i-1,j),1,1);
			if(j>1&&a[i][j-1]!=-1)FLOW::add_e(dy_id(i,j),dy_id(i,j-1),1,1);
		}
	}	
	sort(b.begin(),b.end());
	int sz=b.size();
	s64 ans=0;
	int max_flow=0;
	rep(i,0,sz-2)
	{
		//cerr<<"i="<<i<<endl;
		FLOW::add_e(FLOW::S,b[i].second,2*U,0);
		max_flow+=FLOW::max_flow()-U;
		ans+=1LL*(b[i+1].first-b[i].first)*max_flow;
	}
	cout<<ans<<endl;
}
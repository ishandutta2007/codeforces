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

const int N=1e4+5;
namespace FLOW
{
const int N=::N*2;
struct Edge
{
	int to,f,rev;
};
vector<Edge>lk[N];
void add_e(int x,int y,int f)
{
	lk[x].push_back({y,f,lk[y].size()});
	lk[y].push_back({x,0,lk[x].size()-1});
}
int n,S,T;
void init(int _n)
{
	n=T=_n*2+2;S=n-1;
	rep(i,1,n)lk[i].clear();
}
int g[N],nh[N];
bool bfs()
{
	rep(i,1,n)g[i]=N;
	g[T]=0;
	deque<int>q;q.push_back(T);
	while(!q.empty())
	{
		int x=q.front();q.pop_front();
		if(x==S)return 1;
		for(const auto &e:lk[x])
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
		ans+=dfs(S,n);
	}
	return ans;
}
};

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
#endif
	int n,m;
	cin>>n>>m;
	vector<pair<int,pii>>e(m);
	rep(i,0,m-1)
	{
		int u=read(),v=read(),d=read();
		e[i]={d,{u,v}};
	}
	sort(e.begin(),e.end());
	auto check=[&](int mid)
	{
		FLOW::init(n);
		rep(i,1,n){FLOW::add_e(FLOW::S,i,1);FLOW::add_e(n+i,FLOW::T,1);}
		rep(i,0,mid)
		{
			int u,v;
			tie(u,v)=e[i].second;
			//cerr<<u<<" "<<v<<endl;
			FLOW::add_e(u,n+v,1);
		}
		return FLOW::max_flow()==n;
	};	
	int l=-1,r=m;
	while(l+1!=r)
	{
		int mid=(l+r)/2;
		if(check(mid))r=mid;
		else l=mid;
	}
	if(r==m)puts("-1");
	else cout<<e[r].first<<endl;	
}
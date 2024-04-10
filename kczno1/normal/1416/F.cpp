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

const int dx[]={0,0,1,-1},dy[]={-1,1,0,0};
const char dy_char[]="LRDU";
const int N=1e5+10;

namespace FLOW
{
struct Edge
{
	int to,f,rev;
};
vector<Edge>lk[N];
int n,S0,T0,S,T;
void init(int _n)
{
	for(;n;--n)lk[n].clear();
	n=T=_n+4;S=_n+3;S0=_n+1;T0=_n+2;
}
void add_e(int x,int y,int f)
{
	lk[x].push_back({y,f,lk[y].size()});
	lk[y].push_back({x,0,lk[x].size()-1});
}
int g[N];
bool bfs()
{
	deque<int>q;
	rep(i,1,n)g[i]=N;
	g[T]=0;q.push_back(T);
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
int nh[N];
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
		ans+=dfs(S,N);
	}
	return ans;
}
};

vector<int>a[N],ans[N];
string s[N];
void work()
{
	int n=read(),m=read();
	rep(i,0,n-1)
	{
		a[i].resize(m);
		rep(j,0,m-1)a[i][j]=read();
		s[i].resize(m);
		ans[i].resize(m);
	}
	FLOW::init(n*m);
	int c0=0,c1=0;
	auto dy_id=[&](int x,int y)
	{
		return x*m+y+1;
	};
	rep(x,0,n-1)
	rep(y,0,m-1)
	{
		s[x][y]=0;
		rep(dir,0,3)
		{
			int x1=x+dx[dir],y1=y+dy[dir];
			if(x1<0||x1>=n||y1<0||y1>=m)continue;
			if(a[x1][y1]<a[x][y])
			{
				s[x][y]=dy_char[dir];
				ans[x][y]=a[x][y]-a[x1][y1];
			}
			if(!(x%2^y%2)&&a[x1][y1]==a[x][y])
				FLOW::add_e(dy_id(x,y),dy_id(x1,y1),1);
		}
		if(!s[x][y])
		{
			if(x%2^y%2)
			{
				++c1;
				FLOW::add_e(dy_id(x,y),FLOW::T,1);
			}
			else 
			{
				++c0;
				FLOW::add_e(FLOW::S,dy_id(x,y),1);
			}
		}
		else 
		{
			if(x%2^y%2)
				FLOW::add_e(dy_id(x,y),FLOW::T0,1);
			else 
				FLOW::add_e(FLOW::S0,dy_id(x,y),1);
		}
	}
	FLOW::add_e(FLOW::S0,FLOW::T,c0);
	FLOW::add_e(FLOW::S,FLOW::T0,c1);
	FLOW::add_e(FLOW::T0,FLOW::S0,N);
	if(FLOW::max_flow()<c0+c1){puts("NO");return ;}
	rep(x,0,n-1)
	rep(y,0,m-1)
	if(!(x%2^y%2))
	{
		int i=dy_id(x,y);
		for(auto e:FLOW::lk[i])
		if(!e.f)
		{
			int j=e.to;
			if(j>n*m)continue;
			int x1=(j-1)/m,y1=(j-1)%m;
			assert(a[x][y]==a[x1][y1]);
			rep(dir,0,3)
			if(x1==x+dx[dir]&&y1==y+dy[dir])
			{
				s[x][y]=dy_char[dir];
				s[x1][y1]=dy_char[dir^1];
				ans[x][y]=1;
				ans[x1][y1]=a[x][y]-ans[x][y];
			}
		}
	}
	puts("YES");
	rep(x,0,n-1)
	rep(y,0,m-1)printf("%d%c",ans[x][y]," \n"[y==m-1]);
	rep(x,0,n-1)
	rep(y,0,m-1)printf("%c%c",s[x][y]," \n"[y==m-1]);
}

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
#endif
	int tt;
	cin>>tt;
	while(tt--)
		work();
}
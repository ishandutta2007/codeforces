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
typedef long long s64;
typedef unsigned long long u64;
typedef unsigned int u32;
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

const int N=1e5+5,D=50+5;
int d;
vector<int>lk[N],scc[N];
char s[N][D];
int dp[N][D];
int dis[N],scc_g[N];
bool vis[N][D];

int dfn[N],low[N],tot;
int st[N],top;bool in_st[N];
int belong_scc[N],scc_cnt;//scc=strongly connected component= 

void push(int x,int d,int v)
{
	chmax(dp[belong_scc[x]][dis[x]==-1?0:(d-dis[x]+::d)%(::d)],v);
}

void dfs(int x)
{
	dfn[x]=low[x]=++tot;
	st[++top]=x;
	in_st[x]=1;
	
	for(auto y:lk[x])
	{
		if(!dfn[y])
		{
			dfs(y);
			if(low[x]>low[y])low[x]=low[y];
		}
		else
		{
			if(in_st[y])
			if(low[x]>low[y])low[x]=low[y];
            //low[y]dfn[y]low[x]
		}
	}
	
	if(low[x]==dfn[x])
	{
		++scc_cnt;
		while(1)
		{
			int y=st[top--];
			in_st[y]=0;
			belong_scc[y]=scc_cnt;
			if(y==x)break;
		}
	}
}

void work_scc(int b)
{
	deque<pii>q;
	auto push=[&](int x,int d)
	{
	if(!vis[x][d])
	{
		vis[x][d]=1;
		q.push_back({x,d});
	}
	};
	int x=scc[b].front();
	push(x,0);
	while(!q.empty())
	{
		pii p=q.front();q.pop_front();
		for(auto y:lk[p.first])
		if(belong_scc[y]==b)push(y,(p.second+1)%d);
	}
	for(auto x:scc[b])
	{
		int i=0;
		while(!vis[x][i])++i;
		dis[x]=i;
	}
	x=scc[b].front();
	int i=1;
	while(i<d&&!vis[x][i])++i;
	scc_g[b]=i;
}

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
#endif
	int n,m;
	cin>>n>>m>>d;
	rep(i,1,m)
	{
		int x=read(),y=read();
		lk[x].push_back(y);
	}
	rep(i,1,n)scanf("%s",s[i]); 
	
	dfs(1);
	
	rep(i,1,n)scc[belong_scc[i]].push_back(i);
	rep(i,1,n)dis[i]=-2;
	rep(i,1,scc_cnt)work_scc(i);
//	rep(i,1,n)cerr<<belong_scc[i]<<" "<<dis[i]<<endl;
	
	rep(i,1,n)
	rep(j,0,d-1)dp[i][j]=-N;
	push(1,0,0);
	per(i,scc_cnt,1)
	{
		int g=scc_g[i];
		rep(j,0,d-1)chmax(dp[i][j%g],dp[i][j]);
		rep(j,0,g-1)
		{
//			cerr<<dp[1][0]<<endl;
			for(auto x:scc[i])
			for(int k=j;k<d;k+=g)
			if(s[x][(k+dis[x])%d]=='1'){++dp[i][j];break;}
		}
		rep(j,0,d-1)chmax(dp[i][j],dp[i][j%g]);
			for(auto x:scc[i])
			for(auto y:lk[x])
			if(belong_scc[y]!=i)
			rep(j,0,d-1)
				push(y,j+dis[x]+1,dp[i][j]);
	}
	
	int ans=0;
	rep(i,1,n)
	rep(j,0,d-1)chmax(ans,dp[i][j]);
	cout<<ans<<endl;
}
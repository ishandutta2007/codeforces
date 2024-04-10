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

const int N=1500+5;
int n,w_dy_e[N*N/2],fa[N],cnt_e[N],sz[N];
vector<int>lk[N];
int find(int x)
{
	return x==fa[x]?x:fa[x]=find(fa[x]);
}
namespace TREE
{
const int N=::N*2,D=998244353;
int n;
vector<int>son[N];
int dp[N][::N],sz[N];
void dfs(int x)
{
	if(son[x].empty())
	{
		sz[x]=1;
		dp[x][1]=1;
		return ;
	}
	dp[x][0]=1;
	for(auto y:son[x])	
	{
		dfs(y);
		per(i,sz[x]+sz[y],0)
		{
			s64 sum=0;
			rep(j,max(0,i-sz[y]),min(i,sz[x]))(sum+=1LL*dp[x][j]*dp[y][i-j])%=D;
			dp[x][i]=sum;
		}
		sz[x]+=sz[y];
	}	
	dp[x][1]=1;
}
void work()
{
	dfs(n);
	rep(i,1,::n)printf("%d\n",dp[n][i]);
}
};

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
#endif
	cin>>n;
	rep(i,1,n)
	rep(j,1,n)
	{
		int w=read();
		if(j>i)w_dy_e[w]=i*N+j;
	}
	rep(i,1,n)
	{
		fa[i]=i;
		sz[i]=1;
		lk[i].push_back(i);
	}
	TREE::n=n;
	rep(w,1,n*(n-1)/2)
	{
		int x=w_dy_e[w];
		int y=x%N;x/=N;
		x=find(x);y=find(y);
		++cnt_e[x];
		if(x==y)
		{
			if(cnt_e[x]==sz[x]*(sz[x]-1)/2)
			{
				TREE::son[++TREE::n]=lk[x];
				lk[x].clear();
				lk[x].push_back(TREE::n);
			}
			continue;
		}
		fa[y]=x;cnt_e[x]+=cnt_e[y];sz[x]+=sz[y];
		for(auto z:lk[y])lk[x].push_back(z);
			if(cnt_e[x]==sz[x]*(sz[x]-1)/2)
			{
				TREE::son[++TREE::n]=lk[x];
				lk[x].clear();
				lk[x].push_back(TREE::n);
			}
	}
	TREE::work();
}
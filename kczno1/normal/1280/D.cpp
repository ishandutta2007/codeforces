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

const int N=3000+5;
int dp[N][N][2],ndp[2],m,sz[N],b[N];
s64 mx[N][N][2],nmx[2];
vector<int>lk[N];

void dfs(int x,int fr)
{
	sz[x]=1;
	dp[x][1][0]=dp[x][1][1]=-N;
	if(b[x]>0){dp[x][1][1]=1;mx[x][1][1]=b[x];}
	else{dp[x][1][0]=0;mx[x][1][0]=b[x];}
	for(auto y:lk[x])
	if(y!=fr)
	{
		dfs(y,x);
		rep(i,1,sz[y])dp[x][sz[x]+i][0]=dp[x][sz[x]+i][1]=-N;
		per(i,sz[x],1)
		{
			rep(dx,0,1)
			{
				ndp[dx]=dp[x][i][dx];dp[x][i][dx]=-N;
				nmx[dx]=mx[x][i][dx];
			}
			rep(j,1,sz[y])
			rep(dx,0,1)
			if(ndp[dx]>=0)
			rep(dy,0,1)
			{
				int now=ndp[dx]+dp[y][j][dy];
				if(now>dp[x][i+j][dx])
				{
					dp[x][i+j][dx]=now;
					mx[x][i+j][dx]=nmx[dx];
				}
				else
				if(now==dp[x][i+j][dx])
				{
					chmax(mx[x][i+j][dx],nmx[dx]);
				}
				now-=dx+dy;
				int d;
				if(nmx[dx]+mx[y][j][dy]>0)
				{
					d=1;
					++now;
				}
				else 
				{
					d=0;
				}
				if(now>dp[x][i+j-1][d])
				{
					dp[x][i+j-1][d]=now;
					mx[x][i+j-1][d]=nmx[dx]+mx[y][j][dy];
				}
				else
				if(now==dp[x][i+j-1][d])
				{
					chmax(mx[x][i+j-1][d],nmx[dx]+mx[y][j][dy]);
				}
			}
		}
		sz[x]+=sz[y];
	}
}

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
#endif
	int tt;
	cin>>tt;
	while(tt--)
	{
		int n=read();m=read();
		rep(i,1,n)b[i]=-read();
		rep(i,1,n)b[i]+=read();
		rep(i,1,n)lk[i].clear();
		rep(i,1,n-1)
		{
			int x=read(),y=read();
			lk[x].push_back(y);
			lk[y].push_back(x);
		}
		dfs(1,0);
		printf("%d\n",max(dp[1][m][0],dp[1][m][1]));
	}
}
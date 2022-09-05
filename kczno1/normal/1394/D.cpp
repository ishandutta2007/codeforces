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

const int N=2e5+5;
const s64 INF=1e12;
int n,t[N],h[N];
s64 dp[N][2];
vector<int>lk[N];
s64 a[N];

void dfs(int x,int fr)
{
	for(auto y:lk[x])
	if(y!=fr)
		dfs(y,x);
	int m=0;s64 base=0;
	for(auto y:lk[x])
	if(y!=fr)
	{
		++m;
		dp[y][0]+=t[x];
		dp[y][1]+=t[x];
		if(h[x]!=h[y])dp[y][h[x]>h[y]]=INF;
		base+=dp[y][0];
		a[m]=dp[y][1]-dp[y][0];
		//if(x==1)cerr<<y<<" "<<dp[y][0]<<" "<<dp[y][1]<<endl;
	}
	if(!m)
	{
		dp[x][0]=dp[x][1]=t[x];
		return ;
	}
	dp[x][0]=base;dp[x][1]=base+t[x];
	sort(a+1,a+m+1);
	rep(i,1,m)
	{
		base+=a[i];
		s64 now=base-1LL*min(i,m-i)*t[x];
		chmin(dp[x][0],now+t[x]);
		chmin(dp[x][1],now+t[x]);
		if(i!=m-i||x==1)chmin(dp[x][i>m-i],now);
	}
}

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
#endif
	cin>>n;
	rep(i,1,n)t[i]=read();
	rep(i,1,n)h[i]=read();
	rep(i,1,n-1)
	{
		int x=read(),y=read();
		lk[x].push_back(y);
		lk[y].push_back(x);
	}
	dfs(1,0);
	cout<<min(dp[1][0],dp[1][1]);
}
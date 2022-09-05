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

const int N=1e6+5;
s64 dp[N][2],f[N][2],a[N],sum1[N];

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);//freopen("1.out","w",stdout);
#endif
	int n;s64 r1,r2,r3,d;
	cin>>n>>r1>>r2>>r3>>d;
	rep(i,1,n)a[i]=read();
	rep(i,1,n)
	{
		f[i][1]=min(r2+r1,a[i]*r1+2*r1);
		f[i][0]=a[i]*r1+r3;
		chmin(f[i][1],f[i][0]);
		sum1[i]=sum1[i-1]+f[i][1];
	}
	dp[1][0]=f[1][0];
	dp[1][1]=f[1][1];
	rep(i,2,n)
	{
		dp[i][0]=min(f[i][1]+min(dp[i-1][0],dp[i-1][1])+3*d,f[i][0]+min(dp[i-1][0]+d,dp[i-1][1]+3*d));
		dp[i][1]=min(f[i][1]+min(dp[i-1][0]+d,dp[i-1][1]+3*d),f[i][0]+min(dp[i-1][0]+d,dp[i-1][1]+3*d));
	}
	s64 ans=dp[n][0];
	//cout<<ans<<endl;
	rep(i,1,n-2)
	{
		chmin(ans,dp[i][0]+d+(f[n][0]+sum1[n-1]-sum1[i])+(n-i-1)*d*2);
//		if(i==2)cerr<<dp[i][0]<<" "<<d<<" "<<(dp[n][0]+sum1[n-1]-sum1[i])+(n-i-1)*d*2<<endl;
		//cout<<ans<<endl;
	}
	cout<<ans<<endl;
}
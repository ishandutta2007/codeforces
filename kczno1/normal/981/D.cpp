#include<bits/stdc++.h>
using namespace std;

typedef long long s64;
#define rep(i,l,r) for(int i=l;i<=r;++i)
#define per(i,r,l) for(int i=r;i>=l;--i)
const int N=50+5;
bool dp[N][N];
s64 sum[N];
int n,k;

bool ok(s64 x)
{
	dp[0][0]=1;
	rep(c,1,k)
	rep(i,c,n)
	{
		dp[c][i]=0;
		rep(j,0,i-1)dp[c][i]|=dp[c-1][j]&&((sum[i]-sum[j]&x)==x);
	}
	return dp[k][n];
}

int main()
{
#ifdef kcz
	freopen("1.in","r",stdin);
#endif	
	cin>>n>>k;
	rep(i,1,n)scanf("%lld",sum+i);
	rep(i,1,n)sum[i]+=sum[i-1];
	s64 ans=0;
	per(i,60,0)
	if(ok(ans+(1LL<<i)))ans+=1LL<<i;
	cout<<ans;
}
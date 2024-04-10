#include<bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;
vector<int> pw2(1111111);
vector<vector<int>> C(2333,vector<int>(2333));
const int W=60;
int solve(int n,long long lim,long long z)
{
	vector<vector<int>> dp(64,vector<int>(n*2+10));
	dp[W][0]=1;
	long long ans=0;
	for(int b=W-1;b>=0;b--)
	{
		for(int i=0;i<=n;i++)
		{
			int L=min((long long)n,i*2+((lim>>b)&1));
			for(int j=((z>>b)&1);j<=L;j+=2)
			{
				dp[b][i*2+((lim>>b)&1)-j]=(dp[b][i*2+((lim>>b)&1)-j]+1ll*dp[b+1][i]*C[n][j])%MOD;
			}
		}
		for(int i=n+1;i<=n*2+5;i++)ans+=1ll*dp[b+1][i]*pw2[(b+1)*(n-1)]%MOD;
//		for(int i=0;i<=n;i++)cerr<<"dp "<<b<<' '<<i<<' '<<dp[b][i]<<endl;
	}
	for(int i=0;i<=n*2+5;i++)ans+=dp[0][i];
	return ans%MOD;
}
int main()
{
	pw2[0]=1;
	for(int i=1;i<=1000000;i++)
		pw2[i]=pw2[i-1]*2%MOD;
	C[0][0]=1;
	for(int i=1;i<=2000;i++)
	{
		C[i][0]=C[i][i]=1;
		for(int j=1;j<i;j++)
		{
			C[i][j]=(C[i-1][j]+C[i-1][j-1])%MOD;
		}
	}
	int n;
	long long l,r,z;
	cin>>n>>l>>r>>z;
	if(n==1)cout<<(l<=z and z<=r)<<endl;
	else cout<<(solve(n,r,z)-solve(n,l-1,z)+MOD)%MOD<<endl;
	return 0;
}
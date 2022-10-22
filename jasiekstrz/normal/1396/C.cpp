#include<bits/stdc++.h>
#define fi first
#define se second
using namespace std;
long long dp[1000010][2][2];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,a,i;
	long long r1,r2,r3,d;
	cin>>n>>r1>>r2>>r3>>d;
	cin>>a;
	dp[1][1][0]=r1*a+r3;
	dp[1][1][1]=2*d+min(r1*a+min(2*r1,r3),r2+r1);
	dp[1][0][1]=dp[1][1][1];
	dp[1][0][0]=dp[1][1][0];
	for(i=2;i<=n;i++)
	{
		cin>>a;
		//laduje na koncu
		dp[i][1][0]=min(dp[i-1][1][0],dp[i-1][1][1])+d+r1*a+r3;
		//cerr<<dp[i][1][0]<<"\n";
		dp[i][1][0]=min(dp[i][1][0],min(dp[i-1][1][0]+2*d,dp[i-1][1][1])+d+min(r1*a+min(2*r1,r3),r2+r1));
		dp[i][1][1]=min(dp[i-1][1][0],dp[i-1][1][1])+d+min(r1*a+min(2*r1,r3),r2+r1)+2*d;
		//gdziekolwiek
		dp[i][0][0]=min(dp[i-1][0][0]+2*d,dp[i-1][0][1])+r1*a+r3;
		dp[i][0][1]=min(dp[i][1][1],min(dp[i-1][0][0]+2*d,dp[i-1][0][1])+2*d+min(r1*a+min(2*r1,r3),r2+r1));
		dp[i][0][0]=min(dp[i][0][0],dp[i][1][0]);
		dp[i][0][0]=min(dp[i][0][0],min(dp[i-1][0][0]+2*d,dp[i-1][0][1])+2*d+min(r1*a+min(2*r1,r3),r2+r1));
		//cerr<<dp[i][1][0]<<" "<<dp[i][1][1]<<" "<<dp[i][0][0]<<" "<<dp[i][0][1]<<"\n";
	}
	cout<<dp[n][0][0]<<"\n";
	return 0;
}
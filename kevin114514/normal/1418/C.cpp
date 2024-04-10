#include<bits/stdc++.h>
using namespace std;
const int INF=998244353;
int type[200200];
int dp[200200][2];
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		for(int i=0;i<=n;i++)
			dp[i][0]=dp[i][1]=INF;
		dp[0][1]=0;
		for(int i=0;i<n;i++)
			cin>>type[i];
		for(int i=0;i<n;i++)
		{
			dp[i+1][1]=min(dp[i+1][1],dp[i][0]);
			dp[i+1][0]=min(dp[i+1][0],dp[i][1]+type[i]);
			if(i!=n-1)
			{
				dp[i+2][1]=min(dp[i+2][1],dp[i][0]);
				dp[i+2][0]=min(dp[i+2][0],dp[i][1]+type[i]+type[i+1]);
			}
		}
		cout<<min(dp[n][0],dp[n][1])<<endl;
	}
	return 0;
}
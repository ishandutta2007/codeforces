#include<bits/stdc++.h>
using namespace std;
int h[5010];
int l[5010];
int dp[5010][2510][2];
int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n,i,k;
	cin>>n;
	for(i=1;i<=n;i++)
		cin>>h[i];
	h[0]=1e9;
	for(i=1;i<=n;i++)
	{
		l[i]=l[i-1];
		if(i%2==1)
		{
			l[i]+=max(0,min(h[i-1],h[i-2]-1)-h[i]+1);
		}
		else
		{
			l[i]+=max(0,h[i]-h[i-1]+1);
			l[i-1]+=max(0,h[i]-h[i-1]+1);
		}
	}
	for(i=0;i<=n;i++)
		dp[i][0][1]=1e9;
	h[0]=0;
	h[n+1]=0;
	for(k=1;k<=(n+1)/2;k++)
	{
		dp[2*k-1][k][1]=l[2*k-1];
		dp[2*k-1][k][0]=1e9;
		for(i=2*k;i<=n;i++)
		{
			dp[i][k][0]=min(dp[i-1][k][0],dp[i-1][k][1]);
			dp[i][k][1]=max(0,h[i+1]-h[i]+1)+min(dp[i-2][k-1][0]+max(0,h[i-1]-h[i]+1),dp[i-2][k-1][1]+max(0,min(h[i-1],h[i-2]-1)-h[i]+1));
		}
		cout<<min(dp[n][k][0],dp[n][k][1])<<" ";
	}
	return 0;
}
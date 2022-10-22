#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 200005
#define inf 1e9
#define eps 1e-10
using namespace std;

inline int read()
{
	int x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

int dp[2][105][105],a[maxn];

int main()
{
	int n=read(),od,ev;
	if(n%2==0) od=n/2; else od=n/2+1;
	for(int i=1;i<=n;i++)
	{
		a[i]=read();
		if(a[i]%2==1) od--;
	}
	for(int i=0;i<=n;i++) for(int j=0;j<=n;j++) dp[0][i][j]=dp[1][i][j]=inf;
	dp[0][0][od]=dp[1][0][od]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=n;j++)
		if(a[i]==0)
		{
			dp[0][i][j]=min(dp[0][i-1][j],dp[1][i-1][j]+1);
			dp[1][i][j]=min(dp[1][i-1][j+1],dp[0][i-1][j+1]+1);
		}
		else
		{
			if(a[i]%2==0)
			{
				dp[0][i][j]=min(dp[0][i-1][j],dp[1][i-1][j]+1);
			}
			else
			{
				dp[1][i][j]=min(dp[1][i-1][j],dp[0][i-1][j]+1);
			}
		}
	}
	if(a[n]==0) cout<<min(dp[0][n][0],dp[1][n][0])<<endl;
	else if(a[n]%2==0) cout<<dp[0][n][0]<<endl;
	else cout<<dp[1][n][0]<<endl;
	return 0;
}
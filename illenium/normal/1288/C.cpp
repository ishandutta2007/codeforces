#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 200005
#define inf 1e9
#define eps 1e-10
#define p 1000000007
using namespace std;

inline int read()
{
	int x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

ll dp[15][1005],n,m,dp2[15][1005];

int main()
{
	cin>>m>>n;
	for(int i=1;i<=m;i++) dp[1][i]=1,dp2[1][i]=1;
	for(int i=2;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			for(int k=1;k<=j;k++)
				dp[i][j]=(dp[i][j]+dp[i-1][k])%p;
		}
	}
	for(int i=2;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			for(int k=m;k>=j;k--)
				dp2[i][j]=(dp2[i][j]+dp2[i-1][k])%p;
		}
	}
	ll ans=0;
	for(int i=1;i<=m;i++)
	{
		for(int j=i;j<=m;j++)
			ans=(ans+(dp[n][i]*dp2[n][j])%p)%p;
	}
	cout<<ans<<endl;
	return 0;
}
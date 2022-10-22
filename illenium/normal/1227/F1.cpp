#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<map>
#include<queue>
#include<cmath>
#include<stack>
#include<set>
#define ll long long
#define maxn 200005
#define re register
#define inf 1e9
#define eps 1e-10
#define modc 998244353 
using namespace std;

inline int read()
{
	int x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

int a[maxn],n,k;
ll dp[2005][4005],ans;

int main()
{
	n=read(); k=read();
	for(int i=1;i<=n;i++) a[i]=read();
	dp[0][2000]=1;
	for(int i=1;i<n;i++)
	{
		for(int j=1;j<=4000;j++)
		{
			if(a[i+1]!=a[i])
			{
				dp[i][j]=(dp[i][j]+(dp[i-1][j]*(k-2))%modc)%modc;
				dp[i][j]=(dp[i][j]+dp[i-1][j-1]+dp[i-1][j+1])%modc;
			}
			else dp[i][j]=(dp[i-1][j]*k)%modc;
		}
	}
	if(a[n]!=a[1])
	{
		for(int i=1;i<=4000;i++)
			dp[n][i]=(dp[n][i]+(dp[n-1][i]*(k-2))%modc)%modc,
			dp[n][i]=(dp[n][i]+dp[n-1][i-1]+dp[n-1][i+1])%modc;
	}
	else
	{
		for(int i=1;i<=4000;i++) dp[n][i]=(dp[n-1][i]*k)%modc;
	}
//	for(int i=1;i<=5;i++)
//	{
//		for(int j=1990;j<=2010;j++)
//			cout<<dp[i][j]<<" ";
//		cout<<endl;
//	}
	for(int i=1;i<=2000;i++) ans=(ans+dp[n][i+2000])%modc;
	cout<<ans<<endl;
	return 0;
}
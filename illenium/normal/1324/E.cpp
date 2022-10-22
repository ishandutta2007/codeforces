#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 1000005
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

int n,h,l,r,dp[2005][2005],a[maxn];

int main()
{
	n=read(); h=read(); l=read(); r=read();
	for(int i=1;i<=n;i++) a[i]=read();
	for(int i=0;i<=n;i++) for(int j=0;j<h;j++) dp[i][j]=-inf; dp[0][0]=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<h;j++)
		{
			int p1=j-a[i],p2=j-a[i]+1;
			if(p1<0) p1+=h; if(p2<0) p2+=h;
			dp[i][j]=max(dp[i-1][p1],dp[i-1][p2]);
			if(l<=j&&j<=r) dp[i][j]++;
		}
	}
	int ans=0;
	for(int i=0;i<h;i++) ans=max(ans,dp[n][i]);
	cout<<ans<<endl;
	return 0;
}
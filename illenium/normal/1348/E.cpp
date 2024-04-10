#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 505
#define inf 1e9
#define pb push_back
#define rep(i,a,b) for(int i=a;i<=b;i++)
#define per(i,a,b) for(int i=a;i>=b;i--)
using namespace std;

inline ll read()
{
	ll x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

ll n,K,a[maxn],b[maxn],dp[maxn][maxn],sa,sb;

int main()
{
	n=read(); K=read();
	rep(i,0,(n-1)) a[i]=read(),b[i]=read(),sa+=a[i],sb+=b[i];
	dp[0][0]=1;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<=K;j++)
		{
			if(j<=a[i]&&K-j<=b[i])
			{
				for(int k=0;k<=K;k++) if(dp[i][k])
					dp[i+1][(k+j)%K]=1;
			}
		}
		for(int j=0;j<=K;j++) dp[i+1][j]|=dp[i][j];
	}
	ll ans=sa/K+sb/K;
	for(int i=0;i<=K;i++)
	{
		if(dp[n][i]&&sb>=K-i) ans=max(ans,(sa-i)/K+(sb-K+i)/K+1);
	}
	cout<<ans<<endl;
	return 0;
}
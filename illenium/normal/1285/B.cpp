#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 200005
#define inf 1e9
#define eps 1e-10
using namespace std;

inline ll read()
{
	ll x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

ll a[maxn],tmp,dp[maxn],ans,dp2[maxn];

int main()
{
	int T=read();
	while(T--)
	{
		int n=read(); ans=0; tmp=0;
		for(int i=1;i<=n;i++) a[i]=read(),tmp+=a[i];
		for(int i=1;i<=n;i++) dp[i]=max(dp[i-1],(ll)0)+a[i];
		for(int i=1;i<=n-1;i++) ans=max(dp[i],ans);
		for(int i=2;i<=n;i++) dp2[i]=max(dp2[i-1],(ll)0)+a[i];
		for(int i=2;i<=n;i++) ans=max(dp2[i],ans);
		if(tmp>ans) puts("YES");
		else puts("NO");
		for(int i=1;i<=n;i++) dp[i]=0,dp2[i]=0;
	}
	return 0;
}
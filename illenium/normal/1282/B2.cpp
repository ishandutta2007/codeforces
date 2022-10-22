#pragma GCC optimize(2)
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
using namespace std;

inline ll read()
{
	ll x=0,w=1; char c=getchar();
	while(c<'0'||c>'9') {if(c=='-') w=-1; c=getchar();}
	while(c<='9'&&c>='0') {x=(x<<1)+(x<<3)+c-'0'; c=getchar();}
	return w==1?x:-x;
}

ll a[maxn],s[maxn],dp[maxn];

int main()
{
	int T=read();
	while(T--)
	{
		ll n=read(),q=read(),k=read();
		for(int i=1;i<=n;i++) a[i]=read(),dp[i]=inf;
		sort(a+1,a+n+1);
		for(int i=1;i<=n;i++)
		{
			dp[i]=min(dp[i],dp[i-1]+a[i]);
			if(i>=k) dp[i]=min(dp[i],dp[i-k]+a[i]);
		}
		int ans=0;
		for(int i=1;i<=n;i++) if(dp[i]<=q) ans=max(ans,i);
		cout<<ans<<endl;
	}
	return 0;
}
#pragma GCC optimize(2)
#include<bits/stdc++.h>
#define ll long long
#define maxn 1000005
#define inf 1e18
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

ll n,r1,r2,r3,d,a[maxn],dp[maxn],tot,t[maxn];

int main()
{
	n=read(); r1=read(); r2=read(); r3=read(); d=read();
	rep(i,1,n) a[i]=read(),dp[i]=inf;
	dp[1]=r1*a[1]+r3; dp[0]=-d;
	rep(i,2,n)
	{
		ll p=min(r1+r2+3*d,r1*a[i]+r3+d);
		p=min(p,r1*a[i]+2*r1+3*d);
		dp[i]=min(dp[i],dp[i-1]+p);
		
		ll p1=min(4*d+2*(r1+r2),r1*(a[i]+3)+r2+4*d);
		ll p2=min(r1*(a[i-1]+a[i])+4*(r1+d),r1*(a[i-1]+3)+r2+4*d);
		dp[i]=min(dp[i],dp[i-2]+min(p1,p2));
	}
	ll ans=dp[n-2]+3*d+r1*a[n]+r3;
	ll p3=min(r1+r2,r1*(a[n-1]+2)); ans+=p3;
	ans=min(ans,dp[n]);
	printf("%lld\n",ans);
	return 0;
}
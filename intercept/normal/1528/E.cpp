#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
const int M=1e6+9;
int n;
int dp[M],p[M],dp2[M];
int kpow(int x,int y,int rex=1){
	for(;y;y>>=1,x=1ll*x*x%mod)if(y&1)rex=1ll*rex*x%mod;
	return rex;
}
int c2(int x){
	return 1ll*x*(x+1)/2%mod;
}
int c3(int x){
	return 1ll*x*(x+1)%mod*(x+2)%mod*kpow(6,mod-2)%mod;
}
int main(){
	scanf("%d",&n);
	dp[0]=p[0]=1;
	for(int i=1;i<=n+1;++i){
		dp[i]=((dp[i-1]+c2(dp[i-1]))%mod+1ll*dp[i-1]*p[i-2]%mod)%mod;
		p[i]=(p[i-1]+dp[i])%mod;
		dp2[i]=(dp[i]-dp[i-1]+mod)%mod;
	}
	int ans=(1ll*dp[n]+1ll*dp[n-1]*c2(p[n-2])%mod+1ll*c2(dp[n-1])*p[n-2]%mod+c3(dp[n-1]))%mod;
	ans=2ll*ans%mod-1;
	for(int i=1;i<n;++i){
		ans=(ans+1ll*(dp[i]-1)*(dp2[n-i-1])%mod)%mod;
	}
	printf("%d\n",ans);
	return 0;
}
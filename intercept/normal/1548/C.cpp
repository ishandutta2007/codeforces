#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
const int M=3e6+9;
int n,q,inv3=333333336;
int fac[M],inv[M],dp[M][3];
int c(int x,int y){
	if(x<y)return 0;
	return 1ll*fac[x]*inv[y]%mod*inv[x-y]%mod;
}
int main(){
	scanf("%d%d",&n,&q);
	fac[0]=inv[0]=inv[1]=1;
	for(int i=1;i<M;++i)fac[i]=1ll*i*fac[i-1]%mod;
	for(int i=2;i<M;++i)inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
	for(int i=2;i<M;++i)inv[i]=1ll*inv[i]*inv[i-1]%mod;
	dp[0][0]=dp[0][1]=dp[0][2]=n;
	for(int i=1;i<=n*3;++i){
		int s=c(n*3,i+1);
		dp[i][0]=1ll*inv3*((1ll*s-2ll*dp[i-1][0]-dp[i-1][1])%mod+mod)%mod;
		dp[i][1]=dp[i][0]+dp[i-1][0];
		dp[i][2]=dp[i][1]+dp[i-1][1];
	}
	for(int i=1,x;i<=q;++i){
		scanf("%d",&x);
		printf("%d\n",(dp[x][0]+c(n*3,x))%mod);
	}
	return 0;
}
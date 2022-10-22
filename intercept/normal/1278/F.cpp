#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
const int M=5009;
int n,m,k,ans;
int dp[M];
int kpow(int x,int y,int rex=1){
	for(;y;y>>=1,x=1ll*x*x%mod)if(y&1)rex=1ll*rex*x%mod;
	return rex;
}

int main(){
	scanf("%d%d%d",&n,&m,&k);
	dp[1]=n;
	int invm=kpow(m,mod-2);
	for(int i=2;i<=k;++i){
		for(int j=i;j>=1;--j){
			dp[j]=1ll*dp[j]*j%mod;
			if(j>1)dp[j]=(dp[j]+1ll*dp[j-1]*(n-j+1)%mod)%mod;
		}
	}
	for(int i=1;i<=k;++i)dp[i]=1ll*dp[i]*kpow(invm,i)%mod;
	for(int i=1;i<=k;++i)ans=(ans+dp[i])%mod;
	printf("%d\n",ans);
	return 0;
}
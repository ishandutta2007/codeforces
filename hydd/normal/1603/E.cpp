#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int n,Mod,x;
ll fac[210],inv[210];
int dp[210][210][210];
int solve(int i,int j,int k){
	if (!i) return (k?0:(!j?0:inv[j]));
	if (j>x+i-1) return 0;
	if (~dp[i][j][k]) return dp[i][j][k];
	int res=0;
	for (int t=0;t<=j&&i*t<=k;t++)
		res=(res+solve(i-1,j-t,k-i*t)*inv[t])%Mod;
	dp[i][j][k]=res; return res;
}
int main(){
	scanf("%d%d",&n,&Mod);
	fac[0]=1; for (int i=1;i<=n;i++) fac[i]=fac[i-1]*i%Mod;
	inv[1]=1; for (int i=2;i<=n;i++) inv[i]=(Mod-Mod/i)*inv[Mod%i]%Mod;
	inv[0]=1; for (int i=1;i<=n;i++) inv[i]=inv[i-1]*inv[i]%Mod;
	int ans=0;
	for (x=max(1,n-17);x<=n+1;x++){
		memset(dp,-1,sizeof(dp));
		for (int k=0;k<=x;k++) ans=(ans+solve(n+1-x,n,k))%Mod;
	}
	printf("%lld\n",ans*fac[n]%Mod);
	return 0;
}
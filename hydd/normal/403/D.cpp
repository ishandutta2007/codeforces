#include<cstdio>
using namespace std;
typedef long long ll;
const int Mod=1e9+7;
int t,n,k;
ll dp[2100][2100],fac[2100],inv[2100];
ll C(int n,int m){
	if (n<m) return 0;
	if (n==m) return 1;
	return fac[n]*inv[m]%Mod*inv[n-m]%Mod;
}
inline void ADD(ll &x,ll y){
	x+=y; if (x>=Mod) x-=Mod;
}
int main(){
	dp[0][1]=1;
	for (int i=0;i<=1000;i++)
		for (int j=1;j<=1000;j++){
			ADD(dp[i+j][j],dp[i][j]);
			ADD(dp[i+j][j+1],dp[i][j]);
		}
	fac[0]=1; for (int i=1;i<=1000;i++) fac[i]=fac[i-1]*i%Mod;
	inv[1]=1; for (int i=2;i<=1000;i++) inv[i]=(Mod-Mod/i)*inv[Mod%i]%Mod;
	inv[0]=1; for (int i=1;i<=1000;i++) inv[i]=inv[i-1]*inv[i]%Mod;
	scanf("%d",&t);
	while (t--){
		scanf("%d%d",&n,&k); ll ans=0;
		for (int i=0;i<=n;i++)
			ADD(ans,dp[i][k]*fac[k]%Mod*C(n-i,k)%Mod);
		printf("%lld\n",ans);
	}	
	return 0;
}
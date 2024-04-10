#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int Mod=1e9+7;
int n,m,k,lim;
ll ans,fac[1100000],inv[1100000],dp[1100000];
ll qpow(ll x,int a){
	ll res=1;
	while (a){
		if (a&1) res=res*x%Mod;
		x=x*x%Mod; a>>=1;
	}
	return res;
}
ll C(int n,int m){
	if (n<m) return 0;
	if (n==m) return 1;
	return fac[n]*inv[m]%Mod*inv[n-m]%Mod;
}
int main(){
	scanf("%d%d%d",&n,&m,&k); lim=min(n,k);
	fac[0]=1; for (int i=1;i<=k;i++) fac[i]=fac[i-1]*i%Mod;
	inv[1]=1; for (int i=2;i<=k;i++) inv[i]=(Mod-Mod/i)*inv[Mod%i]%Mod;
	inv[0]=1; for (int i=1;i<=k;i++) inv[i]=inv[i-1]*inv[i]%Mod;
	dp[1]=1;
	for (int i=1;i<=lim;i++){
		dp[i]=qpow(i,n);
		for (int j=1;j<i;j++) (dp[i]+=Mod-dp[j]*C(i,j)%Mod)%=Mod;
	}
	if (m==1){
		printf("%lld\n",qpow(k,n));
		return 0;
	}
	if (m==2){
		for (int j=1;j<=lim;j++)
			(ans+=dp[j]*dp[j]%Mod*C(k,j)%Mod*C(k-j,j)%Mod)%=Mod;
	}
	for (int i=1;i<=lim;i++){
		int tmp=qpow(i,n*(m-2));
		for (int j=0;i+j<=lim;j++)
			(ans+=dp[i+j]*dp[i+j]%Mod*C(k,i)%Mod*C(k-i,j)%Mod*C(k-i-j,j)%Mod*tmp%Mod)%=Mod;
	}
	printf("%lld\n",ans);
	return 0;
}
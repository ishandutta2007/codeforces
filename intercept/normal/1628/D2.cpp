#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
const int M=1e6+9;
int n,m,k;
int fac[M],inv[M];
int c(int x,int y){
	return 1ll*fac[x]*inv[y]%mod*inv[x-y]%mod;
}
int kpow(int x,int y,int rex=1){
	for(;y;y>>=1,x=1ll*x*x%mod)if(y&1)rex=1ll*rex*x%mod;
	return rex;
}
void work(){
	int ans=0;
	scanf("%d%d%d",&n,&m,&k);
	if(n==m){
		ans=1ll*m*k%mod;
		printf("%d\n",ans);
		return;
	}
	for(int i=1;i<=m;++i){
		ans=(ans+1ll*i*c(n-i-1,m-i)%mod*kpow(500000004,n-i)%mod)%mod;
	}
	ans=1ll*ans*k%mod;
	printf("%d\n",ans);
}
int main(){
	fac[0]=inv[0]=inv[1]=1;
	for(int i=1;i<M;++i)fac[i]=1ll*fac[i-1]*i%mod;
	for(int i=2;i<M;++i)inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
	for(int i=2;i<M;++i)inv[i]=1ll*inv[i-1]*inv[i]%mod;
	int T;
	scanf("%d",&T);
	while(T--)work();
	return 0;	
}
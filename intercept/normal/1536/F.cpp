#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
const int M=2e6+9;
int n,ans;
int fac[M],inv[M];
int c(int x,int y){
	if(x<y)return 0;
	return 1ll*fac[x]*inv[y]%mod*inv[x-y]%mod;
}
int main(){
	scanf("%d",&n);
	fac[0]=inv[0]=inv[1]=1;
	for(int i=1;i<=n;++i)fac[i]=1ll*fac[i-1]*i%mod;
	for(int i=2;i<=n;++i)inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
	for(int i=1;i<=n;++i)inv[i]=1ll*inv[i-1]*inv[i]%mod;
	for(int i=0;i<=n-i+1;++i){
		if(n%2!=i%2)continue;
		if(i==0)ans=2ll*fac[n]%mod;
		else ans=(ans+2ll*(c(n-i,i)+c(n-i-1,i-1))*fac[n-i])%mod;
	}
	printf("%d\n",ans);
	return 0;
}
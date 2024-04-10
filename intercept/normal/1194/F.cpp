#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int mod=1e9+7;
const int M=2e5+9;
int n,u,sum=0,ans=0;;
int fac[M],inv[M],pw[M];
ll m,t[M];
int Calc(int y,int x){
	if(x<y)return 0;
	return 1ll*fac[x]*inv[y]%mod*inv[x-y]%mod;
}
int main(){
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;++i)scanf("%d",&t[i]);
	pw[0]=fac[1]=inv[1]=inv[0]=1;pw[1]=500000004;
	for(int i=2;i<=n;++i){
		t[i]+=t[i-1];
		pw[i]=500000004ll*pw[i-1]%mod;
		fac[i]=1ll*fac[i-1]*i%mod;
		inv[i]=1ll*(mod-mod/i)*inv[mod%i]%mod;
	}
	for(int i=2;i<=n;++i)inv[i]=1ll*inv[i]*inv[i-1]%mod;
	sum=1;u=min(1ll*n,m);
	for(int i=1;i<=n;++i){
		if(m<t[i])break;
		int v=min(1ll*n,m-t[i]);
		sum=(2ll*sum%mod-Calc(u,i-1)+mod)%mod;
		for(int j=u;j>v;--j)sum=(sum-Calc(j,i)+mod)%mod;
		u=v;
		ans=(ans+1ll*sum*pw[i]%mod)%mod;
		
	}
	printf("%d",ans);
	return 0;
}
#include<cstdio>
using namespace std;
typedef long long ll;
const int Mod=1e9+7;
int n,k;
ll ans,sum,mul1[1100000],mul2[1100000],fac[1100000];
ll qpow(ll x,ll a){
	ll res=1;
	while (a){
		if (a&1) res=res*x%Mod;
		x=x*x%Mod; a>>=1;
	}
	return res;
}
int main(){
	scanf("%d%d",&n,&k);
	mul1[0]=1; mul2[k+3]=1; fac[0]=1;
    for (int i=1;i<=k+2;i++) mul1[i]=1ll*mul1[i-1]*(n-i)%Mod;
    for (int i=k+2;i>=1;i--) mul2[i]=1ll*mul2[i+1]*(n-i)%Mod;
    for (int i=1;i<=k+2;i++) fac[i]=1ll*fac[i-1]*i%Mod;
    for (int i=1;i<=k+2;i++){
    	sum=(sum+qpow(i,k))%Mod;
    	ll a=1ll*mul1[i-1]*mul2[i+1]%Mod, b=1ll*fac[i-1]*fac[k+2-i]%Mod;
    	if ((k-i)&1) ans=(ans-1ll*sum*a%Mod*qpow(b,Mod-2)%Mod+Mod)%Mod;
		else ans=(ans+1ll*sum*a%Mod*qpow(b,Mod-2)%Mod)%Mod;
	}
	printf("%lld\n",ans);
	return 0;
}
#include<bits/stdc++.h>
#define FOR(i,a,b) for(int i=a;i<=b;++i)
#define ROF(i,a,b) for(int i=a;i>=b;--i)
using namespace std;
typedef long long ll;
const int N=4e5+7,mod=1e9+7;
inline ll qpow(ll a,ll b){
	ll R=1;a%=mod;
	for(;b;b>>=1,a=a*a%mod)if(b&1)R=R*a%mod;
	return R;
}
int n,a[N],fac[N],ifac[N];
ll ans;
inline ll C(int n,int m){
	return fac[n]*1ll*ifac[m]%mod*ifac[n-m]%mod;
}
int main(){
	scanf("%d",&n),*fac=1;
	FOR(i,1,N-2)fac[i]=1ll*fac[i-1]*i%mod;
	ifac[N-2]=qpow(fac[N-2],mod-2);
	ROF(i,N-3,0)ifac[i]=ifac[i+1]*(i+1ll)%mod;
	FOR(i,0,n){
		scanf("%d",a+i),(ans+=C(i+a[i],i+1))%=mod;
	}
	printf("%lld",ans);
	return 0;
}
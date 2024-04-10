#include<bits/stdc++.h>
#define rgi register int
#define pbk push_back
#define FOR(i,a,b) for(rgi i=a;i<=b;++i)
#define log(a) cerr<<#a<<'='<<(a)<<" @ line "<<__LINE__<<endl
typedef long long ll;
using namespace std;
const int N=400010,mod=1000000007;
inline ll qpow(ll a,ll b){
	ll ans=1;a%=mod;
	while(b){
		if(b&1)ans=ans*a%mod;
		b>>=1,a=a*a%mod;
	}
	return ans%mod;
}
ll sum(ll l,ll r){
	l%=mod,r%=mod;
	return (l+r)%mod*(r-l+2)%mod*qpow(4,mod-2)%mod;
}
ll a[2];
ll calc(ll x){
	ll ans=0;
	a[0]=2,a[1]=1;
	FOR(i,1,61){
		ll f=min(x,1ll<<i-1);
		x-=f,(ans+=sum(a[i&1],a[i&1]+2ll*f-2))%=mod,(a[i&1]+=2*f)%=mod;
	}
	return ans%mod;
}
ll l,r;
signed main(){
	cin>>l>>r;
	cout<<(calc(r)-calc(l-1)+mod+mod)%mod;
	return 0;
}
#include "bits/stdc++.h"
 
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef vector<int> vi;
mt19937_64 rng(time(0));
 
const int mn = 3e6+10;
const ll mod = 1e9+7;

ll fact[mn],ifact[mn];
ll po(ll a,ll b=mod-2){
	ll ans=1;
	for(;b;b>>=1,a*=a,a%=mod)if(b&1)ans*=a,ans%=mod;
	return ans;
}
ll ch(ll a,ll b){
	if(b>a||b<0)return 0;
	return fact[a]*ifact[b]%mod*ifact[a-b]%mod;
}
ll dp[mn];
ll getdp(int i){
	return i>=0?dp[i]:0;
}

int main()
{
	cin.tie(0);
	cin.sync_with_stdio(0);
	int n;
	cin>>n;
	fact[0]=ifact[0]=1;
	for(int i=1;i<=3*n;i++)fact[i]=fact[i-1]*i%mod,ifact[i]=po(fact[i]);
	ll i3=po(3);
	for(int i=1;i<=3*n+1;i++){
		dp[i-1]=(ch(3*n,i)+3*ch(3*n,i-1)+3*ch(3*n,i-2)+ch(3*n,i-3)-3*getdp(i-2)-getdp(i-3))%mod*i3%mod;
		if(dp[i-1]<0)dp[i-1]+=mod;
	}
	int q;
	cin>>q;
	while(q--){
		ll x;
		cin>>x;
		printf("%lld\n",dp[x]);
	}
}
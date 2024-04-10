#include <bits/stdc++.h>
using namespace std;
#define endl '\n'
typedef long long ll;
const int N = 2e5+7;
const ll MOD = 998244353;
ll dp[N],exr[N],A[N];
ll binpow(ll x,int power){
	ll mult = x%MOD;
	if (mult<0){
		mult += MOD;
	}
	x = 1;
	while(power){
		if (power&1){
			x = x*mult%MOD;
		}
		mult = mult*mult%MOD;
		power /= 2;
	}
	return x;
}
void solve(){
	ll n;
	cin>>n;
	for(int i = 0;i<=n+1;i+=1){
		dp[i] = exr[i] = A[i] = 0;
	}
	ll cnt0 = 0;
	for(int i = 1;i<=n;i+=1){
		cin>>A[i];
		cnt0 += A[i]==0;
	}
	ll df = 0;
	for(int i = 1;i<=cnt0;i+=1){
		df += A[i];
	}
	ll total = (n*(n-1)/2)%MOD;
	ll rt = binpow(total,MOD-2);
	ll mxdf = min(n-cnt0,cnt0);
	for(ll i = mxdf*2;i>=0;i-=2){
		ll pl = (i/2)*(i/2)%MOD*rt%MOD;
		dp[i] = binpow(pl,MOD-2);
	}
	ll res = 0;
	for(int i = df*2;i>=0;i-=2){
		res = (res+dp[i])%MOD;
	}
	cout<<res<<endl;;
}
signed main(){
	ios_base::sync_with_stdio(0); cin.tie(0);
	int t = 1;
	cin>>t;
	while(t--){
		solve();
	}
}
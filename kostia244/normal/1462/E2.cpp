#include<bits/stdc++.h>
using ll = long long;
using namespace std;
const int maxn = 1<<18, mod = 1e9 + 7;
int n, m, k, a[maxn];
ll fact[maxn], inv[maxn];
ll bp(ll a, ll p) {
	ll res = 1;
	while(p) {
		if(p&1) res = (res*a)%mod;
		a=(a*a)%mod;
		p>>=1;
	}
	return res;
}
ll nck(ll n, ll k) {
	if(n < 0 || k < 0 || k > n) return 0;
	ll res = (fact[n]*inv[k])%mod;
	return (res*inv[n-k])%mod;
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	fact[0] = 1;
	for(int i = 1; i < maxn; i++)
		fact[i] = (fact[i-1]*i)%mod;
	inv[maxn-1]=bp(fact[maxn-1], mod-2);
	for(int i = maxn-1; i--;)
		inv[i] = (inv[i+1]*(i+1))%mod;
	int t;cin >> t;
	while(t--) {
		cin >> n >> m >> k;
		for(int i = 1; i <= n; i++) cin >> a[i];
		sort(a+1, a+n+1);
		ll ans = 0;
		for(int j = 1, i = 1; i <= n; i++) {
			while(a[i]-a[j] > k) j++;
			ans = (ans + nck(i-j, m-1))%mod;
		}
		cout << ans << '\n';
	}
}
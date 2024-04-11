#pragma GCC optimize("O3,unroll-loops")
#pragma GCC target("avx,avx2,sse,sse2,ssse3,sse4,sse4.1")
#include <bits/stdc++.h>
#define all(x) begin(x), end(x)
using ll = long long;
using namespace std;
const int maxn = 3e5 + 33, mod = 998244353;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
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
	ll res = (fact[n]*inv[k])%mod;
	return (res*inv[n-k])%mod;
}
int main() {
    cin.tie(0)->sync_with_stdio(0);
	fact[0] = 1;
	for(int i = 1; i < maxn; i++)
		fact[i] = (fact[i-1]*i)%mod;
	inv[maxn-1]=bp(fact[maxn-1], mod-2);
	for(int i = maxn-1; i--;)
		inv[i] = (inv[i+1]*(i+1))%mod;
	int n, k;
	cin >> n >> k;k = n-k;
	if(k > n || k < 1) return cout << 0, 0;
	ll ans = 0;
	for(int i = 0; i <= k; i++) {
		ll t = bp(i, n);
		t = t*nck(k, i)%mod;
		if((k-i)&1) ans = (mod+ans-t)%mod;
		else ans = (ans+t)%mod;
	}
	if(k != n) ans = (ans+ans)%mod;
	if(ans) ans = ans * 1ll * nck(n, k) % mod;
	cout << ans << '\n';
}
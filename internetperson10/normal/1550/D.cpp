#include <bits/stdc++.h>

typedef long long ll;
using namespace std;

const ll MOD = 1000000007;

ll modpow(ll n, int e = MOD-2) {
	if(e == 0) return 1;
	if(e == 1) return n;
	ll x = modpow(n, e/2);
	x *= x;
	x %= MOD;
	if(e%2) {
		x *= n;
		x %= MOD;
	}
	return x;
}

ll inv[200001];

ll binom(int x, int y) {
	if(2*y > x) y = x - y;
	ll base = 1;
	for(int i = 1; i <= y; i++) {
		base *= (x+1-i);
		base %= MOD;
		base *= inv[i];
		base %= MOD;
	}
	return base;
}

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	for(int i = 1; i <= 200000; i++) inv[i] = modpow(i);
	int t;
	cin >> t;
	while(t--) {
		int n, l, r;
		cin >> n >> l >> r;
		int k = min(1-l, r-n);
		ll ans = 0, base;
		if(n%2 == 0) {
			base = binom(n, n/2);
			ans = base * max(k, 0);
			ans %= MOD;
			int plus = n/2, minus = n/2, g = 0;
			for(int i = k; ; i++) {
				if(r-i <= n) {
					base *= inv[plus+minus];
					base %= MOD;
					base *= plus;
					base %= MOD;
					plus--;
				}
				if(l+i >= 1) {
					base *= inv[plus+minus];
					base %= MOD;
					base *= minus;
					base %= MOD;
					minus--;
				}
				ans += base;
				ans %= MOD;
				if(!minus || !plus) break;
			}
		}
		else {
			base = binom(n, n/2);
			ans = base * max(k, 0);
			ans %= MOD;
			int plus = (n+1)/2, minus = n/2, g = 0;
			for(int i = k; ; i++) {
				if(r-i <= n) {
					base *= inv[plus+minus];
					base %= MOD;
					base *= plus;
					base %= MOD;
					plus--;
				}
				if(l+i >= 1) {
					base *= inv[plus+minus];
					base %= MOD;
					base *= minus;
					base %= MOD;
					minus--;
				}
				ans += base;
				ans %= MOD;
				if(!minus || !plus) break;
			}
			base = binom(n, n/2);
			ans += base * max(k, 0);
			ans %= MOD;
			plus = n/2, minus = (n+1)/2, g = 0;
			for(int i = k; ; i++) {
				if(r-i <= n) {
					base *= inv[plus+minus];
					base %= MOD;
					base *= plus;
					base %= MOD;
					plus--;
				}
				if(l+i >= 1) {
					base *= inv[plus+minus];
					base %= MOD;
					base *= minus;
					base %= MOD;
					minus--;
				}
				ans += base;
				ans %= MOD;
				if(!minus || !plus) break;
			}
		}
		cout << ans << '\n';
	}
}
#include <bits/stdc++.h>
typedef long long ll;

using namespace std;
const ll MOD = 998244353;

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

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while(t--) {
		ll n, a1, a2;
		a1 = a2 = 0;
		cin >> n;
		string s;
		cin >> s;
		for(int i = 0; i < n; i++) {
			if(s.at(i) == '0') a1++;
			else if(i+1 == n) break;
			else {
				i++;
				if(s.at(i) == '0') a1++;
				else a2++;
			}
		}
		a1 += a2;
		ll ans = 1;
		while(a2) {
			ans *= a1;
			ans %= MOD;
			ans *= modpow(a2);
			ans %= MOD;
			a1--; a2--;
		}
		cout << ans << '\n';
	}
}
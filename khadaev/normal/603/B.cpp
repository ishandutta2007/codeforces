#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;

const ll MOD = 1000 * 1000 * 1000 + 7;

int main() {
	ll p, k;
	ll t;
	cin >> p >> k;
	ll k_st = k;
	if (k == 0) t = 1;
	else {
		t = 1;
		while (k != 1) {
			//cout << k << '\n';
			++t;
			k = k * k_st % p;
		}
	}
	ll ans = 1;
	for (ll i = 0; i < (p - 1) / t; ++i)
		ans = ans * p % MOD;
	if (k_st == 1)
		ans = ans * p % MOD;
	cout << ans << '\n';
}
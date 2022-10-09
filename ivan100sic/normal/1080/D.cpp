#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

ll mulsat(ll x, ll y) {
	if (x * 1.0 * y > 9e18)
		return 9e18;
	else
		return x * y;
}

bool uporedi(ll n, ll i, ll ub) { // f(n, i) <= ub ??
	if (i > 31)
		return true;
	ll k = n - i;

	ll dva_na_i = (1ll << i) - 1;
	ll cetri_na_k = 1ll << min(2*k, 62ll);

	ll f = mulsat(dva_na_i, cetri_na_k);
	f += 2;
	f = mulsat(dva_na_i, f);
	f /= 3;

	return f >= ub;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		ll n, k;
		cin >> n >> k;
		int found = 0;
		for (ll i=1; i<=60 && i <= n; i++) {
			// da bi imao ovoliku stranicu treba da secem koliko puta?
			ll tt = (1ll << (i + 1)) - i - 2;
			if (tt > k)
				break; // ne valja
			// koliko ima resto?
			if (uporedi(n, i, k)) {
				found = 1;
				cout << "YES " << n-i << '\n';
				break;
			}
		}
		if (!found) {
			cout << "NO\n";
		}
	}
}
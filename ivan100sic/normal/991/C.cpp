#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll jedi(ll n, ll k) {
	if (n < k)
		return n;
	return k + jedi(n - k - (n-k) / 10, k);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	ll n;
	cin >> n;
	ll l = 1, r = n, o = n;
	while (l <= r) {
		ll m = (l+r) / 2;

		if (2 * jedi(n, m) >= n) {
			o = m;
			r = m-1;
		} else {
			l = m+1;
		}
	}
	cout << o;
}
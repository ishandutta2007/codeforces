#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

ll mul(ll a, ll b) {
	if (a * 1.0 * b > 4e18)
		return 4e18;
	return a * b;
}

ll add(ll a, ll b) {
	if (a + 0.0 + b > 4e18)
		return 4e18;
	return a + b;
}

ll b2(ll x) {
	if (x > 3e9)
		return 2e18;
	return x*(x-1)/2;
}

ll trazi(ll n, ll q) {
	ll l = 0, r = 4e18;
	while (l <= r) {
		ll m = (l+r) >> 1;
		ll z = add(mul(m, (1ll << q) - 1), b2(m));
		if (z == n) {
			return m;
		} else if (z > n) {
			r = m-1;
		} else {
			l = m+1;
		}
	}
	return 0;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	ll n;
	cin >> n;
	basic_string<ll> z;
	for (ll q=0; q<=60; q++) {
		ll g = trazi(n, q);
		if (g % 2 == 0)
			continue;
		z += g << q;
	}
	sort(z.begin(), z.end());
	if (z.empty())
		z += -1;
	for (ll x : z)
		cout << x << '\n';
}
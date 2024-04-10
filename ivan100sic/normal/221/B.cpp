// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

set<ll> g(ll x) {
	set<ll> r;
	while (x) {
		r.insert(x % 10);
		x /= 10;
	}
	return r;
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	ll x;
	set<ll> s;
	cin >> x;
	for (ll d=1; d*d <= x; d++) {
		if (x % d == 0) {
			s.insert(d);
			s.insert(x / d);
		}
	}

	ll a = 0;

	for (ll y : s) {
		auto s1 = g(y);
		auto s2 = g(x);
		ll z = 0;
		for (ll c : s1)
			if (s2.count(c))
				z++;
		if (z) {
			a++;
		}
	}
	cout << a << '\n';
}
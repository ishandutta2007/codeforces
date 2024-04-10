#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

ll lca(ll x, ll y) {
	while (x != y) {
		if (x > y)
			x >>= 1;
		else
			y >>= 1;
	}
	return x;
}

map<ll, ll> cost;

void poskupi(ll x, ll y, ll w) {
	while (x != y) {
		if (x > y) {
			cost[x] += w;
			x >>= 1;
		}
		else {
			cost[y] += w;
			y >>= 1;
		}
	}
}

ll cena(ll x, ll y) {
	ll z = 0;
	while (x != y) {
		if (x > y) {
			z += cost[x];
			x >>= 1;
		}
		else {
			z += cost[y];
			y >>= 1;
		}
	}
	return z;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int q;
	cin >> q;
	while (q--) {
		int t;
		cin >> t;
		if (t == 1) {
			ll u, v, w;
			cin >> u >> v >> w;
			poskupi(u, v, w);
		} else {
			ll u, v;
			cin >> u >> v;
			cout << cena(u, v) << '\n';
		}
	}
}
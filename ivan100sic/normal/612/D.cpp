// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

ll rnd10(ll x) {
	ll y = x / 10, r = y;
	for (ll d=-2; d<=2; d++) {
		ll z = y+d;
		if (abs(x - 10*z) < abs(x - 10*r)) {
			r = z;
		}
	}
	return r;
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	int n, k;
	cin >> n >> k;

	map<ll, ll> mp;

	for (int i=0; i<n; i++) {
		ll l, r;
		cin >> l >> r;
		mp[10ll*l - 1]++;
		mp[10ll*r + 1]--;
	}

	int z = 0;
	vector<pair<ll, ll>> sol;
	for (auto [ke, v] : mp) {
		bool bio = z >= k;
		z += v;
		bool je = z >= k;
		if (!bio && je) {
			sol.emplace_back(ke, -1);
		} else if (bio && !je) {
			sol.back().second = ke;
		}
	}

	cout << sol.size() << '\n';
	for (auto [x, y] : sol)
		cout << rnd10(x) << ' ' << rnd10(y) << '\n';
}
// I've decided to retire from ALL contests
// It's been a nice ride... but I need to move on
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
ll a[5005];

ll q(ll x) {
	if (x & 1)
		return x;
	return x >> 1;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++)
		cin >> a[i];

	vector<pair<ll, int>> ol = {{a[n-1], 0}, {1, 1}};

	for (int i=n-2; i>=0; i--) {
		ll x = a[i];
		vector<pair<ll, int>> nu;
		for (auto [u, v] : ol) {
			nu.emplace_back(q(u), v+(q(u) != x));
			if (u & 1) {
				if (x % u == 0)
					nu.emplace_back(x, v);
			} else {
				ll uu = u >> 1;
				if (x % uu == 0 && ((x/uu) & 1))
					nu.emplace_back(x, v);
			}
		}
		sort(begin(nu), end(nu));
		ol = {};
		for (auto [x, y] : nu) {
			if (ol.size() && ol.back().first == x)
				ol.back().second = min(ol.back().second, y);
			else
				ol.emplace_back(x, y);
		}
	}

	int z = 1e9;
	for (auto [x, y] : ol)
		z = min(z, y);
	cout << z << '\n';
}

// I will still practice daily...
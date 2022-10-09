// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

struct state {
	ll rem, cost;
};

ll n, k;
ll l[2005], r[2005], a[2005];

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	cin >> n >> k;
	for (int i=0; i<n; i++) {
		cin >> l[i] >> r[i] >> a[i];
	}

	vector<state> ol;
	ol.push_back({k, 0});

	for (int i=0; i<n; i++) {
		vector<state> nu;

		auto go = [&](ll rem, ll cost) {
			if (rem + (r[i] - l[i]) * k < a[i]) {
				return;
			}

			ll cost2 = cost + a[i];
			ll rem2 = (k - (a[i] - rem) % k) % k;

			nu.push_back({rem2, cost2});

			if (rem + (r[i] - l[i] - 1) * k >= a[i]) {
				ll cost3 = cost2;
				ll rem3 = rem2;
				cost3 += rem3;
				rem3 = k;
				nu.push_back({rem3, cost3});
			}

		};

		for (auto [rem, cost] : ol) {
			if (!i || l[i] > r[i-1]) {
				// reloaduj pre nego sto pocne pucanje
				go(k, cost + rem);
			}

			go(rem, cost);
		}

		sort(begin(nu), end(nu), [](state a, state b) { return a.rem < b.rem; });

		ol.clear();

		for (auto [rem, cost] : nu) {
			if (ol.size() && ol.back().rem == rem) {
				ol.back().cost = min(ol.back().cost, cost);
			} else {
				ol.push_back({rem, cost});
			}
		}
	}

	ll sol = 1e18;
	for (auto [r, c] : ol) {
		sol = min(sol, c);
	}

	if (sol > 9e17) {
		sol = -1;
	}

	cout << sol << '\n';
}
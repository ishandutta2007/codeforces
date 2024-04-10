// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int n, m;
ll a[105][105];

void mn(ll& x, ll y) {
	x = min(x, y);
}

pair<ll, ll> migrate(ll k, ll v, int i, int j) {
	if (a[i][j] < k) {
		return {a[i][j], v + (i+j) * (k - a[i][j])};
	} else {
		return {k, v + a[i][j] - k};
	}
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	int t;
	cin >> t;
	while (t--) {
		cin >> n >> m;
		for (int i=0; i<n; i++) {
			for (int j=0; j<m; j++) {
				cin >> a[i][j];
				a[i][j] -= i+j;
			}
		}

		vector<vector<pair<ll, ll>>> dold(m);

		for (int i=0; i<n; i++) {
			vector<vector<pair<ll, ll>>> dnu(m);
			if (i == 0) {
				dnu[0] = {{a[0][0], 0}};
			}

			for (int j=0; j<m; j++) {
				vector<pair<ll, ll>> f1, f2, f;

				if (i) {
					for (auto [k, v] : dold[j]) {
						f1.push_back(migrate(k, v, i, j));
					}
				}

				if (j) {
					for (auto [k, v] : dnu[j-1]) {
						f2.push_back(migrate(k, v, i, j));
					}
				}

				f.resize(f1.size() + f2.size());
				merge(begin(f1), end(f1), begin(f2), end(f2), begin(f));
				
				for (auto [k, v] : f) {
					if (dnu[j].size() && dnu[j].back().first == k) {
						mn(dnu[j].back().second, v);
					} else {
						dnu[j].emplace_back(k, v);
					}
				}
			}

			if (i == n-1) {
				ll z = 3e18;
				for (auto [k, v] : dnu[m-1])
					z = min(z, v);
				cout << z << '\n';
			} else {
				swap(dold, dnu);
			}
		}
	}
}
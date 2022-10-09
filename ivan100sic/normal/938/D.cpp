#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

ll d[200005];
basic_string<pair<int, ll>> e[200005];
int n, m;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	while (m--) {
		int u, v;
		ll w;
		cin >> u >> v >> w;
		e[u] += {v, w*2};
		e[v] += {u, w*2};
	}

	set<pair<ll, int>> pq;

	for (int i=1; i<=n; i++) {
		cin >> d[i];
		pq.insert({d[i], i});
	}

	while (pq.size()) {
		int x = pq.begin()->second;
		pq.erase(pq.begin());
		for (auto ee : e[x]) {
			int y = ee.first;
			ll w = ee.second;
			if (d[y] > d[x] + w) {
				pq.erase({d[y], y});
				d[y] = d[x] + w;
				pq.insert({d[y], y});
			}
		}
	}

	for (int i=1; i<=n; i++)
		cout << d[i] << ' ';
	cout << '\n';
}
// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int n, m;
int u[300005], v[300005], w[300005];
basic_string<int> e[300005];

ll d[300005];
pair<ll, int> lo[300005];

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	cin >> n >> m;
	for (int i=1; i<=m; i++) {
		cin >> u[i] >> v[i] >> w[i];
		e[u[i]] += i;
		e[v[i]] += i;
	}

	int x0;
	cin >> x0;

	memset(d, 63, sizeof d);
	memset(lo, 63, sizeof lo);

	set<pair<ll, int>> q;
	d[x0] = 0;
	q.insert({0, x0});

	while (q.size()) {
		auto [dx, x] = *q.begin();
		q.erase(q.begin());
		for (int i : e[x]) {
			int y = u[i] ^ v[i] ^ x;
			if (dx + w[i] < d[y]) {
				q.erase({d[y], y});
				d[y] = dx + w[i];
				q.insert({d[y], y});
			}
		}
	}

	for (int i=1; i<=m; i++) {
		int x = u[i], y = v[i];
		ll w = ::w[i];
		if (d[x] > d[y])
			swap(x, y);
		if (d[y] == d[x] + w) {
			lo[y] = min(lo[y], pair(w, i));
		}
	}

	ll wt = 0;
	for (int i=1; i<=n; i++)
		if (lo[i].first <= 1e18)
			wt += lo[i].first;
	cout << wt << '\n';
	for (int i=1; i<=n; i++)
		if (lo[i].first <= 1e18)
			cout << lo[i].second << ' ';
	cout << '\n';
}
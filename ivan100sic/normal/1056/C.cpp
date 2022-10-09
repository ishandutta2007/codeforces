#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int a[2005];
int p[2005];

set<pair<int, int>> un, pa;

int n, m;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=1; i<=2*n; i++) {
		cin >> a[i];
	}

	for (int i=1; i<=m; i++) {
		int u, v;
		cin >> u >> v;
		p[u] = v;
		p[v] = u;
		pa.insert({a[u] - a[v], u});
		pa.insert({a[v] - a[u], v});
	}

	for (int i=1; i<=2*n; i++)
		if (p[i] == 0)
			un.insert({a[i], i});

	int t;
	cin >> t;
	if (t == 1) {
		// ja igram prvi n puta
		for (int i=1; i<=n; i++) {
			// ako ima uparenih uzmi nekog uparenog
			if (pa.size()) {
				int u = prev(pa.end())->second;
				cout << u << '\n' << flush;
				int v;
				cin >> v; // on mora da uzme para
				pa.erase({a[u] - a[v], u});
				pa.erase({a[v] - a[u], v});
			} else {
				// samo uzmi najjaceg
				int u = prev(un.end())->second;
				cout << u << '\n' << flush;
				int v;
				cin >> v; // on ne moze da uzme para jer ih i nema
				un.erase({a[u], u});
				un.erase({a[v], v});
			}
		}
	} else {
		// prvo on igra pa ja
		for (int i=1; i<=n; i++) {
			int u;
			cin >> u;
			if (p[u] && pa.count({a[p[u]] - a[u], p[u]})) {
				// ako je uparen a nije viseci par moram da uzmem para
				int v = p[u];
				cout << v << '\n' << flush;
				pa.erase({a[u] - a[v], u});
				pa.erase({a[v] - a[u], v});
			} else {
				// nije uzeo uparenog ili je uzeo drugog iz para
				if (un.count({a[u], u}))
					un.erase({a[u], u});
				else
					pa.erase({a[u] - a[p[u]], u});

				// ako ima neki par onda par!
				if (pa.size()) {
					int v = prev(pa.end())->second;
					cout << v << '\n' << flush;
					pa.erase({a[v] - a[p[v]], v});
				} else {
					// najjaceg koji nije iz para
					int v = prev(un.end())->second;
					cout << v << '\n' << flush;
					un.erase({a[v], v});
				}
			}
		}
	}
}
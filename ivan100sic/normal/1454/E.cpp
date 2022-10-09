// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int n;
basic_string<int> e[200005];
basic_string<int> cyc;

int d[200005], st[200005];

void rm(int x, int y) {
	auto it = partition(begin(e[x]), end(e[x]), [&](int z) { return z != y; });
	e[x].resize(it - begin(e[x]));
}

void dfs(int x, int db) {
	d[x] = db;
	st[db] = x;
	for (int y : e[x]) {
		if (d[y] == db-1) {
			// odavde smo dosli
		} else if (d[y] == 0) {
			// neposeceno
			dfs(y, db+1);
		} else if (d[y] < db-1) {
			// back-edge
			for (int i=d[y]; i<=d[x]; i++) {
				cyc += st[i];
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	int t;
	cin >> t;
	while (t--) {
		cin >> n;

		cyc = {};
		for (int i=1; i<=n; i++) {
			e[i] = {};
			d[i] = 0;
		}

		for (int i=0; i<n; i++) {
			int x, y;
			cin >> x >> y;
			e[x] += y;
			e[y] += x;
		}

		dfs(1, 2);

		// skloni
		int k = cyc.size();
		for (int i=0; i<k; i++) {
			int x = cyc[i], y = cyc[(i+1)%k], z = cyc[(i+2)%k];
			rm(y, x);
			rm(y, z);
		}

		string vis(n+1, 0);

		ll sol = 0;

		for (int i=1; i<=n; i++) {
			if (!vis[i]) {
				queue<int> q;
				q.push(i);
				vis[i] = 1;
				ll c = 1;
				while (q.size()) {
					int x = q.front(); q.pop();
					for (int y : e[x]) {
						if (!vis[y]) {
							c++;
							vis[y] = 1;
							q.push(y);
						}
					}
				}

				sol += c*(c-1)/2 + c*(n-c);
			}
		}

		cout << sol << "\n";
	}
}
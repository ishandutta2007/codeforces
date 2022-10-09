// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	mt19937 eng(chrono::high_resolution_clock::now().time_since_epoch().count());

	int t;
	cin >> t;
	while (t--) {
		int n, m;
		cin >> n >> m;
		vector<basic_string<int>> e(n+1);
		for (int i=0; i<m; i++) {
			int u, v;
			cin >> u >> v;
			e[u] += v;
		}

		vector<vector<pair<int, int>>> p(n+1);

		for (int i=1; i<=n; i++) {
			for (int j : e[i]) {
				for (int k : e[j]) {
					p[k].emplace_back(i, j);
				}
			}
		}

		vector<int> g(n+1);

		basic_string<int> sol;

		for (int i=1; i<=n; i++) {
			bool ok = 1;
			for (auto [x, y] : p[i]) {
				if (g[x] && g[y])
					ok = 0;
			}
			g[i] = ok;
			if (!ok)
				sol += i;
		}

		if ((int)sol.size() * 7 > 4 * n) {
			for (int i=1; i<=n; i++)
				cout << g[i];
			cout << '\n';
			for (int i=1; i<=n; i++)
				for (int x : e[i])
					cout << i << "_" << x << "__";
			cout << '\n';
		}

		cout << sol.size() << '\n';
		for (int x : sol)
			cout << x << ' ';
		cout << '\n';
	}
}
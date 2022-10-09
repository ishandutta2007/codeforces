// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

template<class T, class E, class A>
void dfs(int y, T& vis, E& e, A& a, int cy, int& ok, A& comp) {
	if (vis[y]) {
		if (vis[y] != cy) {
			ok = 0;
		}
		return;
	}

	vis[y] = cy;
	comp[cy-1].push_back(y);

	for (int r=0; r<2; r++) {
		auto [xx, yy] = e[a[r][y]][e[a[r][y]][0] == pair{r, y}];
		dfs(yy, vis, e, a, r == xx ? 3 - cy : cy, ok, comp);
	}
}

int main() {
	ios::sync_with_stdio(!cin.tie(0));

	int t;
	cin >> t;
	while (t--) {
		int n;
		cin >> n;
		vector<int> a[2], sol;
		vector<vector<pair<int, int>>> e(n);
		for (int i=0; i<2; i++) {
			a[i].resize(n);
			for (int j=0; j<n; j++) {
				int x;
				cin >> x;
				x--;
				a[i][j] = x;
				e[x].emplace_back(i, j);
			}
		}

		int ok = 1;

		for (int i=0; i<n; i++) {
			if (e[i].size() != 2) {
				ok = 0;
			}
		}

		if (!ok) {
			cout << "-1\n";
			continue;
		}

		string vis(n, 0);

		for (int y=0; y<n; y++) {
			if (!vis[y]) {
				vector<int> comp[2];
				dfs(y, vis, e, a, 1, ok, comp);
				int w = comp[0].size() > comp[1].size();
				sol.insert(sol.end(), begin(comp[w]), end(comp[w]));
			}
		}

		if (!ok) {
			cout << "-1\n";
			continue;
		}

		cout << sol.size() << '\n';
		for (int x : sol) {
			cout << x+1 << ' ';
		}
		cout << '\n';
	}
}
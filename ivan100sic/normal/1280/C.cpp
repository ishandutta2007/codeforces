#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
vector<pair<int, int>> e[200005];
int sz[200005];
ll smin, smax;

void dfs(int x, int p) {
	sz[x] = 1;
	for (auto [y, w] : e[x]) {
		if (y == p)
			continue;
		dfs(y, x);
		sz[x] += sz[y];
		if (sz[y] % 2)
			smin += w;
		smax += min(sz[y], n-sz[y]) * 1ll * w;
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int t;
	cin >> t;
	while (t--) {
		cin >> n;
		n *= 2;
		
		smin = smax = 0;
		for (int i=0; i<n; i++) {
			e[i].clear();
			sz[i] = 0;
		}

		for (int i=1; i<n; i++) {
			int u, v, w;
			cin >> u >> v >> w;
			u--, v--;
			e[u].emplace_back(v, w);
			e[v].emplace_back(u, w);
		}

		dfs(0, 0);

		cout << smin << ' ' << smax << '\n';
	}
}
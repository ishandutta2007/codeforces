#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
basic_string<pair<int, int>> e[300005];
ll w[300005], d[300005], sol;

void dfs(int x, int p) {
	ll h1 = 0, h2 = 0;
	d[x] = w[x];
	for (auto [y, w] : e[x]) {
		if (y == p)
			continue;
		dfs(y, x);
		ll v = d[y] - w;
		if (v > h1) {
			h2 = h1;
			h1 = v;
		} else if (v > h2) {
			h2 = v;
		}
	}
	d[x] += h1;
	sol = max({sol, d[x], w[x] + h1 + h2});
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=1; i<=n; i++)
		cin >> w[i];
	for (int i=1; i<n; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		e[u] += {v, w};
		e[v] += {u, w};
	}
	dfs(1, 1);
	cout << sol << '\n';
	for (int i=1; i<=n; i++)
		cerr << d[i] << ' ';
	cerr << '\n';
}
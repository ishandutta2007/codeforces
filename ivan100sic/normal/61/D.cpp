#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n;
basic_string<pair<int, int>> e[100005];

int dfs(int x, int p) {
	int d = 0;
	for (auto ee : e[x]) {
		if (ee.first != p) {
			d = max(d, ee.second + dfs(ee.first, x));
		}
	}
	return d;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	ll sol = 0;
	for (int i=1; i<n; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		e[u] += {v, w};
		e[v] += {u, w};
		sol += 2 * w;
	}

	cout << sol - dfs(1, 1) << '\n';
}
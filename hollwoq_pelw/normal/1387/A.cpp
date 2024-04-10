#include <bits/stdc++.h>
using namespace std;

void solve_case();

signed main() {
	cin.tie(0), cout.tie(0) -> sync_with_stdio(0);

	// int test; for (cin >> test; test --; )
	{
		solve_case();
	}
}

const int N = 1e5 + 5;

int n, m, a[N], b[N], ok = 1;
vector<pair<int, int>> adj[N];

vector<int> sol, equ;

void solve(int u, int ca = 1, int cb = 0) {
	a[u] = ca, b[u] = cb;
	equ.push_back(u);

	for (auto e : adj[u]) {
		int v = e.first, f = e.second;
		if (a[v]) {
			if (a[v] == -ca) {
				ok &= b[v] == f - cb;
			}
			else {
				// (ca + a[v]) * x + cb + b[v] == f;
				// (ca + a[v]) = -2 | 2
				int val = f - cb - b[v];
				if (ca + a[v] == -2)
					val = - val;
				sol.push_back(val);
			}
		} else {
			solve(v, - ca, f - cb);
		}
	}
}

long double res[N];

void solve_case() {
	cin >> n >> m;
	for (int u, v, w; m --; ) {
		cin >> u >> v >> w;
		adj[u].emplace_back(v, w);
		adj[v].emplace_back(u, w);
	}

	for (int i = 1; i <= n; i++) if (!a[i]) {
		sol.clear();
		equ.clear();
		solve(i);

		if (sol.size()) {
			sort(sol.begin(), sol.end());
			if (sol[0] != sol.back()) ok = 0;

			int x = sol[0];

			for (int u : equ)
				res[u] = x * a[u] / 2.0 + b[u];
			// cout << "among us\n";
		} else {

			long double l = - N, r = + N;

			for (int iter = 80; iter --; ) {
				long double ml = (l + l + r) / 3;
				long double mr = (l + r + r) / 3;

				long double val = 0;
				for (int u : equ) {
					long double v1 = ml * a[u] + b[u];
					long double v2 = mr * a[u] + b[u];
					val += (v1 > 1e-12 ?  v1 : -v1)
						+  (v2 > 1e-12 ? -v2 :  v2);
				}
				if (val > 1e-9)
					l = ml;
				else
					r = mr;
			}

			for (int u : equ)
				res[u] = l * a[u] + b[u];
		}

	}

	if (!ok) return cout << "NO\n", (void) 0;

	cout << fixed << setprecision(6);
	cout << "YES\n";
	for (int i = 1; i <= n; i++)
		cout << res[i] << ' ';
}

#include <bits/stdc++.h>

#define all(a) (a).begin(), (a).end()
#define sz(a) (int)(a).size()
#define pb push_back

using namespace std;

typedef long long ll;
typedef pair<int, int> pii;
typedef pair<ll, ll> pll;
typedef double ld;

vector<vector<int> > g;
vector<char> used;
vector<int> p;
vector<int> cycle;

void dfs(int v, int par) {
	p[v] = par;
	used[v] = true;
	for (int to : g[v]) {
		if (to == par) {
			continue;
		}
		if (used[to]) {
			cycle.pb(v);
			while (v != to) {
				v = p[v];
				cycle.pb(v);
			}
			return;
		}
		dfs(to, v);
		if (!cycle.empty()) {
			return;
		}
	}
}

void out(const vector<int>& ans) {
	cout << "YES\n";
	for (int i = 0; i < sz(ans); ++i) {
		cout << ans[i] << " ";
	}
	cout << "\n";
}

int main() {

	ios_base::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);

	//ifstream cin("input.txt");

	int tt;
	cin >> tt;

	while (tt--) {
		int n, m;
		cin >> n >> m;
		g = vector<vector<int> >(n, vector<int>());
		while (m--) {
			int u, v;
			cin >> u >> v;
			--u, --v;
			g[u].pb(v);
			g[v].pb(u);
		}
		used.assign(n, false);
		p.assign(n, -1);
		cycle.clear();
		for (int i = 0; i < n; ++i) {
			if (!used[i] && cycle.empty()) {
				dfs(i, i);
			}
		}
		vector<int> ans(n);
		if (!cycle.empty()) {
			for (int v : cycle) {
				ans[v] = 1;	
			}
			out(ans);
			continue;
		}

		bool done = false;
		for (int i = 0; i < n; ++i) {
			if (sz(g[i]) >= 4) {
				ans[i] = 2;
				for (int j = 0; j < 4; ++j) {
					int to = g[i][j];
					ans[to] = 1;
				}
				out(ans);
				done = true;
				break;
			}
		}
		if (done) {
			continue;
		}

		used.assign(n, false);
		p.assign(n, -1);
		for (int i = 0; i < n; ++i) {
			if (sz(g[i]) != 3) {
				continue;
			}
			if (used[i]) {
				ans[i] = 2;
				int curr = i;
				while (p[curr] != curr) {
					curr = p[curr];
					ans[curr] = 2;
				}
				for (int to : g[i]) {
					if (ans[to] == 0) {
						ans[to] = 1;
					}
				}
				for (int to : g[curr]) {
					if (ans[to] == 0) {
						ans[to] = 1;
					}
				}
				out(ans);
				done = true;
				break;
			} else {
				dfs(i, i);
			}
		}
		if (done) {
			continue;
		}

		for (int i = 0; i < n; ++i) {
			if (sz(g[i]) != 3) {
				continue;
			}
			int eq1 = 0;
			for (int to : g[i]) {
				if (sz(g[to]) == 1) {
					++eq1;
				}
			}
			if (eq1 == 0) {
				ans[i] = 3;
				for (int to : g[i]) {
					ans[to] = 2;
					for (int d : g[to]) {
						if (d != i) {
							ans[d] = 1;
						}
					}
				}
				out(ans);
				done = true;
				break;
			}
			if (eq1 > 1) {
				continue;
			}

			int son = -1;
			for (int to : g[i]) {
				for (int e : g[to]) {
					if (e == i) {
						continue;
					}
					for (int t : g[e]) {
						if (t == to) {
							continue;
						}
						for (int h : g[t]) {
							if (h == e) {
								continue;
							}
							for (int j : g[h]) {
								if (j == t) {
									continue;
								}
								son = to;
							}
						}
					}
				}
			}
			if (son != -1) {
				ans[i] = 6;
				ans[son] = 5;
				for (int e : g[son]) {
					if (e == i) {
						continue;
					}
					ans[e] = 4;
					for (int t : g[e]) {
						if (t == son) {
							continue;
						}
						ans[t] = 3;
						for (int h : g[t]) {
							if (h == e) {
								continue;
							}
							ans[h] = 2;
							for (int j : g[h]) {
								if (j == t) {
									continue;
								}
								ans[j] = 1;
							}
						}
					}
				}
				for (int to : g[i]) {
					if (to == son) {
						continue;
					}
					if (sz(g[to]) == 1) {
						ans[to] = 3;
					} else {
						ans[to] = 4;
						for (int f : g[to]) {
							if (f == i) {
								continue;
							}
							ans[f] = 2;
						}
					}
				}
				out(ans);
				done = true;
				break;
			}

			int eq3 = 0;
			for (int to : g[i]) {
				for (int d : g[to]) {
					if (d == i) {
						continue;
					}
					for (int e : g[d]) {
						if (e == to) {
							continue;
						}
						++eq3;
					}
				}
			}
			if (eq3 != 2) {
				continue;
			}
			ans[i] = 4;
			for (int to : g[i]) {
				if (sz(g[to]) == 1) {
					ans[to] = 2;
				} else {
					ans[to] = 3;
					for (int d : g[to]) {
						if (d == i) {
							continue;
						}
						ans[d] = 2;
						for (int e : g[d]) {
							if (e == to) {
								continue;
							}
							ans[e] = 1;
						}
					}
				}
			}
			out(ans);
			done = true;
			break;
		}

		if (!done) {
			cout << "NO\n";
		}
	}

}
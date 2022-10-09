#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

set<int> e[1000005];
basic_string<pair<int, int>> sol;
int n, m;
bool vis[1000005];

int dfs(int x, int p) {
	vis[x] = 1;
	int sz = e[x].size();
	for (int y : e[x]) {
		if (!vis[y]) {
			sz += dfs(y, x);
		}
	}
	if (sz & 1) {
		sol += {x, p};
	}
	return sz;
}

list<int> euler(int x) {
	list<int> a;
	while (e[x].size()) {
		int t = *e[x].begin();
		e[x].erase(t);
		e[t].erase(x);
		a.push_back(t);
		x = t;
	}
	for (auto it = a.begin(); it != a.end(); ++it) {
		auto b = euler(*it);
		a.splice(next(it), b);
	}
	return a;
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=0; i<m; i++) {
		int u, v;
		cin >> u >> v;
		e[u].insert(v);
		e[v].insert(u);
	}

	for (int i=1; i<=n; i++) {
		if (!vis[i]) {
			dfs(i, i);
		}
	}
	for (auto [x, y] : sol) {
		e[x].erase(y);
		e[y].erase(x);
	}

	for (int i=1; i<=n; i++) {
		auto a = euler(i);
		if (a.size() % 2) {
			sol += {*a.begin(), *next(a.begin())};
			for (auto it=next(a.begin()); it!=a.end(); it=next(next(it))) {
				sol += {*it, *next(it)}; 
			}
		} else {
			for (auto it=a.begin(); it!=a.end(); it=next(next(it))) {
				sol += {*it, *next(it)}; 
			}
		}

			
	}

	cout << sol.size() << '\n';
	for (auto [x, y] : sol)
		cout << x << ' ' << y << '\n';
}
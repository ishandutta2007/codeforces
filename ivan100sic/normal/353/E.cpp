#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct matching {

	/* https://en.wikipedia.org/wiki/Hopcroft%E2%80%93Karp_algorithm */

	vector<vector<int>> e;
	const int n, m;

	matching(int n, int m) : e(n+1), n(n), m(m) {}

	/* Cvorovi su indeksirani od 1, zalim slucaj */

	void add_edge(int u, int v) {
		e[u].push_back(v);
	}

	vector<int> pu, pv, d;

	bool bfs() {
		queue<int> q;

		for (int u=1; u<=n; u++) {
			if (pu[u] == 0) {
				d[u] = 0;
				q.push(u);
			} else {
				d[u] = 123123123;
			}
		}

		d[0] = 123123123;

		while (!q.empty()) {
			int u = q.front(); q.pop();
			if (d[u] < d[0]) {
				for (int v : e[u]) {
					if (d[pv[v]] == 123123123) {
						d[pv[v]] = d[u] + 1;
						q.push(pv[v]);
					}
				}
			}
		}

		return d[0] != 123123123;
	}

	bool dfs(int u) {
		if (u == 0) {
			return true;
		}
		for (int v : e[u]) {
			if (d[pv[v]] == d[u] + 1) {
				if (dfs(pv[v])) {
					pv[v] = u;
					pu[u] = v;
					return true;
				}
			}
		}
		d[u] = 123123123;
		return false;
	}

	int run() {
		int sz = 0;
		pu.resize(n+1, 0);
		pv.resize(m+1, 0);
		d.resize(n+1);

		while (bfs()) {
			for (int u=1; u<=n; u++) {
				if (pu[u] == 0) {
					if (dfs(u)) {
						sz++;
					}
				}
			}
		}

		return sz;
	}

	auto vertex_cover() {
		run();

		queue<int> q;
		vector<int> drhs(m+1, 123123123);

		for (int u=1; u<=n; u++) {
			if (pu[u] == 0) {
				d[u] = 0;
				q.push(u);
			} else {
				d[u] = 123123123;
			}
		}

		d[0] = 123123123;

		while (!q.empty()) {
			int u = q.front(); q.pop();
			if (d[u] < d[0]) {
				for (int v : e[u]) {
					drhs[v] = 0;
					if (d[pv[v]] == 123123123) {
						d[pv[v]] = d[u] + 1;
						q.push(pv[v]);
					}
				}
			}
		}

		pair<vector<int>, vector<int>> s;
		for (int i=1; i<=n; i++)
			if (pu[i] > 0 && d[i] == 123123123)
				s.first.push_back(i);
		for (int j=1; j<=m; j++)
			if (drhs[j] == 0)
				s.second.push_back(j);
		return s;
	}
};


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	string s;
	cin >> s;
	int n = s.size();
	matching e(n, n);
	for (int i=0; i<n; i++) {
		if (s[i] == '0') {
			e.add_edge(i+1, (i+1)%n+1);
		} else {
			e.add_edge((i+1)%n+1, i+1);
		}
	}
	cout << n - e.run() << '\n';
}
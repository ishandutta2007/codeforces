#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m, k;
int u[1005], v[1005], c[1005];
int idx[105][105];
int fc[105][1005];

struct euler {
	set<int> e[105];

	void add_edge(int x, int y) {
		e[x].insert(y);
		e[y].insert(x);
	}

	list<int> dfs(int x) {
		list<int> a;
		while (e[x].size()) {
			int y = *e[x].begin();
			e[x].erase(y);
			e[y].erase(x);
			a.push_back(y);
			x = y;
		}

		for (auto it = a.begin(); it != a.end(); ++it) {
			auto v = dfs(*it);
			a.splice(next(it), v);
		}

		return a;
	}

	vector<pair<int, int>> run() {
		for (int i=1; i<=n; i++) {
			if (e[i].size() % 2) {
				add_edge(i, n+1);
			}
		}

		vector<pair<int, int>> r;
		for (int i=1; i<=n; i++) {
			auto a = dfs(i);
			if (a.size()) {
				a.push_front(i);
				for (auto it = a.begin(); next(it) != a.end(); ++it) {
					int x = *it;
					int y = *next(it);
					if (x <= n && y <= n) {
						r.emplace_back(x, y);
					}
				}
			}
		}

		return r;
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m >> k;
	for (int i=0; i<n; i++) {
		int _;
		cin >> _;
	}

	for (int i=0; i<m; i++) {
		cin >> u[i] >> v[i];
		idx[u[i]][v[i]] = idx[v[i]][u[i]] = i;
	}

	mt19937 eng;
	for (int i=0; i<m; i++) {
		c[i] = uniform_int_distribution<int>(1, k)(eng);
		fc[u[i]][c[i]]++;
		fc[v[i]][c[i]]++;
	}

	while (1) {
		bool smth = false;
		for (int i=1; i<=n; i++) {
			auto [p, q] = minmax_element(fc[i]+1, fc[i]+k+1);
			if (*q-*p > 2) {
				// cerr << "node " << i << " sucks\n";
				smth = true;
				euler e;
				int c1 = p-fc[i], c2 = q-fc[i];
				for (int i=0; i<m; i++) {
					if (c[i] == c1 || c[i] == c2) {
						e.add_edge(u[i], v[i]);
					}
				}
				auto r = e.run();
				int boja = c1;
				for (auto [u, v] : r) {
					int j = idx[u][v];
					fc[u][c[j]]--;
					fc[v][c[j]]--;
					fc[u][boja]++;				
					fc[v][boja]++;
					c[j] = boja;
					boja ^= c1 ^ c2;				
				}
			}
		}
		if (!smth)
			break;
	}

	for (int i=0; i<m; i++)
		cout << c[i] << "\n";
}
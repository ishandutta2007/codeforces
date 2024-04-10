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

void solve_brut(int t, int n) {
	matching eng(n, n);
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=n; j++) {
			if (!!(i&j) == t && i != j) {
				eng.add_edge(i, j);
			}
		}
	}
	
	int z = eng.run();
	if (z < n) {
		cout << "NO\n";
	} else {
		cout << "YES ";
		for (int i=1; i<=n; i++)
			cout << eng.pu[i] << " \n"[i == n];
	}
}

void solve_smart(int t, int n) {
	if (n <= 6) {
		solve_brut(t, n);
		return;
	}

	if (t == 0) {
		if (n % 2) {
			cout << "NO\n";
		} else {
			vector<int> a(n);
			iota(a.begin(), a.end(), 1);
			int x = n;
			while (x > 0) {
				int y = 1;
				while (2*y <= x)
					y <<= 1;
				int w = x-y+1;
				reverse(a.begin()+x-2*w, a.begin()+x);
				x -= 2*w;
			}
			cout << "YES ";
			for (int i=0; i<n; i++)
				cout << a[i] << " \n"[i == n-1];
		}
	} else {
		if ((n & (n-1)) == 0) {
			cout << "NO\n";
		} else {
			vector<int> a(n+1);
			set<int> av;
			for (int i=1; i<=n; i++)
				av.insert(i);
			auto twin = [&](vector<int> v) {
				int k = v.size();
				// if (k == 1) {
				// 	cerr << "error! " << __LINE__ << '\n';
				// 	cerr << n << ' ' <<v[0] << '\n';
				// }
				for (int i=0; i<k; i++) {
					a[v[i]] = v[(i+1)%k];
					av.erase(v[i]);
				}
			};

			for (int i=524288; i; i>>=1) {
				vector<int> q;
				for (int j=i; j<=n; j+=2*i) {
					if (av.count(j))
						q.push_back(j);
				}
				if (q.size() == 1) {
					q.push_back(i+1);
				}

				twin(q);
			}

			// if (av.size()) {
			// 	cerr << "error! " << __LINE__ << '\n';
			// }

			cout << "YES ";
			for (int i=1; i<=n; i++)
				cout << a[i] << " \n"[i == n];
		}
	}
}

/*

4 ili vece pridruzi x+1
4-5
8-9



do 6 - brutina
0 - mogu svi parni
1 - mogu svi koji nisu stepeni dvojke
*/

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	// for (int n=1; n<=36; n++)
	// 	solve_brut(1, n);

	// for (int n=1; n<=36; n++)
	// 	solve_smart(1, n);

	int n;
	cin >> n;
	solve_smart(0, n);
	solve_smart(1, n);

}
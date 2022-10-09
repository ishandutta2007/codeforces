#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

int n, m;
basic_string<pair<int, int>> e[100005];
int d0[100005], p0[100005];

void bfs0() {
	fill(d0, d0+n, 123123123);
	fill(p0, p0+n, -1);
	d0[n-1] = 0;
	basic_string<int> q = {n-1};
	size_t qs = 0;
	while (qs != q.size()) {
		int x = q[qs++];
		for (auto [y, w] : e[x]) {
			if (w == 0 && d0[y] == 123123123) {
				d0[y] = d0[x] + 1;
				p0[y] = x;
				q += y;
			}
		}
	}
}

int d1[100005];

void bfs1() {
	fill(d1, d1+n, 123123123);
	d1[0] = 0;
	basic_string<int> q = {0};
	size_t qs = 0;
	while (qs != q.size()) {
		int x = q[qs++];
		for (auto [y, w] : e[x]) {
			if (d1[y] == 123123123) {
				d1[y] = d1[x] + 1;
				q += y;
			}
		}
	}
}

void solve() {
	int najkraci_do_f = 123123123;
	for (int i=0; i<n; i++) {
		if (d0[i] != 123123123)
			najkraci_do_f = min(najkraci_do_f, d1[i]);
	}

	cerr << najkraci_do_f << '\n';

	// sad uzmi sve njih
	map<int, int> curr;
	for (int i=0; i<n; i++) {
		if (d0[i] != 123123123 && d1[i] == najkraci_do_f) {
			curr[i] = d0[i];
		}
	}

	string sol;
	map<int, int> came_from;

	while (d1[curr.begin()->first]) {
		map<int, int> nx;
		int min_grana = 123123123;
		for (auto [x, vr] : curr) {
			for (auto [y, w] : e[x]) {
				if (d1[y] == d1[x] - 1) {
					min_grana = min(min_grana, w);
				}
			}
		}
		sol += (char)(min_grana + '0');
		for (auto [x, vr] : curr) {
			for (auto [y, w] : e[x]) {
				if (d1[y] == d1[x] - 1 && w == min_grana) {
					if (nx.count(y) > 0) {
						if (vr < nx[y]) {
							nx[y] = vr;
							came_from[y] = x;
						}
					} else {
						nx[y] = vr;
						came_from[y] = x;
					}
				}
			}
		}
		swap(nx, curr);
	}

	basic_string<int> put = {0};

	int x = 0;
	for (int i=0; i<(int)sol.size(); i++) {
		x = came_from[x];
		put += x;
	}

	while (x != n-1) {
		x = p0[x];
		put += x;
	}

	if (sol == "")
		sol = "0";

	cout << sol << '\n';
	cout << put.size() << '\n';
	for (int x : put)
		cout << x << ' ';
	cout << '\n';

}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=0; i<m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		e[u] += {v, w};
		e[v] += {u, w};
	}

	bfs0();
	bfs1();
	solve();
}
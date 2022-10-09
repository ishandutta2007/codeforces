#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int BS = 20;

struct upit {
	int t, x, y;	
} u[200005];

/*
g je skup grana na pocetku nekog bloka
c je skup relevantnih grana za trenutni blok
f je privremeni skup grana (g\c ili g*c)
*/

set<pair<int, int>> alive;
vector<pair<int, int>> g, c, f;
vector<vector<int>> e;
vector<unordered_multiset<int>> h;
int n, q;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> q;
	for (int i=0; i<q; i++) {
		cin >> u[i].t >> u[i].x >> u[i].y;
	}

	int last = 0;
	for (int _blok=0; _blok<BS; _blok++) { // nesto drugo?
		int ql = q*_blok/BS, qr = q*(_blok+1)/BS;
		c.clear();
		for (int i=ql; i<qr; i++) {
			if (u[i].t == 1) {
				int x = u[i].x, y = u[i].y;
				if (x > y)
					swap(x, y);
				c.emplace_back(x, y);
				x = x == n ? 1 : x+1;
				y = y == n ? 1 : y+1;
				if (x > y)
					swap(x, y);
				c.emplace_back(x, y);
			}
		}
		sort(c.begin(), c.end());
		c.erase(unique(c.begin(), c.end()), c.end());
		f.resize(g.size());
		f.erase(set_difference(g.begin(), g.end(), c.begin(), c.end(), f.begin()),
			f.end());
		// f su grane za koje pravimo cc
		e.assign(n+1, {});
		vector<int> cc(n+1);
		for (auto [x, y] : f) {
			e[x].push_back(y);
			e[y].push_back(x);
		}
		int k = 0;
		for (int i=1; i<=n; i++) {
			if (cc[i] == 0) {
				cc[i] = ++k;
				vector<int> q = {i};
				size_t qs = 0;
				while (qs != q.size()) {
					int x = q[qs++];
					for (int y : e[x]) {
						if (cc[y] == 0) {
							cc[y] = k;
							q.push_back(y);
						}
					}
				}
			}
		}
		h.assign(k+1, {});
		// dodaj grane iz preseka
		f.resize(c.size());
		f.erase(set_intersection(g.begin(), g.end(), c.begin(), c.end(), f.begin()),
			f.end());
		for (auto [x, y] : f) {
			x = cc[x];
			y = cc[y];
			if (x != y) {
				h[x].insert(y);
				h[y].insert(x);
			}
		}
		string vis(k+1, 0);
		// sad konacno normalno resi upite
		for (int i=ql; i<qr; i++) {
			int x = u[i].x, y = u[i].y;
			x += last;
			y += last;
			if (x == n+1) x = 1;
			if (y == n+1) y = 1;
			if (x > y)
				swap(x, y);

			if (u[i].t == 2) {
				// samo pusti dfs ili nesto
				vector<int> q = {cc[x]};
				vis[cc[x]] = 1;
				size_t qs = 0;
				while (qs != q.size()) {
					int x = q[qs++];
					for (int y : h[x]) {
						if (!vis[y]) {
							vis[y] = true;
							q.push_back(y);
						}
					}
				}

				if (vis[cc[y]]) {
					cout << (last = 1);
				} else {
					cout << (last = 0);
				}

				for (int x : q)
					vis[x] = 0;
			} else {
				if (alive.count({x, y})) {
					alive.erase({x, y});
					if (cc[x] != cc[y]) {
						h[cc[x]].erase(h[cc[x]].find(cc[y]));
						h[cc[y]].erase(h[cc[y]].find(cc[x]));
					}
				} else {
					alive.insert({x, y});
					if (cc[x] != cc[y]) {
						h[cc[x]].insert(cc[y]);
						h[cc[y]].insert(cc[x]);
					}
				}
			}
		}

		g = vector<pair<int, int>>(alive.begin(), alive.end());
	}
	cout << '\n';
}
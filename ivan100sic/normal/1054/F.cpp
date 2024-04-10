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


int n, mx, my;
int x[1005], y[1005];
int xt[1005], yt[1005];
int xu[1005], yu[1005];

char a[1005][1005];
int ha[1005][1005], va[1005][1005];
int hp[1005][1005], vp[1005][1005];

vector<pair<int, int>> hor[1005], ver[1005];

struct segment {
	int nivo, lo, hi;
};

struct resenje {
	int x1, y1, x2, y2;
};

vector<segment> hs, vs;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n;
	for (int i=0; i<n; i++) {
		cin >> x[i] >> y[i];
		xu[i] = x[i];
		yu[i] = y[i];
	}

	sort(xu, xu+n);
	sort(yu, yu+n);
	mx = unique(xu, xu+n) - xu;
	my = unique(yu, yu+n) - yu;

	for (int i=0; i<n; i++) {
		xt[i] = lower_bound(xu, xu+mx, x[i]) - xu;
		yt[i] = lower_bound(yu, yu+my, y[i]) - yu;
		a[xt[i]][yt[i]] = 1;
	}

	for (int i=0; i<mx; i++) {
		int lo = 123123, hi = -123123;
		for (int j=0; j<my; j++)
			if (a[i][j]) {
				lo = min(lo, j);
				hi = max(hi, j);
			}
		for (int j=lo+1; j<hi; j++) {
			if (a[i][j] == 0) {
				if (a[i][j-1] == 0)
					hor[i].back().second = j;
				else
					hor[i].push_back({j, j});
			}
		}
	}

	for (int j=0; j<my; j++) {
		int lo = 123123, hi = -123123;
		for (int i=0; i<mx; i++)
			if (a[i][j]) {
				lo = min(lo, i);
				hi = max(hi, i);
			}
		for (int i=lo+1; i<hi; i++) {
			if (a[i][j] == 0) {
				if (a[i-1][j] == 0)
					ver[j].back().second = i;
				else
					ver[j].push_back({i, i});
			}
		}
	}

	for (int i=0; i<mx; i++)
		for (auto p : hor[i]) {
			hs.push_back({i, p.first, p.second});
			for (int j=p.first; j<=p.second; j++)
				ha[i][j] = (int)hs.size();
		}

	for (int j=0; j<my; j++)
		for (auto p : ver[j]) {
			vs.push_back({j, p.first, p.second});
			for (int i=p.first; i<=p.second; i++)
				va[i][j] = (int)vs.size();
		}

	matching mc(hs.size(), vs.size());

	for (int i=0; i<mx; i++)
		for (int j=0; j<my; j++)
			mc.add_edge(ha[i][j], va[i][j]);

	auto vc = mc.vertex_cover();

	for (auto x : vc.first) {
		x--;
		for (int j = hs[x].lo; j <= hs[x].hi; j++)
			hp[hs[x].nivo][j] = 1;
	}

	for (auto x : vc.second) {
		x--;
		for (int i = vs[x].lo; i <= vs[x].hi; i++)
			vp[i][vs[x].nivo] = 1;
	}

	vector<resenje> sol;
	// popuni, stampaj


	for (int j=0; j<my; j++) {
		int lo = 123123, hi = -123123;
		for (int i=0; i<mx; i++)
			if (a[i][j]) {
				lo = min(lo, i);
				hi = max(hi, i);
			}

		int last = 0;

		for (int i=lo; i<=hi; i++) {
			int curr = !vp[i][j];
			if (curr) {
				if (last)
					sol.back().x2 = i;
				else
					sol.push_back({i, j, i, j});
			}
			last = curr;
		}
	}

	cout << sol.size() << '\n';
	for (auto r : sol)
		cout << xu[r.x1] << ' ' << yu[r.y1] << ' ' << xu[r.x2] << ' ' << yu[r.y2] << '\n';

	sol = {};

	for (int i=0; i<mx; i++) {
		int lo = 123123, hi = -123123;
		for (int j=0; j<my; j++)
			if (a[i][j]) {
				lo = min(lo, j);
				hi = max(hi, j);
			}

		int last = 0;

		for (int j=lo; j<=hi; j++) {
			int curr = !hp[i][j];
			if (curr) {
				if (last)
					sol.back().y2 = j;
				else
					sol.push_back({i, j, i, j});
			}
			last = curr;
		}
	}

	cout << sol.size() << '\n';
	for (auto r : sol)
		cout << xu[r.x1] << ' ' << yu[r.y1] << ' ' << xu[r.x2] << ' ' << yu[r.y2] << '\n';

}
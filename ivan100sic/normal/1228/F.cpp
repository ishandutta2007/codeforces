#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct tree {
	vector<vector<int>> e;
	vector<int> d, p;
	int n;

	tree(int n) : e(n), d(n), p(n), n(n) {}

	void add_edge(int x, int y) {
		e[x].push_back(y);
		e[y].push_back(x);
	}

	vector<int> dijametar() {
		d[0] = 0;
		dfs(0, 0);
		int x = max_element(d.begin(), d.end()) - d.begin();
		d[x] = 0;
		dfs(x, x);
		int y = max_element(d.begin(), d.end()) - d.begin();
		vector<int> q;
		for (int i=y; i!=x; i=p[i])
			q.push_back(i);
		q.push_back(x);
		return q;
	}

	vector<pair<int, int>> grane() const {
		vector<pair<int, int>> v;
		for (int i=0; i<n; i++)
			for (int j : e[i])
				if (j > i)
					v.emplace_back(i, j);
		return v;
	}

	void dfs(int x, int par) {
		p[x] = par;
		for (int y : e[x]) {
			if (y == par)
				continue;
			d[y] = d[x] + 1;
			dfs(y, x);
		}
	}

	bool rekdobro(int x, int p, int sz) {
		if (sz == 1)
			return e[x].size() == 1;
		if (e[x].size() != 3)
			return false;
		bool ok = true;
		for (int y : e[x]) {
			if (y == p)
				continue;
			ok &= rekdobro(y, x, sz/2);
		}
		return ok;
	}

	bool dobro_drvo() {
		auto dij = dijametar();
		if (dij.size() % 2 == 0)
			return false;
		int x = dij[dij.size() / 2];
		if (e[x].size() != 2)
			return false;
		return rekdobro(e[x][0], x, n/2) && rekdobro(e[x][1], x, n/2);
	}

	int najblizi_list(int r) {
		for (int i=0; i<n; i++) {
			if (e[i].size() == 2) {
				for (int j : e[i]) {
					if (e[j].size() == 1)
						return i;
				}
			}
		}
		return 0;
	}
};

void done(set<int> v) {
	cout << v.size() << '\n';
	for (int x : v)
		cout << x+1 << ' ';
	cout << '\n';
	exit(0);
}

set<int> sol;

bool eqp(pair<int, int> a, pair<int, int> b) {
	return (a.first == b.first && a.second == b.second) ||
		(a.second == b.first && a.first == b.second);
}

void probaj(const tree& d, int x) {
	if (d.e[x].size() > 4)
		return;
	int m = d.e[x].size();
	for (int i=0; i<m; i++) {
		for (int j=i+1; j<m; j++) {
			int u = d.e[x][i];
			int v = d.e[x][j];

			// ubacujemo novi cvor
			int novi = d.n;

			tree d2(d.n + 1);
			for (auto [a, b] : d.grane()) {
				if (eqp({a, b}, {x, u}))
					continue;
				if (eqp({a, b}, {x, v}))
					continue;
				d2.add_edge(a, b);
			}

			d2.add_edge(novi, x);
			d2.add_edge(novi, u);
			d2.add_edge(novi, v);

			if (d2.dobro_drvo()) {
				sol.insert(x);
				return;
			}
		}
	}
}

void probaj2(const tree& d, int x) {
	tree d2(d.n + 1);
	for (auto [a, b] : d.grane())
		d2.add_edge(a, b);
	d2.add_edge(x, d.n);
	if (d2.dobro_drvo())
		sol.insert(x);
}


int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	int nlog;
	cin >> nlog;

	if (nlog == 2) {
		cout << "2\n1 2\n";
		return 0;
	}

	int n = (1 << nlog) - 2;

	tree drvo(n);

	for (int i=1; i<n; i++) {
		int u, v;
		cin >> u >> v;
		u--, v--;
		drvo.add_edge(u, v);
	}

	// probaj cvor stepena bar 4? ako ima vise zajebi
	vector<int> kand;
	for (int i=0; i<n; i++)
		if (drvo.e[i].size() >= 4)
			kand.push_back(i);
	if (kand.size() > 1)
		done({});
	for (int x : kand)
		probaj(drvo, x);

	// probaj oko centra dijametra
	auto dij = drvo.dijametar();

	for (int i=(int)dij.size()/2-1; i<=(int)dij.size()/2+1; i++) {
		if (0 <= i && i < (int)dij.size())
			probaj(drvo, dij[i]);
	}

	int cntr = dij[dij.size()/2];
	cerr << "cntr " << cntr << '\n';
	int nl = drvo.najblizi_list(cntr);
	cerr << "nl " << nl << '\n';
	probaj2(drvo, nl);

	done(sol);
}

/*
4
1 2
1 3
2 4
2 5
3 6
3 7
4 8
4 9
5 10
5 11
6 12
7 13
7 14
*/
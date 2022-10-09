#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

const int LIMIT = 500;

struct grana {
	int u, v;
};

struct dsu {
	vector<int> p;

	dsu(int n) : p(n) {
		iota(p.begin(), p.end(), 0);
	}

	int e(int x) {
		if (p[x] == x)
			return x;
		return p[x] = e(p[x]);
	}

	void merge(int x, int y) {
		x = e(x);
		y = e(y);
		if (x != y)
			p[x] = y;
	}
};

struct ccs {
	basic_string<pair<int, int>> edges;
	basic_string<int> p, cc;
	vector<basic_string<int>> e;

	void add_edge(int x, int y) {
		p += x;
		p += y;
		edges += {x, y};
	}

	void run() {
		sort(p.begin(), p.end());
		int k = unique(p.begin(), p.end()) - p.begin();
		p.resize(k);
		cc.resize(k, 0);
		e.resize(k);
		for (auto [x, y] : edges) {
			x = lower_bound(p.begin(), p.end(), x) - p.begin();
			y = lower_bound(p.begin(), p.end(), y) - p.begin();
			e[x] += y;
			e[y] += x;
		}
		int bcc = 0;
		for (int i=0; i<k; i++) {
			if (cc[i] == 0) {
				cc[i] = ++bcc;
				basic_string<int> q = {i};
				size_t qs = 0;
				while (qs != q.size()) {
					int x = q[qs++];
					for (int y : e[x]) {
						if (!cc[y]) {
							cc[y] = bcc;
							q += y;
						}
					}
				}
			}
		}
	}

	bool same(int x, int y) {
		return cc[x] == cc[y];
	}
};

int n, m, q;
basic_string<grana> e[100005];
vector<dsu> dense;
map<pair<int, int>, int> sparse;

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=0; i<m; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		e[c-1] += {u-1, v-1};
	}

	for (int c=0; c<m; c++) {
		if (e[c].size() > LIMIT) {
			dsu d(n);
			for (auto [u, v] : e[c]) {
				d.merge(u, v);
			}
			dense.push_back(d);
		} else {
			ccs d;
			for (auto [u, v] : e[c]) {
				d.add_edge(u, v);
			}
			d.run();
			for (int i=0; i<(int)d.p.size(); i++) {
				for (int j=i+1; j<(int)d.p.size(); j++) {
					if (d.same(i, j)) {
						sparse[{d.p[i], d.p[j]}]++;
					}
				}
			}
		}
	}

	int q;
	cin >> q;
	while (q--) {
		int x, y;
		cin >> x >> y;
		x--, y--;
		if (x > y)
			swap(x, y);
		int z = sparse[{x, y}];
		for (auto& d : dense) {
			if (d.e(x) == d.e(y)) {
				z++;
			}
		}
		cout << z << '\n';
	}
}
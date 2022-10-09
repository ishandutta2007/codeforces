#include <bits/stdc++.h>
using namespace std;

struct edge {
	int u, v, w, i;
	bool operator< (const edge& other) const {
		return w < other.w;
	}
};

int n, m, q;
vector<edge> e, eo;

struct dsu {
	vector<pair<int*, int>> changes;

	int p[500005], sz[500005];

	int endp(int x) {
		while (x != p[x]) {
			x = p[x];
		}
		return x;
	}

	bool same(int a, int b) {
		return endp(a) == endp(b);
	}

	void merge(int a, int b) {
		a = endp(a);
		b = endp(b);

		if (a == b) {
			return;
		}

		if (sz[a] > sz[b]) {
			swap(a, b);
		}

		changes.push_back({&p[a], p[a]});
		changes.push_back({&sz[b], sz[b]});

		p[a] = b;
		sz[b] = sz[a] + sz[b];
	}

	void roll_back() {
		for (int i=(int)changes.size()-1; i>=0; i--) {
			auto e = changes[i];
			*e.first = e.second;
		}
		changes.clear();
	}

	void commit() {
		changes.clear();
	}
} engine;

bool ok[500005];
vector<pair<int, vector<int>>> attach;

bool edge_w(int a, int b) {
	return e[a].w < e[b].w;
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
		e.push_back({u, v, w, i});
	}

	cin >> q;
	for (int i=1; i<=q; i++) {
		ok[i] = true;
		vector<int> eid;
		int sz;
		cin >> sz;
		eid.resize(sz);
		for (int& x : eid) {
			cin >> x;
			x--;
		}
		sort(eid.begin(), eid.end(), edge_w);
		
		vector<int> g;
		int last = -1;
		for (int x : eid) {
			if (g.size() && e[x].w != e[last].w) {
				g.push_back(i);
				attach.push_back({e[last].w, move(g)});
				g.clear();
			}
			g.push_back(x);
			last = x;
		}

		g.push_back(i);
		attach.push_back({e[last].w, move(g)});
		g.clear();
	}

	eo = e;
	sort(e.begin(), e.end());
	sort(attach.begin(), attach.end());

	for (int i=1; i<=n; i++) {
		engine.p[i] = i;
		engine.sz[i] = 1;
	}

	int lastw = -1;
	for (auto ee : e) {
		if (ee.w != lastw) {
			auto poc = lower_bound(attach.begin(), attach.end(),
				make_pair(ee.w, vector<int>()));
			auto krj = lower_bound(attach.begin(), attach.end(),
				make_pair(ee.w+1, vector<int>()));

			/*
			cerr << "!" << ee.w << ' ' << poc-attach.begin() << ' ' <<
				krj-attach.begin() << '\n';
			*/

			while (poc != krj) {
				auto& v = poc->second;

				int qn = v.back();
				v.pop_back();

				for (auto eid : v) {
					int nu = eo[eid].u;
					int nv = eo[eid].v;

					if (engine.same(nu, nv)) {
						ok[qn] = false;
					} else {
						engine.merge(nu, nv);
					}
				}
				engine.roll_back();
				++poc;
			}
		}
		engine.merge(ee.u, ee.v);
		engine.commit();
		lastw = ee.w;
	}

	for (int i=1; i<=q; i++) {
		cout << (ok[i] ? "YES\n" : "NO\n");
	}
}
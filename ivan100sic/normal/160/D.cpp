#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;

struct edge {
	int u, v, id;
};

int n, m;
basic_string<edge> e[1000005];

struct dsu {
	vector<int> p;

	dsu(int n) : p(n) {
		iota(p.begin(), p.end(), 0);
	}

	int e(int x) {
		if (x == p[x])
			return x;
		return p[x] = e(p[x]);
	}

	bool isti(int x, int y) {
		return e(x) == e(y);
	}

	void spoji(int x, int y) {
		x = e(x), y = e(y);
		if (x == y)
			return;
		p[x] = y;
	}
};

int ans[100005];

struct bridges {
	
	map<int, vector<int>> e;
	map<int, int> g, idx, low;
	set<int> st;
	int t;

	bridges() : t(0) {}

	void add(int u, int v, int i) {
		e[u].push_back(i);
		e[v].push_back(i);
		g[i] = u^v;
		ans[i] = 1;
	}

	void dfs(int x, int i) {
		st.insert(x);
		int& lo = low[x];
		int& id = idx[x];
		id = lo = ++t;
		for (int j : e[x]) {
			if (j == i)
				continue;
			int y = g[j] ^ x;
			if (!idx.count(y)) {
				dfs(y, j);
				lo = min(lo, low[y]);
			} else if (st.count(y)) {
				lo = min(lo, idx[y]);
			}
		}

		if (idx[x] == low[x] && i != -1) {
			ans[i] = 0;
		}
	}

	void run() {
		for (auto& [x, v] : e)
			if (!idx.count(x))
				dfs(x, -1);
	}
};

const string sol[3] = {"any", "at least one", "none"};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cerr.tie(nullptr);

	cin >> n >> m;
	for (int i=0; i<m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		e[w] += {u, v, i};
	}

	dsu d(n+1);

	for (int w=1; w<=1000000; w++) {
		if (e[w].size()) {
			bridges b;
			for (auto [u, v, i] : e[w]) {
				int x = d.e(u);
				int y = d.e(v);
				if (x == y)
					ans[i] = 2;
				else
					b.add(x, y, i);
			}
			b.run();
			for (auto [u, v, i] : e[w])
				d.spoji(u, v);
		}
	}

	for (int i=0; i<m; i++)
		cout << sol[ans[i]] << '\n';
}
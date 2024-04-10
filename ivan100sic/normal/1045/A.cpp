#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
using namespace std;

struct edge {
	int v, cap, flow, next;
};

const int SEGMENTNO = 8192;

struct flow {
	int n, s, t;
	vector<int> start, used, level;
	vector<edge> g;

	flow(int n, int s, int t) : n(n), s(s), t(t),
		start(n, -1) {}

	void add_edge(int x, int y, int capacity) {
		g.push_back({ y, capacity, 0, start[x] });
		start[x] = g.size() - 1;
		g.push_back({ x, 0, 0, start[y] });
		start[y] = g.size() - 1;
	}

	bool bfs() {
		level.assign(n, -1);
		queue<int> q;
		q.push(s);
		level[s] = 0;
		while (q.size()) {
			int x = q.front(); q.pop();
			for (int i = start[x]; i != -1; i = g[i].next) {
				int y = g[i].v;
				if (g[i].flow < g[i].cap && level[y] == -1) {
					level[y] = level[x] + 1;
					q.push(y);
				}
			}
		}

		return level[t] != -1;
	}

	int dfs(int x, int f = 123123213) {
		if (x == t)
			return f;
		for (int& i = used[x]; i != -1; i = g[i].next) {
			int y = g[i].v;
			if (level[y] == level[x] + 1 && g[i].flow < g[i].cap) {
				int z = dfs(y, min(f, g[i].cap - g[i].flow));
				if (z > 0) {
					g[i].flow += z;
					g[i ^ 1].flow -= z;
					return z;
				}
			}
		}
		return 0;
	}

	int run() {
		int f = 0;
		while (bfs()) {
			used = start;
			while (1) {
				int x = dfs(s);
				if (!x)
					break;
				f += x;
			}
		}
		return f;
	}

	vector<int> find_one_path() {
		vector<int> v;
		int x = s;
		while (x != t) {
			v.push_back(x);
			int ok = 0;
			for (int i = start[x]; i != -1; i = g[i].next) {
				if (g[i].flow > 0) {
					g[i].flow -= 1;
					g[i ^ 1].flow += 1;
					x = g[i].v;
					ok = 1;
					break;
				}
			}
			if (!ok)
				return {};
		}
		return v;
	}
};

int n, q;

void get_segtree_nodes(int l, int r, int x, int xl, int xr, vector<int>& v) {
	if (xr < l || r < xl)
		return;
	if (l <= xl && xr <= r) {
		v.push_back(x);
		return;
	}
	
	int xm = (xl + xr) >> 1;

	get_segtree_nodes(l, r, 2 * x + 1, xl, xm, v);
	get_segtree_nodes(l, r, 2 * x + 2, xm + 1, xr, v);
}

vector<int> get_segtree_nodes(int l, int r) {
	vector<int> v;
	get_segtree_nodes(l, r, 0, 0, SEGMENTNO - 1, v);
	return v;
}

int upit(int i) {
	return i;
}

int cvor(int i) {
	return q + i;
}

int bazni_cvor(int i) {
	return q + i + SEGMENTNO - 1;
}

vector<int> matches[5005];
bool glup[5005];
vector<int> glup_v[5005];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);

	cin >> q >> n;

	int sz = 2 * SEGMENTNO + 1 + q;
	int source = sz - 2;
	int sink = sz - 1;
	
	flow e(sz, source, sink);

	// naredjaj segmentno
	for (int i = 1; i < 2 * SEGMENTNO - 1; i++) {
		int j = (i - 1) >> 1;
		e.add_edge(cvor(j), cvor(i), 123123123);
	}

	for (int i = 0; i < n; i++) {
		e.add_edge(bazni_cvor(i), sink, 1);
	}

	for (int i=0; i<q; i++) {
		int t;
		cin >> t;
		if (t == 0) {
			e.add_edge(source, upit(i), 1);
			int c;
			cin >> c;
			while (c--) {
				int x;
				cin >> x;
				x--;
				e.add_edge(upit(i), bazni_cvor(x), 1);
			}
		}
		else if (t == 1) {
			e.add_edge(source, upit(i), 1);
			int l, r;
			cin >> l >> r;
			l--;
			r--;
			auto v = get_segtree_nodes(l, r);
			for (int x : v) {
				e.add_edge(upit(i), cvor(x), 1);
			}
		}
		else {
			glup[i] = 1;
			int x, y, z;
			cin >> x >> y >> z;
			x--;
			y--;
			z--;
			glup_v[i] = { x, y, z };
			e.add_edge(source, upit(i), 2);
			e.add_edge(upit(i), bazni_cvor(x), 1);
			e.add_edge(upit(i), bazni_cvor(y), 1);
			e.add_edge(upit(i), bazni_cvor(z), 1);
		}
	}

	int f = e.run();

	cout << f << '\n';
	
	while (1) {
		auto v = e.find_one_path();
		if (!v.size()) {
			break;
		}

		int upit = -1;
		int cilj = -1;

		for (int x : v) {
			if (x < q) {
				upit = x;
			}
			else if (x >= q + SEGMENTNO - 1 && x < q + SEGMENTNO - 1 + n) {
				cilj = x - (q + SEGMENTNO - 1);
			}
		}

		if (upit != -1 && cilj != -1) {
			matches[upit].push_back(cilj);
		}
	}

	for (int i = 0; i < q; i++) {
		if (glup[i] && matches[i].size() == 1) {
			// uzmi nekog drugog
			int t = glup_v[i][0];
			if (t == matches[i][0])
				t = glup_v[i][1];

			// unmatchuj ga sa drugim i matchuj ga samnom
			for (int j = 0; j < q; j++) {
				auto it = find(matches[j].begin(), matches[j].end(), t);

				if (it != matches[j].end()) {
					matches[j].erase(it);
					matches[i].push_back(t);
					break;
				}
			}
		}
	}

	for (int i = 0; i < q; i++) {
		for (int j : matches[i]) {
			cout << i + 1 << ' ' << j + 1 << '\n';
		}
	}

	// system("pause");

}
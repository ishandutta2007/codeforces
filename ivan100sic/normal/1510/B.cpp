// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

template<class T = int>
struct min_cost_max_flow {
  static constexpr T inf = numeric_limits<T>::max();

	struct edge {
		int v, t;
		T c, w, f;
	};

	vector<vector<edge>> g;
	int n, s, t;
	T f, w;

	min_cost_max_flow(int n, int s, int t) : g(n), n(n), s(s), t(t), f(T()), w(T()) {}

	void add_edge(int u, int v, T c, T w, T f = T()) {
		edge e1 = {v, (int)g[v].size(), c, w, f};
		edge e2 = {u, (int)g[u].size(), 0, -w, -f};
		g[u].push_back(e1);
		g[v].push_back(e2);
	}

	void step(T h = inf) {
		string l(n, 0);
		vector<T> d(n, inf);
		vector<int> p(n), q(n), pe(n);
		int qs = 0, qe = 0;
		q[qe++] = s;
		d[s] = T();
		while (qs != qe) {
			int u = q[qs++];
			if (qs == n) qs = 0;
			l[u] = 2;
			for (size_t i=0; i<g[u].size(); i++) {
				edge& e = g[u][i];
				int v = e.v;
				if (e.f < e.c && d[u] + e.w < d[v]) {
					d[v] = d[u] + e.w;
					if (l[v] == 0) {
						q[qe++] = v;
						if (qe == n) qe = 0;
					} else if (l[v] == 2) {
						if (--qs == -1) {
							qs = n-1;
						}
						q[qs] = v;
					}
					l[v] = 1;
					p[v] = u;
					pe[v] = i;
				}
			}
		}
		if (d[t] == inf) return;
		T a = h;
		int y = t;
		while (y != s) {
			int x = p[y];
			int i = pe[y];
			a = min(a, g[x][i].c - g[x][i].f);
			y = x;
		}
		y = t;
		while (y != s) {
			int x = p[y];
			int i = pe[y];
			int j = g[x][i].t;
			g[x][i].f += a;
			g[y][j].f -= a;
			w += g[x][i].w * a;
			y = x;
		}
		f += a;
	}

	void operator()(T l = inf) {
		while (1) {
			T o = f;
			step(l - f);
			cerr << "step " << f << ' ' << w << '\n';
			if (o == f) return;
		}
	}
};

int k, n;
int c[1024];

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  cin >> k >> n;
  for (int i=0; i<n; i++) {
    string s;
    cin >> s;
    int z = 0;
    for (int i=0; i<k; i++) {
      z += (s[i] - '0') << i;
    }
    c[z] = 1;
  }

	basic_string<int> sol;

	const int dump = 2 << k;
	const int sink = dump + 1;
	const int twin = 1 << k;
	min_cost_max_flow<ll> e(sink + 1, 0, sink);

	// source edges
	for (int i=0; i<k; i++) {
		e.add_edge(0, 1 << i, 123123, 2);
	}
	e.add_edge(0, dump, 123123, 0);

	// mid edges
	for (int i=1; i<twin; i++) {
		for (int j=0; j<k; j++) {
			if (!bitset<10>(i)[j]) {
				e.add_edge(i + twin * c[i], i + (1 << j), 123123, 1);
			}
		}
		e.add_edge(i, dump, 123123, 0);
		if (c[i]) {
			e.add_edge(i, i + twin, 1, -0x10000);
			e.add_edge(i, i + twin, 123123, 0);
			e.add_edge(i + twin, dump, 123123, 0);
		}
	}

	// sink edges
	e.add_edge(dump, sink, 123123, 0);

	e();

	auto go = [&](int x) {
		for (int j=0; j<(int)e.g[x].size(); j++) {
			auto& h = e.g[x][j];
			if (h.c > 0 && h.f > 0) {
				h.f -= 1;
				return h.v;
			}
		}
		return -1;
	};

	while (1) {
		int x = 0, c = 0, dun = 0;
		while (1) {
			int y = go(x);
			if (y == -1) {
				dun = 1;
				break;
			}
			if (y == dump) break;
			c++;
			if (y < twin) {
				sol += 31 - __builtin_clz(y - (x & (twin - 1)));
			}
			x = y;
		}
		if (c) sol += -1;
		if (dun) break;
	}

	sol.pop_back();
  cout << sol.size() << '\n';
  for (int x : sol) {
    if (x == -1) {
      cout << "R ";
    } else {
      cout << x << ' ';
    }
  }
  cout << '\n';
}
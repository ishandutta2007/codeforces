// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

template<class T = int>
struct max_flow {
	struct edge {
		int next, v;
		T cap, flow;
	};

	int s, t;
	vector<int> start, level, used, q;
	vector<edge> g;

	max_flow(int n, int s, int t) : s(s), t(t), start(n, -1), level(n, -1), used(n, -1), q(n) {}

  void ap(int x, int y) {
    if ((x/2+(x%2)) % 2) {
      swap(x, y);
    }
    add_edge(x, y, 1);
  }

	void add_edge(int u, int v, T cap, T rev = T()) {
		g.push_back({start[u], v, cap, T()});
		start[u] = g.size() - 1;
		g.push_back({start[v], u, rev, T()});
		start[v] = g.size() - 1;
	}

	bool bfs(int s, int t) {
		size_t qs = 0, qe = 1;
		fill(level.begin(), level.end(), -1);
		q[0] = s;
		level[s] = 0;
		while (qs != qe) {
			int x = q[qs++];
			for (int i = start[x]; i != -1; i = g[i].next) {
				if (g[i].flow < g[i].cap && level[g[i].v] == -1) {
					level[g[i].v] = level[x] + 1;
					q[qe++] = g[i].v;
				}
			}
		}
		return level[t] != -1;
	}

	T dfs(int x, int t, T f) {
		if (x == t)
			return f;
		for (int& i = used[x]; i != -1; i = g[i].next) {
			int v = g[i].v;
			if (level[v] == level[x] + 1 && g[i].flow < g[i].cap) {
				T z = dfs(v, t, min(f, g[i].cap - g[i].flow));
				if (z > 0) {
					g[i].flow += z;
					g[i^1].flow -= z;
					return z;
				}
			}
		}
		return T();
	}

	T operator() () {
		T f = T();
		while (bfs(s, t)) {
			used = start;
			while (1) {
				T z = dfs(s, t, numeric_limits<T>::max());
				f += z;
				if (!z) break;
			}
		}
		return f;
	}
};

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    vector<pair<int, int>> a(m+4);
    for (int i=0; i<m; i++) {
      cin >> a[i].second >> a[i].first;
    }

    a[m+0] = {0, 1};
    a[m+1] = {0, 2};
    a[m+2] = {n+1, 1};
    a[m+3] = {n+1, 2};

    m += 4;

    sort(begin(a), end(a));

    int decr = 0;

    for (int i=1; i<m; i++) {
      int f = a[i].first - decr - a[i-1].first;
      if (f >= 4) {
        decr += (f-2)/2*2;
      }
      a[i].first -= decr;

      // cerr << "fixed " << a[i].first << ' ' << a[i].second << '\n';
    }

    int w = a[m-1].first + 1;
    // cerr << "w = " << w << '\n';

    vector<int> ok(w, 3);
    for (auto [x, y] : a) {
      ok[x] -= 1 << (y-1);
    }

    max_flow<int> e(2*w+2, 2*w, 2*w+1);
    for (int i=0; i<w; i++) {
      // izmedju
      if (ok[i] == 3) {
        e.ap(2*i, 2*i+1);
      }

      // preko
      if (i > 0) {
        if (ok[i] & ok[i-1] & 1) {
          e.ap(2*i, 2*i-2);
        }

        if (ok[i] & ok[i-1] & 2) {
          e.ap(2*i+1, 2*i-1);
        }
      }

      for (int j=0; j<2; j++) {
        if (ok[i] & (1 << j)) {
          if ((i+j) % 2 == 0) {
            e.add_edge(2*w, 2*i+j, 1);
          } else {
            e.add_edge(2*i+j, 2*w+1, 1);
          }
        }
      }
    }

    if (e()*2 == 2*w-m) {
      cout << "YES\n";
    } else {
      cout << "NO\n";
    }
  }
}
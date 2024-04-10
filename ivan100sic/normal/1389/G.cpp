// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

template<class T, class D, class E, class G, class U, class F = plus<D>>
struct tree_dp {
	vector<T> a;
	D e;
	vector<D> up, dn, rt;
	F f;
	G g;
  U u;
	vector<pair<int, E>*> p;
	vector<vector<pair<int, E>>> h;

  // a : vertex array - typed T
  // b : array of edges - typed E
  // g : (D, T) -> D - extends the sum of subtrees with the root vertex
  // u : (D, E) -> D - extends a subtree with an edge
  // e : neutral element of D
  // f : (D, D) -> D - adds together two (extended) subtrees
	tree_dp(const vector<T>& a, const vector<tuple<int, int, E>>& b, G g, U u, D e = D(), F f = F()) :
    a(a), e(e), up(a.size()), dn(a.size()), f(f), g(g), u(u), p(a.size()), h(a.size())
  {
    for (auto [x, y, z] : b) {
      h[x].emplace_back(y, z);
      h[y].emplace_back(x, z);
    }
    dfs1(0, 0);
    dfs2(0);
    rt.resize(a.size());
		rt[0] = dn[0];
		for (int x=1; x<(int)a.size(); x++) {
			D d = u(up[x], p[x]->second);
      for (auto& hh : h[x]) {
        auto& [y, w] = hh;
        if (y != p[x]->first)
          d = f(d, u(dn[y], w));
      }
			rt[x] = g(d, a[x]);
		}
  }

  D operator() (int x) { return rt[x]; }

	void dfs1(int x, int o) {
		D d = e;
		for (auto& hh : h[x]) {
      auto& [y, w] = hh;
      if (y == o) {
        p[x] = &hh;
        continue;
      }
			dfs1(y, x);
			d = f(d, u(dn[y], w));
		}
		dn[x] = g(d, a[x]);
	}

	void dfs2(int x) {
		D d = x ? u(up[x], p[x]->second) : e, t = e;
		int m = h[x].size() - !!x;
		vector<D> pref(m, e);
		int i = 0;
		for (auto& hh : h[x]) {
      auto& [y, w] = hh;
			if (p[x] && p[x]->first == y) continue;
			pref[i++] = t;
			t = f(t, u(dn[y], w));
		}
		for (int j=(int)h[x].size()-1; j>=0; j--) {
      auto& hh = h[x][j];
      auto& [y, w] = hh;
			if (p[x] && p[x]->first == y) continue;
			i--;
			up[y] = g(f(pref[i], d), a[x]);
			d = f(d, u(dn[y], w));
		}
    for (auto& hh : h[x]) {
      auto& [y, w] = hh;
			if (p[x] && p[x]->first == y) continue;
      dfs2(y);
		}
	}
};

struct graf2 {
  int n;
  vector<int> spec;
  vector<ll> c;
  vector<tuple<int, int, int>> e;
};

namespace G {
  int n, m, k;
  int spec[300005], c[300005], w[300005];
  vector<pair<int, int>> e[300005];

  void rdi() {
    cin >> n >> m >> k;

    for (int i=0; i<k; i++) {
      int x;
      cin >> x;
			x--;
      spec[x]++;
    }

    for (int i=0; i<n; i++) {
      cin >> c[i];
    }

    for (int i=0; i<m; i++) {
      cin >> w[i];
    }

    for (int i=0; i<m; i++) {
      int u, v;
      cin >> u >> v;
      u--, v--;
      e[u].emplace_back(v, w[i]);
      e[v].emplace_back(u, w[i]);
    }
  }

  int idx[300005], low[300005], dt;
  int comp[300005];
  vector<int> st;

  graf2 g2;

  pair<int, ll> dfs(int x, int p, int pw) {
    idx[x] = low[x] = ++dt;
    st.push_back(x);
    pair<int, ll> rez = {spec[x], c[x]};
    for (auto [y, w] : e[x]) {
      if (y == p) {
        continue;
      }

      if (!idx[y]) {
        auto [i, j] = dfs(y, x, w);
        rez.first += i;
        rez.second += j;
        low[x] = min(low[x], low[y]);
      } else {
        low[x] = min(low[x], idx[y]);
      }
    }

    if (idx[x] == low[x]) {
      while (1) {
				int b = st.back();
				st.pop_back();
				comp[b] = g2.n;
        if (b == x) {
          break;
        }
      }

      g2.n++;
      g2.spec.push_back(rez.first);
      g2.c.push_back(rez.second);
      if (x != p) {
        g2.e.emplace_back(x, p, pw);
      }

      return {0, 0};
    } else {
      return rez;
    }
  }

  graf2 resi() {
		dfs(0, 0, 0);
    for (auto& [x, y, w] : g2.e) {
      x = comp[x];
      y = comp[y];
    }
    return move(g2);
  }
}

struct nodeval {
  ll c;
  int spec;
};

const ll inf = 2e18;

struct subtree {
  // treba za usputnu sumu/sume
	ll cpsummmax0satmw = 0;
  ll cpsumsat = 0;
  ll c0sumsa = 0;
  ll cpmaxsa = -inf;
  int spec = 0;
	int cpcard = 0;
  // treba samo za javnost
  ll sa = 0;
	// za krajnji rezultat
	ll sat = 0;

  subtree operator+ (const subtree& b) const {
    subtree rez;
		rez.cpsummmax0satmw = cpsummmax0satmw + b.cpsummmax0satmw;
    rez.cpsumsat = cpsumsat + b.cpsumsat;
    rez.c0sumsa = c0sumsa + b.c0sumsa;
		rez.cpmaxsa = max(cpmaxsa, b.cpmaxsa);
    rez.cpcard = cpcard + b.cpcard;
    rez.spec = spec + b.spec;

    return rez;
  }
};

subtree edge_extend(const subtree& st, int w) {
  subtree rez;

  rez.spec = st.spec;

  if (st.spec > 0) {
		rez.cpsummmax0satmw += max(0ll, st.sat - w);
    rez.cpsumsat += st.sat;
    rez.cpmaxsa = st.sa; // implicit max
		rez.cpcard = 1;
  } else {
    rez.c0sumsa += st.sa;
  }

  return rez;
}

subtree vertex_extend(const subtree& st, nodeval root) {
  ll root_cost = root.c;
  int root_spec = root.spec;

  subtree rez;
  rez.spec = st.spec + root_spec;
	rez.sat = st.cpsummmax0satmw + st.c0sumsa + root_cost;
  rez.sa = max(rez.sat, st.cpmaxsa);

	if (st.spec == G::k && st.cpcard == 1) {
		rez.sat = max(rez.sat, st.cpsumsat + st.c0sumsa + root_cost);
	}

  return rez;
}

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  G::rdi();
  graf2 g2 = G::resi();

  vector<nodeval> nv(g2.n);
  for (int i=0; i<g2.n; i++) {
    nv[i] = {g2.c[i], g2.spec[i]};
  }

  tree_dp dp(nv, g2.e, vertex_extend, edge_extend, subtree{});

  for (int i=0; i<G::n; i++) {
    cout << dp(G::comp[i]).sat << " \n"[i == G::n-1];
  }
}
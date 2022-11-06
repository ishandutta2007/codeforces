// Author:  HolyK
// Created: Tue Mar  8 22:22:24 2022
#include <bits/stdc++.h>

template <class T, class U>
inline bool smin(T &x, const U &y) {
  return y < x ? x = y, 1 : 0;
}
template <class T, class U>
inline bool smax(T &x, const U &y) {
  return x < y ? x = y, 1 : 0;
}

using LL = long long;
using PII = std::pair<int, int>;

struct Dsu {
  std::vector<int> f;
  void clear() {
    std::iota(f.begin(), f.end(), 0);
  } 
  Dsu(int n) : f(n) { clear(); }
  int find(int x) {
    while (x != f[x]) {
      x = f[x] = f[f[x]];
    }
    return x;
  }
  bool same(int x, int y) {
    return find(x) == find(y);
  }
  bool merge(int x, int y) {
    return !same(x, y) ? f[find(x)] = find(y), true : false;
  }
};

struct KT {
  std::vector<int> dep, val;
  std::vector<std::vector<int>> f;
  KT(int n, std::vector<std::array<int, 3>> e)
    : dep(n * 2), val(n * 2), f(std::__lg(n * 2) + 1, std::vector<int>(n * 2, -1)) {
    std::sort(e.begin(), e.end());
    Dsu d(n * 2);
    int cur = n;
    for (auto &[z, x, y] : e) {
      x = d.find(x), y = d.find(y);
      if (x == y) continue;
      d.merge(x, cur), d.merge(y, cur);
      f[0][x] = f[0][y] = cur;
      val[cur] = z;
      cur++;
    }
    assert(cur + 1 == n * 2);

    for (int i = cur - 1; i >= 0; i--) {
      dep[i] = ~f[0][i] ? dep[f[0][i]] + 1 : 0;
    }

    for (int i = 1; i < f.size(); i++) {
      for (int j = 0; j < cur; j++) {
        int k = f[i - 1][j];
        f[i][j] = ~k ? f[i - 1][k] : -1;
      }
    }
  }

  int get(int x, int y) {
    if (dep[x] < dep[y]) std::swap(x, y);
    for (int i = 0; dep[x] != dep[y]; i++) {
      if (dep[x] - dep[y] >> i & 1) {
        x = f[i][x];
      }
    }
    if (x != y) {
      for (int i = f.size() - 1; i >= 0; i--) {
        if (f[i][x] != f[i][y]) {
          x = f[i][x];
          y = f[i][y];
        }
      }
      x = f[0][x];
    }
    return val[x];
  }
};

template <class T>
struct Fenwick {
  std::vector<T> c;
  Fenwick(int n) : c(n) {}
  void clear() { std::fill(c.begin(), c.end(), 0); }
  void add(int p, T x) {
    for (; p < c.size(); p |= p + 1) c[p] += x;
  }
  T ask(int p) {
    T r = 0;
    for (; p; p &= p - 1) r += c[p - 1];
    return r;
  }
  T ask(int l, int r) { return ask(r) - ask(l); }

  int find(T k) {
    int p = 0;
    for (int i = 1 << 18; i; i >>= 1) {
      if (p + i <= c.size() && c[p + i - 1] < k) {
        k -= c[p + i - 1];
        p += i;
      }
    }
    return p;
  }
};

void solve() {
  int n, m;
  std::cin >> n >> m;
  std::vector<std::array<int, 3>> e(m), ee;
  for (auto &[z, x, y] : e) {
    std::cin >> x >> y >> z;
    x--, y--;
  }

  KT kt1(n, e);

  std::vector<std::vector<int>> g(n * 2);
  for (int i = 0; i < n * 2 - 1; i++) {
    if (~kt1.f[0][i]) {
      g[kt1.f[0][i]].push_back(i);
    }
  }

  std::vector<int> in(n), id(n);
  int cnt = 0;
  std::function<void(int)> dfs = [&](int x) {
    if (x < n) in[x] = cnt, id[cnt++] = x;
    for (int y : g[x]) dfs(y);
  };

  dfs(n * 2 - 2);

  g.assign(n, std::vector<int>());
  for (auto &[z, x, y] : e) {
    g[x].push_back(y);
    g[y].push_back(x);
  }

  Dsu d(n);
  while (ee.size() < n - 1) {
    std::vector<std::vector<int>> it(n);
    Fenwick<int> fen(n);

    for (int i = 1; i <= n; i++) {
      fen.c[i - 1] = i & -i;
    }
    
    for (int i = 0; i < n; i++) it[d.find(i)].push_back(i);
    std::vector<int> vis(n, -1);
    decltype(e) p; 
    for (int i = 0; i < n; i++) {
      if (d.find(i) != i) continue;
      for (int x : it[i]) fen.add(in[x], -1), vis[x] = i;
      p.push_back({INT_MAX, -1, -1});
      for (int x : it[i]) {
        for (int y : g[x]) {
          if (vis[y] == i) continue;
          fen.add(in[y], -1);
        }
        int k = fen.ask(in[x]);
        if (k) {
          int y = id[fen.find(k)];
          smin(p.back(), std::array<int, 3>{kt1.get(x, y), x, y});
        }
        int y = fen.find(k + 1);
        if (y < n) {
          y = id[y];
          smin(p.back(), std::array<int, 3>{kt1.get(x, y), x, y});
        }
        for (int y : g[x]) {
          if (vis[y] == i) continue;
          fen.add(in[y], 1);
        }
      }
      for (int x : it[i]) fen.add(in[x], 1);
    }

    
    for (auto &[z, x, y] : p) {
      assert(~x && ~y);
      if (!d.merge(x, y)) continue;
      ee.push_back({z, x, y});
    }
  }

  KT kt2(n, ee);
  for (auto &[z, x, y] : e) {
    std::cout << kt2.get(x, y) << " ";
  }
  std::cout << "\n";
}

int main() {
  // freopen("t.in", "r", stdin);
  
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  int t = 1;
  
  std::cin >> t;
  
  while (t--) {
    solve();
  }
  return 0;
}
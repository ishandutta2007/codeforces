// Author:  HolyK
// Created: Wed Aug  3 21:49:50 2022
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

constexpr int N(1e5 + 5);
int n, m, in[N], out[N], st[17][N], lg[N];
std::vector<int> g[N];
void dfs(int x, int p) {
  st[0][in[0]] = p;
  in[x] = ++in[0];
  for (int y : g[x]) {
    if (y == p) continue;
    dfs(y, x);
  }
  out[x] = in[0];
}

int get(int i, int j) {
  return in[i] < in[j] ? i : j;
}
int lca(int x, int y) {
  if (x == y) return x;
  x = in[x], y = in[y];
  if (x > y) std::swap(x, y);
  int k = lg[y - x];
  return get(st[k][x], st[k][y - (1 << k)]);
}
void init() {
  for (int i = 2; i <= n; i++) lg[i] = lg[i >> 1] + 1;
  for (int i = 1; i < 17; i++) {
    for (int j = 1; j + (1 << i) <= n; j++) {
      st[i][j] = get(st[i - 1][j], st[i - 1][j + (1 << i - 1)]);
    }
  }
}

int a[N];
LL c[N][2];
void add(int p, int x) {
  LL v[2] = {x, 1LL * p * x};
  for (; p <= n; p += p & -p) {
    c[p][0] += v[0];
    c[p][1] += v[1];
  }
}
LL ask(int n) {
  LL r = 0;
  for (int p = n; p; p -= p & -p) {
    r += c[p][0] * (n + 1) - c[p][1];
  }
  return r;
}
int jmp(int x, int y) {
  x = in[x];
  for (int i = 16; i >= 0; i--) {
    int p = in[y] - (1 << i);
    if (x < p && x < in[st[i][p]]) {
      y = st[i][p];
    }
  }
  return y;
}
void solve() {
  std::cin >> n >> m;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  for (int i = 1, x, y; i < n; i++) {
    std::cin >> x >> y;
    g[x].push_back(y);
    g[y].push_back(x);
  }

  dfs(1, 0);
  init();

  for (int i = 1; i <= n; i++) {
    add(in[i], a[i]);
    add(in[i] + 1, -a[i]);
  }
  
  int r = 1;
  while (m--) {
    int opt, x, y;
    std::cin >> opt >> x;
    if (opt == 1) {
      r = x;
    } else if (opt == 2) {
      std::cin >> y;
      x = lca(x, y) ^ lca(x, r) ^ lca(y, r);
      std::cin >> y;
      if (x == r) {
        add(1, y);
      } else if (in[x] <= in[r] && out[r] <= out[x]) {
        int u = jmp(x, r);
        add(1, y);
        add(in[u], -y);
        add(out[u] + 1, y);
      } else {
        add(in[x], y);
        add(out[x] + 1, -y);
      }
    } else {
      LL ans;
      if (x == r) {
        ans = ask(n);
      } else if (in[x] <= in[r] && out[r] <= out[x]) {
        int u = jmp(x, r);
        ans = ask(n) - ask(out[u]) + ask(in[u] - 1);
      } else {
        ans = ask(out[x]) - ask(in[x] - 1);
      }
      std::cout << ans << "\n";
    }
  }
}

int main() {
  // freopen("t.in", "r", stdin);
  
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  int t = 1;
  
  // std::cin >> t;
  
  while (t--) {
    solve();
  }
  return 0;
}
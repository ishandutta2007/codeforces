// Author:  HolyK
// Created: Tue Sep  6 14:20:14 2022
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

#define ls o << 1
#define rs o << 1 | 1
constexpr int N(5e5 + 5), L(19), S(1 << L);
int n, m, q, f[50][N], s[50][N], d[50][N];
PII find(int k, int x) {
  int r = 0;
  while (x != f[k][x]) {
    r ^= d[k][x];
    x = f[k][x];
  }
  return {x, r};
}

PII e[N];
int c[N];
std::vector<int> g[S * 2];

void add(int l, int r, int x) {
  for (l += S, r += S; l < r; l >>= 1, r >>= 1) {
    if (l & 1) g[l++].push_back(x);
    if (r & 1) g[--r].push_back(x);
  }
}

PII st[N], op[N];
int top;
void dfs(int o, int l, int r) {
  int cur = top;
  for (int i : g[o]) {
    if (c[i] == -1) continue;
    auto [x, y] = e[i];
    int k = c[i], wx, wy;
    std::tie(x, wx) = find(k, x);
    std::tie(y, wy) = find(k, y);
    if (x == y) continue;
    if (s[k][x] > s[k][y]) std::swap(x, y);
    f[k][x] = y;
    s[k][y] += s[k][x];
    d[k][x] = wx ^ wy ^ 1;
    st[++top] = {k, x};
  }
  
  if (r - l == 1) {
    if (l < q) {
      auto [i, k] = op[l];
      auto [x, y] = e[i];
      int wx, wy;
      std::tie(x, wx) = find(k, x);
      std::tie(y, wy) = find(k, y);
      if (x != y || x == y && wx != wy) {
        c[i] = k;
        std::cout << "YES\n";
      } else {
        std::cout << "NO\n";
      }
    }
  } else {
    int m = l + r >> 1;
    dfs(ls, l, m), dfs(rs, m, r);
  }

  while (top > cur) {
    auto &&[k, x] = st[top--];
    s[k][f[k][x]] -= s[k][x];
    f[k][x] = x;
  }
}

void solve() {
  int k;
  std::cin >> n >> m >> k >> q;
  for (int i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    e[i] = {x, y};
  }

  std::vector<int> last(m, -1);
  
  for (int i = 0; i < q; i++) {
    int x, y;
    std::cin >> x >> y;
    x--, y--;
    op[i] = {x, y};
    if (last[x] != -1) {
      add(last[x] + 1, i, x);
    }
    last[x] = i;
  }

  for (int i = 0; i < m; i++) {
    if (last[i] != -1) {
      add(last[i] + 1, q, i);
    }
  }

  for (int i = 0; i < k; i++) {
    for (int j = 0; j <= n; j++) {
      f[i][j] = j;
      s[i][j] = 1;
    }
  }

  for (int i = 0; i < m; i++) c[i] = -1;
  
  dfs(1, 0, S);
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
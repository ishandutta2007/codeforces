// Author:  HolyK
// Created: Fri Feb 25 20:50:48 2022
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

constexpr int N(1e5 + 5), T(512);

int b[N];
std::vector<int> g[N << 2];
#define ls o * 2
#define rs o * 2 + 1
void pushup(int o) {
  g[o].clear();
  int i = 0, j = 0;
  while (i < g[ls].size() || j < g[rs].size()) {
    if (j == g[rs].size() || i < g[ls].size() && i + g[ls][i] < g[rs][j]) {
      g[o].push_back(g[ls][i++]);
    } else {
      g[o].push_back(g[rs][j++] - i);
    }
  }
}
void build(int o, int l, int r) {
  if (l == r) {
    g[o] = {b[l]};
    return;
  }
  int m = l + r >> 1;
  build(ls, l, m), build(rs, m + 1, r);
  if (r - l + 1 <= T) pushup(o);
}
void update(int o, int l, int r, int x) {
  if (l == r) {
    g[o] = {b[l]};
    return;
  }
  int m = l + r >> 1;
  x <= m ? update(ls, l, m, x) : update(rs, m + 1, r, x);
  if (r - l + 1 <= T) pushup(o);
}
void ask(int o, int l, int r, int x, int y, int &z) {
  if (x <= l && r <= y && r - l + 1 <= T) {
    z += std::upper_bound(g[o].begin(), g[o].end(), z) - g[o].begin();
    return;
  }
  int m = l + r >> 1;
  if (x <= m) ask(ls, l, m, x, y, z);
  if (y > m) ask(rs, m + 1, r, x, y, z);
}

void solve() {
  int n;
  std::cin >> n;
  for (int i = 1; i <= n; i++) {
    std::cin >> b[i];
    b[i] = i - b[i];
  }

  build(1, 1, n);
  
  int q;
  std::cin >> q;
  while (q--) {
    int opt, x;
    std::cin >> opt >> x;
    if (opt == 1) {
      std::cin >> b[x];
      b[x] = x - b[x];
      update(1, 1, n, x);
    } else {
      if (x == n) {
        std::cout << b[x] << "\n";
      } else {
        int ans = b[x];
        ask(1, 1, n, x + 1, n, ans);
        std::cout << ans << "\n";
      }
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
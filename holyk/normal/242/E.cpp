// Author:  HolyK
// Created: Fri May 20 18:29:15 2022
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
#define ls o << 1
#define rs o << 1 | 1

int c[N << 2][20][2], tag[N << 2];

void pushup(int o) {
  for (int i = 0; i < 20; i++) {
    c[o][i][0] = c[ls][i][0] + c[rs][i][0];
    c[o][i][1] = c[ls][i][1] + c[rs][i][1];
  }
}

void build(int o, int l, int r) {
  if (l == r) {
    int x;
    std::cin >> x;
    for (int i = 0; i < 20; i++) {
      c[o][i][x >> i & 1]++;
    }
    return;
  }
  int m = l + r >> 1;
  build(ls, l, m), build(rs, m + 1, r);
  pushup(o);
}

void apply(int o, int x) {
  tag[o] ^= x;
  for (int i = 0; i < 20; i++) {
    if (x >> i & 1) std::swap(c[o][i][0], c[o][i][1]);
  }
}
void pushdown(int o) {
  if (tag[o]) {
    apply(ls, tag[o]), apply(rs, tag[o]);
    tag[o] = 0;
  }
}

void update(int o, int l, int r, int x, int y, int z) {
  if (x <= l && r <= y) return apply(o, z);
  int m = l + r >> 1;
  pushdown(o);
  if (x <= m) update(ls, l, m, x, y, z);
  if (y > m) update(rs, m + 1, r, x, y, z);
  pushup(o);
}
LL ask(int o, int l, int r, int x, int y) {
  if (r < x || y < l) return 0;
  if (x <= l && r <= y) {
    LL ans = 0;
    for (int i = 0; i < 20; i++) {
      ans += (LL)c[o][i][1] << i;
    }
    return ans;
  }
  int m = l + r >> 1;
  pushdown(o);
  return ask(ls, l, m, x, y) + ask(rs, m + 1, r, x, y);
}

void solve() {
  int n;
  std::cin >> n;
  build(1, 1, n);
  int m;
  std::cin >> m;
  while (m--) {
    int opt, l, r;
    std::cin >> opt >> l >> r;
    if (opt == 1) {
      std::cout << ask(1, 1, n, l, r) << "\n";
    } else {
      int x;
      std::cin >> x;
      update(1, 1, n, l, r, x);
    }
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t = 1;
  // std::cin >> t;
  while (t--) solve();
  return 0;
}
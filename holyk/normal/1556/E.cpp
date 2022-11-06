// Author:  HolyK
// Created: Sun Aug 29 23:45:46 2021
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
int a[N];
LL pre[17][N];
struct Info {
  LL s, l, r, t;
  Info operator+(const Info &v) const {
    return {s + v.s, std::max(l, s + v.l), std::max(v.r, v.s + r), std::max({t, v.t, r + v.l})};
  }
} ;
std::array<Info, 2> t[N << 2];
std::array<Info, 2> operator+(const std::array<Info, 2> &a, const std::array<Info, 2> &b) {
  return {a[0] + b[0], a[1] + b[1]};
}
#define ls o << 1
#define rs o << 1 | 1
void pushup(int o) {
  t[o] = t[ls] + t[rs];
}
void build(int o, int l, int r) {
  if (l == r) {
    t[o][0] = {a[l], 0, 0, 0};
    t[o][1] = {-a[l], 0, 0, 0};
    if (a[l] > 0) {
      t[o][0].l = t[o][0].r = t[o][0].t = a[l];
    } else {
      t[o][1].l = t[o][1].r = t[o][1].t = -a[l];
    }
    return;
  }
  int m = l + r >> 1;
  build(ls, l, m), build(rs, m + 1, r);
  pushup(o);
}
std::array<Info, 2> ask(int o, int l, int r, int x, int y) {
  if (x <= l && r <= y) return t[o];
  int m = l + r >> 1;
  if (y <= m) return ask(ls, l, m, x, y);
  if (x > m) return ask(rs, m + 1, r, x, y);
  return ask(ls, l, m, x, y) + ask(rs, m + 1, r, x, y);
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n, q;
  std::cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  for (int i = 1, x; i <= n; i++) {
    std::cin >> x;
    a[i] -= x;
    pre[0][i] = pre[0][i - 1] + a[i];
  }
  for (int i = 1; i < 17; i++) {
    for (int j = 1 << i; j <= n; j++) {
      pre[i][j] = std::max(pre[i - 1][j], pre[i - 1][j - (1 << i - 1)]);
    }
  }
  build(1, 1, n);
  while (q--) {
    int l, r;
    std::cin >> l >> r;
    if (pre[0][r] != pre[0][l - 1]) {
      std::cout << "-1\n";
      continue;
    }
    int k = std::__lg(r - l + 1);
    if (std::max(pre[k][r], pre[k][l + (1 << k) - 1]) > pre[0][l - 1]) {
      std::cout << "-1\n";
      continue;
    }
    auto v = ask(1, 1, n, l, r);
    std::cout << std::max(std::abs(v[0].t), std::abs(v[1].t)) << "\n";
  }
  return 0;
}
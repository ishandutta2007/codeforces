// Author:  HolyK
// Created: Fri May 20 20:54:23 2022
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
struct Info {
  LL m1, m2, a;
} t[N << 2];
Info operator+(Info a, Info b) {
  return {std::max(a.m1, b.m1), std::max(a.m2, b.m2), std::max({a.a, b.a, a.m2 + b.m1})};
}

#define ls o << 1
#define rs o << 1 | 1
Info ask(int o, int l, int r, int x, int y) {
  if (x <= l && r <= y) return t[o];
  int m = l + r >> 1;
  if (y <= m) return ask(ls, l, m, x, y);
  if (x > m) return ask(rs, m + 1, r, x, y);
  return ask(ls, l, m, x, y) + ask(rs, m + 1, r, x, y);
}

LL s[N], h[N];

void build(int o, int l, int r) {
  if (l == r) {
    t[o] = {h[l] + s[l], h[l] - s[l], LLONG_MIN};
    return;
  }
  int m = l + r >> 1;
  build(ls, l, m), build(rs, m + 1, r);
  t[o] = t[ls] + t[rs];
}

void solve() {
  int n, m;
  std::cin >> n >> m;
  for (int i = 1; i <= n; i++) std::cin >> s[i + 1], s[i + 1] += s[i];
  for (int i = 1; i <= n; i++) std::cin >> h[i], h[i] *= 2;
  build(1, 1, n);

  while (m--) {
    int x, y;
    std::cin >> x >> y;
    if (x <= y) {
      if (x == 1) {
        std::cout << ask(1, 1, n, y + 1, n).a << "\n";
      } else if (y == n) {
        std::cout << ask(1, 1, n, 1, x - 1).a << "\n";
      } else {
        Info u = ask(1, 1, n, 1, x - 1), v = ask(1, 1, n, y + 1, n);
        std::cout << std::max({u.a, v.a, u.m1 + s[n + 1] + v.m2}) << "\n";
      }
    } else {
      std::cout << ask(1, 1, n, y + 1, x - 1).a << "\n";
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
// Author:  HolyK
// Created: Tue Sep  7 15:01:41 2021
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

constexpr int N(2e5 + 5);
int n, q, a[N];
struct Info {
  int s, l, r;
  LL ans;
  friend inline Info operator+(Info a, Info b) {
    return {
      a.s + b.s,
      a.l == a.s ? a.s + b.l : a.l,
      b.r == b.s ? b.s + a.r : b.r,
      a.ans + b.ans + 1LL * a.r * b.l
    };
  }
} t[N << 2];
#define ls o << 1
#define rs o << 1 | 1
void update(int o, int l, int r, int x, int y) {
  if (l == r) {
    t[o].s = 1;
    t[o].l = t[o].r = t[o].ans = y;
    return;
  }
  int m = l + r >> 1;
  x <= m ? update(ls, l, m, x, y) : update(rs, m + 1, r, x, y);
  t[o] = t[ls] + t[rs];
}
Info ask(int o, int l, int r, int x, int y) {
  if (x <= l && r <= y) return t[o];
  int m = l + r >> 1;
  if (y <= m) return ask(ls, l, m, x, y);
  if (x > m) return ask(rs, m + 1, r, x, y);
  return ask(ls, l, m, x, y) + ask(rs, m + 1, r, x, y);
}
int main() {
  // freopen("t.in", "r", stdin);
  // freopen(".out", "w", stdout);
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cin >> n >> q;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  for (int i = 2; i <= n; i++) {
    update(1, 2, n, i, a[i] - a[i - 1] >= 0);
  }
  while (q--) {
    int opt, x, y;
    std::cin >> opt >> x >> y;
    if (opt == 1) {
      a[x] = y;
      if (x > 1) update(1, 2, n, x, a[x] - a[x - 1] >= 0);
      if (x < n) update(1, 2, n, x + 1, a[x + 1] - a[x] >= 0);
    } else {
      LL res = y - x + 1;
      if (res > 1) res += ask(1, 2, n, x + 1, y).ans;
      std::cout << res << "\n";
    }
  }
  return 0;
}
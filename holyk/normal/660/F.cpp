// Author:  HolyK
// Created: Wed Nov  3 10:40:30 2021
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
#define int long long
struct Line {
  int k;
  LL b;
  LL f(LL x) {
    return 1LL * k * x + b;
  }
} t[N << 2];
#define ls o << 1
#define rs o << 1 | 1
LL a[N];
int m;
void ins(int o, int l, int r, Line x) {
  int m = l + r >> 1;
  bool lv = x.f(a[l]) > t[o].f(a[l]), mv = x.f(a[m]) > t[o].f(a[m]), rv = x.f(a[r]) > t[o].f(a[r]);
  if (mv) std::swap(x, t[o]);
  if (lv == rv || l == r) return;
  lv != mv ? ins(ls, l, m, x) : ins(rs, m + 1, r, x);
}
LL ask(int o, int l, int r, int x) {
  int m = l + r >> 1;
  if (x == m) return t[o].f(a[x]);
  return std::max(t[o].f(a[x]), x < m ? ask(ls, l, m, x) : ask(rs, m + 1, r, x));
}

LL s[N], si[N];

signed main() {
  // freopen("t.in", "r", stdin);
  // freopen(".out", "w", stdout);
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n;
  std::cin >> n;
  LL ans = 0;
  for (int i = 1; i <= n; i++) {
    std::cin >> s[i];
    si[i] = si[i - 1] + s[i] * i;
    s[i] += s[i - 1];
    a[i] = s[i];
  }
  
  std::sort(a, a + 1 + n);
  m = std::unique(a, a + 1 + n) - a;
  // ins(1, 0, m, {0, 0});
  for (int i = 1; i <= n; i++) {
    smax(ans, ask(1, 0, m - 1, std::lower_bound(a, a + m, s[i]) - a) + si[i]);
    ins(1, 0, m - 1, {-i, i * s[i] - si[i]});
  }
  std::cout << ans << "\n";
  return 0;
}
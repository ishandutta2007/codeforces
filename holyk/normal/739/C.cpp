// Author:  HolyK
// Created: Thu Nov  4 16:13:29 2021
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

int n;
LL a[1 << 20];

struct Info {
  std::array<int, 4> l, r;
  int ans, len;
  friend Info operator+(const Info &a, const Info &b) {
    Info c;
    c.ans = std::max(a.ans, b.ans);
    c.l[0] = a.l[0] == a.len ? a.len + b.l[0] : a.l[0];
    c.l[3] = a.l[3] == a.len ? a.len + b.l[3] : a.l[3];
    c.r[0] = b.r[0] == b.len ? b.len + a.r[0] : b.r[0];
    c.r[3] = b.r[3] == b.len ? b.len + a.r[3] : b.r[3];
    
    for (int i = 1; i < 3; i++) {
      c.l[i] = a.l[i], c.r[i] = b.r[i];
      for (int j = 0; j < 2; j++) {
        int u = i & 2 | j, v = j << 1 | i & 1;
        if (a.len == a.l[u]) smax(c.l[i], a.len + b.l[v]);
        if (b.len == b.r[v]) smax(c.r[i], b.len + a.r[u]);
        if (i == 1) smax(c.ans, a.r[u] + b.l[v]);
      }
    }
    c.len = a.len + b.len;
    return c;
  }
  void init(LL x) {
    if (x > 0) {
      l.fill(1), r.fill(1);
      l[3] = r[3] = 0;
      ans = 1;
    } else if (x < 0) {
      l.fill(1), r.fill(1);
      l[0] = r[0] = 0;
      ans = 1;
    } else {
      l.fill(0), r.fill(0);
      ans = 0;
    }
    len = 1;
  }
} t[1 << 20];

int main() {
  // freopen("t.in", "r", stdin);
  // freopen(".out", "w", stdout);
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cin >> n;
  for (int i = 0; i < n; i++) std::cin >> a[i];
  for (int i = n - 1; i; i--) a[i] -= a[i - 1];
  a[0] = 0;
  int s = 1 << std::__lg(n * 2 - 1);
  for (int i = 0; i < s; i++) {
    t[i + s].init(a[i]);
  }
  for (int i = s - 1; i; i--) {
    t[i] = t[i * 2] + t[i * 2 + 1];
  }
  
  int m;
  std::cin >> m;
  while (m--) {
    int l, r, x;
    std::cin >> l >> r >> x;
    l--;
    if (l) {
      t[l + s].init(a[l] += x);
      for (l = l + s >> 1; l; l >>= 1) {
        t[l] = t[l * 2] + t[l * 2 + 1];
      }
    }
    if (r < n) {
      t[r + s].init(a[r] -= x);
      for (r = r + s >> 1; r; r >>= 1) {
        t[r] = t[r * 2] + t[r * 2 + 1];
      }
    }
    std::cout << 1 + t[1].ans << "\n";
  }
  
  return 0;
}
// Author:  HolyK
// Created: Thu Nov  4 17:06:18 2021
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

struct Info {
  std::array<int, 4> l, r, sum;
  int ans;
  friend Info operator+(const Info &a, const Info &b) {
    Info c;
    c.ans = std::max(a.ans, b.ans);
    c.l[0] = std::max(a.l[0], a.sum[0] + b.l[0]);
    c.l[3] = std::max(a.l[3], a.sum[3] + b.l[3]);
    c.r[0] = std::max(b.r[0], b.sum[0] + a.r[0]);
    c.r[3] = std::max(b.r[3], b.sum[3] + a.r[3]);
    c.sum[0] = a.sum[0] + b.sum[0];
    c.sum[1] = std::max(a.sum[0] + b.sum[1], a.sum[1] + b.sum[3]);
    c.sum[2] = std::max(a.sum[2] + b.sum[0], a.sum[3] + b.sum[2]);
    c.sum[3] = a.sum[3] + b.sum[3];
    
    for (int i = 1; i < 3; i++) {
      c.l[i] = a.l[i], c.r[i] = b.r[i];
      for (int j = 0; j < 2; j++) {
        int u = i & 2 | j, v = j << 1 | i & 1;
        smax(c.l[i], a.sum[u] + b.l[v]);
        smax(c.r[i], b.sum[v] + a.r[u]);
        if (i == 2) smax(c.ans, a.r[u] + b.l[v]);
      }
    }
    return c;
  }
  void init(char c) {
    l.fill(1), r.fill(1), sum.fill(1);
    ans = 1;
    if (c == '(') {
      l[3] = r[3] = 0;
      sum[3] = -1;
    } else {
      l[0] = r[0] = 0;
      sum[0] = -1;
    }
  }
} t[1 << 20];


int main() {
  // freopen("t.in", "r", stdin);
  // freopen(".out", "w", stdout);
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n, m;
  std::string a;
  
  std::cin >> n >> m >> a;
  n = a.length();
  
  int s = 1 << std::__lg(n * 2 - 1);
  for (int i = 0; i < n; i++) {
    t[i + s].init(a[i]);
  }
  
  for (int i = s - 1; i; i--) {
    t[i] = t[i * 2] + t[i * 2 + 1];
  }
  std::cout << t[1].ans << "\n";
  
  while (m--) {
    int x, y;
    std::cin >> x >> y;
    x--, y--;
    std::swap(a[x], a[y]);
    t[x + s].init(a[x]);
    t[y + s].init(a[y]);
    for (x = x + s >> 1; x; x >>= 1) {
      t[x] = t[x * 2] + t[x * 2 + 1];
    }
    for (y = y + s >> 1; y; y >>= 1) {
      t[y] = t[y * 2] + t[y * 2 + 1];
    }
    // std::cout << a << " ";
    std::cout << t[1].ans << "\n";
  }
  return 0;
}
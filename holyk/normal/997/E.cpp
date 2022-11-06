// Author:  HolyK
// Created: Mon Nov  8 08:55:17 2021
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

constexpr int N(1.2e5 + 5);


struct Info {
  int x, c;
  friend Info operator+(const Info &a, const Info &b) {
    if (a.x == b.x) return {a.x, a.c + b.c};
    return a.x < b.x ? a : b;
  }
  
  void add(int u) {
    x += u;
  }
  
} t[N << 2];

int add[N << 2], fwd[N << 2];
LL sum[N << 2];

#define ls o << 1
#define rs o << 1 | 1

void applyAdd(int o, int x) {
  t[o].add(x);
  add[o] += x;
}

void applyFwd(int o, int x) {
  sum[o] += 1LL * x * t[o].c;
  fwd[o] += x;
}

void pushdown(int o) {
  if (add[o]) {
    applyAdd(ls, add[o]), applyAdd(rs, add[o]);
    add[o] = 0;
  }
  
  if (fwd[o]) {
    if (t[o].x == t[ls].x) applyFwd(ls, fwd[o]);
    if (t[o].x == t[rs].x) applyFwd(rs, fwd[o]);
    fwd[o] = 0;
  }
}

void pushup(int o) {
  t[o] = t[ls] + t[rs];
  sum[o] = sum[ls] + sum[rs];
}

void rangeAdd(int o, int l, int r, int x, int y, int z) {
  if (x <= l && r <= y) return applyAdd(o, z);
  int m = l + r >> 1;
  pushdown(o);
  if (x <= m) rangeAdd(ls, l, m, x, y, z);
  if (y > m) rangeAdd(rs, m + 1, r, x, y, z);
  pushup(o);
}

LL ask(int o, int l, int r, int x, int y) {
  if (r < x || y < l) return 0;
  if (x <= l && r <= y) return sum[o];
  int m = l + r >> 1;
  pushdown(o);
  return ask(ls, l, m, x, y) + ask(rs, m + 1, r, x, y);
}

void build(int o, int l, int r) {
  if (l == r) {
    t[o] = {l, 1};
    return;
  }
  int m = l + r >> 1;
  build(ls, l, m), build(rs, m + 1, r);
  pushup(o);
}

int a[N];
std::vector<PII> g[N];

int main() {
  // freopen("t.in", "r", stdin);
  // freopen(".out", "w", stdout);
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n, m;
  std::cin >> n;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
  }
  
  build(1, 1, n);
  
  std::cin >> m;
  std::vector<LL> ans(m);
  for (int i = 0; i < m; i++) {
    int x, y;
    std::cin >> x >> y;
    g[y].push_back({x, i});
  }

  // std::cerr << "???\n";
  static int s1[N], t1, s2[N], t2;
  for (int i = 1; i <= n; i++) {

    for (; t1 && a[s1[t1]] < a[i]; t1--) {
      rangeAdd(1, 1, n, s1[t1 - 1] + 1, s1[t1], -a[s1[t1]]);
    }
    for (; t2 && a[s2[t2]] > a[i]; t2--) {
      rangeAdd(1, 1, n, s2[t2 - 1] + 1, s2[t2], a[s2[t2]]);
    }

    rangeAdd(1, 1, n, s1[t1] + 1, i, a[i]);
    rangeAdd(1, 1, n, s2[t2] + 1, i, -a[i]);
    
    s1[++t1] = s2[++t2] = i;
    applyFwd(1, 1);

    for (auto [l, id] : g[i]) {
      ans[id] = ask(1, 1, n, l, i);
    }
  }
  
  for (LL x : ans) std::cout << x << "\n";
  return 0;
}
// Author:  HolyK
// Created: Fri May 20 15:35:46 2022
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
struct Node {
  int ls, rs, cov, min;
} t[N * 60];
int cnt, mark;
void copy(int &o) {
  if (o <= mark) {
    t[++cnt] = t[o], o = cnt;
  }
}
void apply(int o, int x) {
  t[o].cov = t[o].min = x;
}
void pushdown(int &o) {
  if (t[o].cov) {
    copy(t[o].ls), copy(t[o].rs);
    apply(t[o].ls, t[o].cov);
    apply(t[o].rs, t[o].cov);
    t[o].cov = 0;
  }
}
void pushup(int o) {
  t[o].min = std::min(t[t[o].ls].min, t[t[o].rs].min);
}

int n, m, q;
void update2(int &o, int l, int r, int x, int y, int z) {
  copy(o);
  if (x <= l && r <= y) return apply(o, z);
  pushdown(o);
  int m = l + r >> 1;
  if (x < m) update2(t[o].ls, l, m, x, y, z);
  if (y > m) update2(t[o].rs, m, r, x, y, z);
  pushup(o);
}
void update1(int &o, int l, int r, int x, int y, int z) {
  if (r - l == 1) return update2(o, 0, n, x - l * n, y - l * n, z);
  if (x <= l * n && r * n <= y) return apply(o, z);

  pushdown(o);
  int m = l + r >> 1;
  if (x < m * n) update1(t[o].ls, l, m, x, y, z);
  if (y > m * n) update1(t[o].rs, m, r, x, y, z);
  pushup(o);
}

int ask2(int &o, int l, int r, int x, int y) {
  if (r <= x || y <= l) return INT_MAX;
  if (x <= l && r <= y) return t[o].min;
  pushdown(o);
  int m = l + r >> 1;
  return std::min(ask2(t[o].ls, l, m, x, y), ask2(t[o].rs, m, r, x, y));
}
int ask1(int &o, int l, int r, int x, int y) {
  if (r * n <= x || y <= l * n) return INT_MAX;
  if (x <= l * n && r * n <= y) return t[o].min;
  if (r - l == 1) return ask2(o, 0, n, x - l * n, y - l * n);
  pushdown(o);
  int m = l + r >> 1;
  return std::min(ask1(t[o].ls, l, m, x, y), ask1(t[o].rs, m, r, x, y));
}

int a[N];
void build2(int &o, int l, int r) {
  o = ++cnt;
  if (r - l == 1) {
    t[o].min = a[l];
    return;
  }
  int m = l + r >> 1;
  build2(t[o].ls, l, m), build2(t[o].rs, m, r);
  pushup(o);
}
void build1(int &o, int l, int r) {
  o = ++cnt;
  if (r - l == 1) {
    o = 1;
    return;
  }
  int m = l + r >> 1;
  build1(t[o].ls, l, m), build1(t[o].rs, m, r);
  pushup(o);
}

void solve() {
  std::cin >> n >> m;
  for (int i = 0; i < n; i++) std::cin >> a[i];
  int o;
  build2(o, 0, n);
  mark = cnt;
  build1(o, 0, m);

  std::cin >> q;
  while (q--) {
    int t, l, r, x;
    std::cin >> t >> l >> r;
    l--;
    if (t == 1) {
      std::cin >> x;
      update1(o, 0, m, l, r, x);
    } else {
      std::cout << ask1(o, 0, m, l, r) << "\n";
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
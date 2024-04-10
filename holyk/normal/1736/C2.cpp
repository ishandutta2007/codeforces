// Author:  HolyK
// Created: Tue Oct 11 00:47:59 2022
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

#define ls o << 1
#define rs o << 1 | 1

constexpr int N(2e5 + 5);
int min[N << 2];
LL ans[N << 2];
LL ask(int o, int l, int r, int x) {
  if (l == r) return std::min(min[o], x) - l;
  int m = l + r >> 1;
  return x >= min[rs] ? ans[o] + ask(rs, m + 1, r, x) : ask(ls, l, m, x) + LL(r - m) * x - LL(r - m) * (m + 1 + r) / 2;
}
void pushup(int o, int l, int r) {
  min[o] = std::min(min[ls], min[rs]);
  ans[o] = ask(ls, l, l + r >> 1, min[rs]);
  // std::cerr << l << " " << r << " " << ans[o] << "\n";
}
void update(int o, int l, int r, int x, int y) {
  if (l == r) {
    min[o] = y;
    return;
  }
  int m = l + r >> 1;
  if (x <= m) {
    update(ls, l, m, x, y);
  } else {
    update(rs, m + 1, r, x, y);
  }
  pushup(o, l, r);
}

int n, a[N];
std::set<int> s[N];
int get(int x) {
  return s[x].empty() ? n + 1 : *s[x].begin();
}
void add(int x, int y) {
  if (x <= 0) return;
  s[x].insert(y);
  update(1, 1, n, x, get(x));
}
void del(int x, int y) {
  if (x <= 0) return;
  s[x].erase(y);
  update(1, 1, n, x, get(x));
}

void build(int o, int l, int r) {
  if (l == r) {
    min[o] = get(l);
    return;
  }
  int m = l + r >> 1;
  build(ls, l, m);
  build(rs, m + 1, r);
  pushup(o, l, r);
}
void solve() {
  std::cin >> n;
  for (int i = 1; i <= n; i++) {
    std::cin >> a[i];
    if (i - a[i] > 0) s[i - a[i]].insert(i);
  }
  build(1, 1, n);
  int q;
  std::cin >> q;
  while (q--) {
    int i, x;
    std::cin >> i >> x;
    del(i - a[i], i), add(i - x, i);
    std::cout << ask(1, 1, n, n + 1) << "\n";
    del(i - x, i), add(i - a[i], i);
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
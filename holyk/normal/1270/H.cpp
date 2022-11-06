// Author:  HolyK
// Created: Fri Jul 29 19:59:00 2022
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

constexpr int N(5e5 + 5);
#define ls o << 1
#define rs o << 1 | 1
int min[N << 2], max[N << 2], vl[N << 2], vr[N << 2];
int query(int o, int l, int r, int x, int y) {
  if (l == r || x <= y || x <= min[o] || max[o] <= y) return 0;
  int ans = std::min(min[ls], x) > std::max(max[rs], y), m = l + r >> 1;
  ans += x >= max[ls] && y < max[rs] ? vl[o] : query(ls, l, m, x, std::max(y, max[rs]));
  ans += y <= min[rs] && x > min[ls] ? vr[o] : query(rs, m + 1, r, std::min(x, min[ls]), y);
  return ans;
}
void pushup(int o, int l, int r) {
  min[o] = std::min(min[ls], min[rs]);
  max[o] = std::max(max[ls], max[rs]);
  int m = l + r >> 1;
  vl[o] = query(ls, l, m, 1e9, max[rs]);
  vr[o] = query(rs, m + 1, r, min[ls], 0);
}

void init(int o, int x) {
  min[o] = max[o] = x;
  vl[o] = vr[o] = 0;
}

void build(int o, int l, int r) {
  if (l == r) {
    int x;
    std::cin >> x;
    init(o, x);
    return;
  }
  int m = l + r >> 1;
  build(ls, l, m), build(rs, m + 1, r);
  pushup(o, l, r);
}

void update(int o, int l, int r, int x, int y) {
  if (l == r) return init(o, y);
  int m = l + r >> 1;
  if (x <= m) {
    update(ls, l, m, x, y);
  } else {
    update(rs, m + 1, r, x, y);
  }
  pushup(o, l, r);
}

void solve() {
  int n, q;
  std::cin >> n >> q;
  build(1, 1, n);
  
  while (q--) {
    int i, x;
    std::cin >> i >> x;
    update(1, 1, n, i, x);
    std::cout << query(1, 1, n, 1e9, 0) + 1 << "\n";
  }
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t = 1;
  while (t--) solve();
  return 0;
}
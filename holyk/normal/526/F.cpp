// Author:  HolyK
// Created: Fri Nov  5 14:33:24 2021
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

constexpr int N(3e5 + 5);
struct Info {
  int min, cnt;
  friend Info operator+(const Info &a, const Info &b) {
    if (a.min == b.min) {
      return {a.min, a.cnt + b.cnt};
    }
    return a.min < b.min ? a : b;
  }
} t[N << 2];
int add[N << 2];

#define ls o << 1
#define rs o << 1 | 1

void apply(int o, int x) {
  add[o] += x;
  t[o].min += x;
}

void pushdown(int o) {
  if (add[o]) {
    apply(ls, add[o]), apply(rs, add[o]);
    add[o] = 0;
  }
}

void pushup(int o) {
  t[o] = t[ls] + t[rs];
}

void rangeAdd(int o, int l, int r, int x, int y, int z) {
  if (x <= l && r <= y) return apply(o, z);
  int m = l + r >> 1;
  pushdown(o);
  if (x <= m) rangeAdd(ls, l, m, x, y, z);
  if (y > m) rangeAdd(rs, m + 1, r, x, y, z);
  pushup(o);
}

void build(int o, int l, int r) {
  if (l == r) {
    t[o] = {l, 1};
    return ;
  }
  int m = l + r >> 1;
  build(ls, l, m), build(rs, m + 1, r);
  pushup(o);
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n;
  std::cin >> n;
  build(1, 1, n);
  static int a[N];
  for (int i = 1; i <= n; i++) {
    int x, y;
    std::cin >> x >> y;
    a[x] = y;
  }
  
  static int s1[N], t1, s2[N], t2;
  LL ans = 0;
  for (int i = 1; i <= n; i++) {
    for (; t1 && a[i] < a[s1[t1]]; t1--) {
      rangeAdd(1, 1, n, s1[t1 - 1] + 1, s1[t1], a[s1[t1]]);
    }
    for (; t2 && a[i] > a[s2[t2]]; t2--) {
      rangeAdd(1, 1, n, s2[t2 - 1] + 1, s2[t2], -a[s2[t2]]);
    }
    
    rangeAdd(1, 1, n, s1[t1] + 1, i, -a[i]);
    rangeAdd(1, 1, n, s2[t2] + 1, i, a[i]);
    s1[++t1] = s2[++t2] = i;
    
    apply(1, -1);
    // std::cerr << t[1].min << "\n";
    assert(t[1].min == 0);
    ans += t[1].cnt;
  }
  std::cout << ans << "\n";
  return 0;
}
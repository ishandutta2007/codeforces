// Author:  HolyK
// Created: Thu Jul  8 17:54:59 2021
#include <bits/stdc++.h>
#define dbg(a...) fprintf(stderr, a)
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
int min[N << 2], max[N << 2], tag[N << 2];
#define ls o << 1
#define rs o << 1 | 1
void add(int o, int x) {
  min[o] += x;
  max[o] += x;
  tag[o] += x;
}
void pushdown(int o) {
  if (tag[o]) {
    add(ls, tag[o]);
    add(rs, tag[o]);
    tag[o] = 0;
  }
}
void pushup(int o) {
  min[o] = std::min(min[ls], min[rs]);
  max[o] = std::max(max[ls], max[rs]);
}
void update(int o, int l, int r, int x, int y, int z) {
  if (x <= l && r <= y) return add(o, z);
  int m = l + r >> 1;
  pushdown(o);
  if (x <= m) update(ls, l, m, x, y, z);
  if (y > m) update(rs, m + 1, r, x, y, z);
  pushup(o);
}
int askMin(int o, int l, int r, int x, int y) {
  if (r < x || y < l) return 1e6;
  if (x <= l && r <= y) return min[o];
  int m = l + r >> 1;
  pushdown(o);
  return std::min(askMin(ls, l, m, x, y), askMin(rs, m + 1, r, x, y));
}
int askMax(int o, int l, int r, int x, int y) {
  if (r < x || y < l) return -1e6;
  if (x <= l && r <= y) return max[o];
  int m = l + r >> 1;
  pushdown(o);
  return std::max(askMax(ls, l, m, x, y), askMax(rs, m + 1, r, x, y));
}
void build(int o, int l, int r) {
  tag[o] = 0;
  if (l == r) {
    min[o] = max[o] = l + 1;
    return;
  }
  int m = l + r >> 1;
  build(ls, l, m), build(rs, m + 1, r);
  pushup(o);
}
std::vector<int> g[N];
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n;
  std::cin >> n;
  std::vector<int> a(n), b(n);
  for (int i = 0; i < n; i++) {
    std::cin >> a[i];
    g[a[i]].push_back(i);
  }
  build(1, 0, n - 1);
  std::vector<int> ans(n);
  for (int x = 1; x <= n; x++) {
    
    for (int i : g[x]) {
      ans[i] = (askMax(1, 0, n - 1, i, n - 1) - std::min(0, askMin(1, 0, n - 1, 0, i - 1))) >> 1;
    }
    for (int i : g[x]) {
      update(1, 0, n - 1, i, n - 1, -2);
    }
    for (int i : g[x]) {
      smax(ans[i], (-askMin(1, 0, n - 1, i, n - 1) + std::max(0, askMax(1, 0, n - 1, 0, i - 1)) + 1 >> 1) - 1);
    }
    
    
  }
  for (int x : ans) std::cout << x << " ";
  return 0;
}
/*
5
5 4 3 2 1

7
3 6 5 6 2 1 3

 */
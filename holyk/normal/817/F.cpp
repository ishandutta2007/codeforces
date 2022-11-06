// Author:  HolyK
// Created: Fri May 20 14:04:23 2022
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
#define ls o << 1
#define rs o << 1 | 1
struct Node {
  bool col[2], cov[2], f;
} t[N << 2];
void cover(int o, int x) {
  t[o].col[x] = t[o].cov[x] = true;
  t[o].col[!x] = t[o].cov[!x] = false;
  t[o].f = false;
}
void flip(int o) {
  std::swap(t[o].col[0], t[o].col[1]);
  std::swap(t[o].cov[0], t[o].cov[1]);
  t[o].f = !t[o].cov[0] && !t[o].cov[1] && !t[o].f;
}
void pushup(int o) {
  t[o].col[0] = t[ls].col[0] || t[rs].col[0];
  t[o].col[1] = t[ls].col[1] || t[rs].col[1];
}
void pushdown(int o) {
  if (t[o].cov[0]) {
    cover(ls, 0), cover(rs, 0), t[o].cov[0] = false;
  }
  
  if (t[o].cov[1]) {
    cover(ls, 1), cover(rs, 1), t[o].cov[1] = false;
  }

  if (t[o].f) {
    flip(ls), flip(rs), t[o].f = false;
  }
}

void rangeFlip(int o, int l, int r, int x, int y) {
  if (x <= l && r <= y) {
    return flip(o);
  }
  pushdown(o);
  int m = l + r >> 1;
  if (x < m) rangeFlip(ls, l, m, x, y);
  if (y > m) rangeFlip(rs, m, r, x, y);
  pushup(o);
}
void rangeCover(int o, int l, int r, int x, int y, int z) {
  if (x <= l && r <= y) {
    return cover(o, z);
  }
  pushdown(o);
  int m = l + r >> 1;
  if (x < m) rangeCover(ls, l, m, x, y, z);
  if (y > m) rangeCover(rs, m, r, x, y, z);
  pushup(o);  
}

int dfs(int o, int l, int r) {
  if (r - l == 1) return l;
  pushdown(o);
  int m = l + r >> 1;
  return t[ls].col[0] ? dfs(ls, l, m) : dfs(rs, m, r);
}

void solve() {
  int n;
  std::cin >> n;
  std::vector<int> t(n);
  std::vector<LL> a(n * 2 + 1), l(n), r(n);
  for (int i = 0; i < n; i++) {
    std::cin >> t[i] >> l[i] >> r[i];
    smax(l[i], 1);
    a[i * 2] = l[i];
    a[i * 2 + 1] = ++r[i];
  }
  a.back() = 1;
  std::sort(a.begin(), a.end());
  a.erase(std::unique(a.begin(), a.end()), a.end());

  int m = a.size();
  cover(1, 0);
  for (int i = 0; i < n; i++, std::cout << a[dfs(1, 0, m)] << "\n") {
    if (l[i] >= r[i]) continue;

    l[i] = std::lower_bound(a.begin(), a.end(), l[i]) - a.begin();
    r[i] = std::lower_bound(a.begin(), a.end(), r[i]) - a.begin();

    if (t[i] == 1) {
      rangeCover(1, 0, m, l[i], r[i], 1);
    } else if (t[i] == 2) {
      rangeCover(1, 0, m, l[i], r[i], 0);
    } else {
      rangeFlip(1, 0, m, l[i], r[i]);
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
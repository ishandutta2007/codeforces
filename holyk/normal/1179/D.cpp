// Author:  HolyK
// Created: Sat May 22 15:41:42 2021
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

constexpr int N(5e5 + 5);

int n, siz[N], fa[N];
std::vector<int> g[N];
LL n2, f[N], h[N], ans;
LL sqr(int x) {
  return 1LL * x * x;
}
void dfs(int x) {
  siz[x] = 1;
  for (int y : g[x]) {
    if (y == fa[x]) continue;
    fa[y] = x;
    dfs(y);
    siz[x] += siz[y];
  }
}
struct Line {
  int k;
  LL b;
  LL f(int x) {
    return 1LL * k * x + b;
  }
} t[N << 2];
int clr[N << 2], cnt;
#define ls o << 1
#define rs o << 1 | 1
void ins(int o, int l, int r, Line x) {
  if (clr[o] != cnt) clr[o] = cnt, t[o] = {0, 0};
  int m = l + r >> 1;
  bool lv = x.f(l) > t[o].f(l), mv = x.f(m) > t[o].f(m), rv = x.f(r) > t[o].f(r);
  if (mv) std::swap(x, t[o]);
  if (lv == rv || l == r) return;
  lv != mv ? ins(ls, l, m, x) : ins(rs, m + 1, r, x);
}
LL ask(int o, int l, int r, int x) {
  if (clr[o] != cnt) clr[o] = cnt, t[o] = {0, 0};
  int m = l + r >> 1;
  if (x == m) return t[o].f(x);
  return std::max(t[o].f(x), x < m ? ask(ls, l, m, x) : ask(rs, m + 1, r, x));
}
void dfs2(int x) {
  h[x] = f[x] + sqr(siz[x]);
  for (int y : g[x]) {
    if (y == fa[x]) continue;
    f[y] = f[x] + sqr(siz[x] - siz[y]);
    dfs2(y);
    smin(h[x], h[y]);
  }
  cnt++;
  for (int y : g[x]) {
    if (y == fa[x]) continue;
    LL b = 1LL * siz[y] * (n * 2 - siz[y]) - (h[y] - f[y]);
    // dbg("b : %lld\n", b);
    smax(ans, ask(1, 1, n, siz[y]) + b);
    ins(1, 1, siz[x], {-2 * siz[y], b});
  }
  // dbg("f[%d] = %lld, h = %lld\n", x, f[x], h[x]);
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cin >> n;
  n2 = sqr(n);
  for (int i = 1; i < n; i++) {
    int x, y;
    std::cin >> x >> y;
    g[x].push_back(y), g[y].push_back(x);
  }
  dfs(1), dfs2(1);
  std::cout << 1LL * n * (n - 1) / 2 + ans / 2 << "\n";
  return 0;
}
/*
2
1 2

4
1 2
1 3
1 4

6
1 2
1 3
3 4
3 5
4 6
 */
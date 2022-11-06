#include <bits/stdc++.h>
#define perr(a...) fprintf(stderr, a)
#define dbg(a...) perr("\033[32;1m"), perr(a), perr("\033[0m")
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
struct Data {
  int x, c;
};
Data merge(Data a, Data b) {
  if (a.x == b.x) return {a.x, a.c + b.c};
  if (a.c < b.c) return {b.x, b.c - a.c};
  return {a.x, a.c - b.c};
}
Data t[N << 2];
#define ls o << 1
#define rs o << 1 | 1
inline void pushup(int o) {
  t[o] = merge(t[ls], t[rs]);
}
int a[N];
void build(int o, int l, int r) {
  if (l == r) {
    t[o] = {a[l], 1};
    return;
  }
  int m = l + r >> 1;
  build(ls, l, m), build(rs, m + 1, r);
  pushup(o);
}
Data ask(int o, int l, int r, int x, int y) {
  if (x <= l && r <= y) {
    return t[o];
  }
  int m = l + r >> 1;
  if (y <= m) return ask(ls, l, m, x, y);
  if (x > m) return ask(rs, m + 1, r, x, y);
  return merge(ask(ls, l, m, x, y), ask(rs, m + 1, r, x, y));
}
std::vector<int> p[N];
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n, m;
  std::cin >> n >> m;
  for (int i = 1; i <= n; i++) std::cin >> a[i], p[a[i]].push_back(i);
  build(1, 1, n);
  while (m--) {
    int l, r;
    std::cin >> l >> r;
    int x = ask(1, 1, n, l, r).x;
    int c = std::upper_bound(p[x].begin(), p[x].end(), r) - std::lower_bound(p[x].begin(), p[x].end(), l);
    std::cout << std::max(1, 2 * c - (r - l + 1)) << "\n";
  }
  return 0;
}
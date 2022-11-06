#include <bits/stdc++.h>
#define dbg(...) std::cerr << "\033[32;1m", fprintf(stderr, __VA_ARGS__), std::cerr << "\033[0m";
template <class T, class U>
inline bool smin(T &x, const U &y) { return y < x ? x = y, 1 : 0; }
template <class T, class U>
inline bool smax(T &x, const U &y) { return x < y ? x = y, 1 : 0; }

using LL = long long;
using PII = std::pair<int, int>;

constexpr int N(1e5 + 5);
int n, m, a[N];
struct Node {
  std::vector<int> v;
  int min;
} t[N << 2];
#define ls o << 1
#define rs o << 1 | 1
void build(int o, int l, int r) {
  t[o].min = 1e9;
  if (l == r) {
    t[o].v = { a[l] };
    return;
  }
  int m = l + r >> 1;
  build(ls, l, m), build(rs, m + 1, r);
  t[o].min = 1e9;
  t[o].v.resize(r - l + 1);
  std::merge(t[ls].v.begin(), t[ls].v.end(), t[rs].v.begin(), t[rs].v.end(), t[o].v.begin());
}
int now;
void update(int o, int l, int r, int x) {
  if (r < x) {
    auto it = std::upper_bound(t[o].v.begin(), t[o].v.end(), a[x]);
    if (it != t[o].v.end()) {
      smin(t[o].min, *it - a[x]);
    }
    if (it != t[o].v.begin()) {
      smin(t[o].min, a[x] - *--it);
    }
    if (now <= t[o].min) {
      return;
    }
    if (l == r) {
      smin(now, t[o].min);
      return;
    }
  }
  int m = l + r >> 1;
  if (m < x - 1) {
    update(rs, m + 1, r, x);
  }
  update(ls, l, m, x);
  smin(t[o].min, t[ls].min);
  smin(t[o].min, t[rs].min);
  smin(now, t[o].min);
}
int ask(int o, int l, int r, int x, int y) {
  if (x > r || y < l) {
    return 1e9;
  }
  if (x <= l && r <= y) {
    return t[o].min;
  }
  int m = l + r >> 1;
  return std::min(ask(ls, l, m, x, y), ask(rs, m + 1, r, x, y));
}
std::vector<PII> q[N];
int ans[N * 3];
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cin >> n;
  for (int i = 1; i <= n; i++) std::cin >> a[i];
  build(1, 1, n);
  std::cin >> m;
  for (int i = 1; i <= m; i++) {
    int x, y; std::cin >> x >> y;
    q[y].emplace_back(x, i);
  }
  for (int i = 2; i <= n; i++) {
    now = 1e9;
    update(1, 1, n, i);
    for (auto [x, t] : q[i]) {
      ans[t] = ask(1, 1, n, x, i);
    }
  }
  for (int i = 1; i <= m; i++) {
    std::cout << ans[i] << "\n";
  }
  return 0;
}
#include <bits/stdc++.h>
#define dbg(...) std::cerr << "\033[32;1m", fprintf(stderr, __VA_ARGS__), std::cerr << "\033[0m";
template <class T, class U>
inline bool smin(T &x, const U &y) { return y < x ? x = y, 1 : 0; }
template <class T, class U>
inline bool smax(T &x, const U &y) { return x < y ? x = y, 1 : 0; }

using LL = long long;
using PII = std::pair<int, int>;

constexpr int N(1e6 + 5);
int n, a[N], p[N], id[N];
std::vector<int> g[N];

int fa[N], siz[N];
inline int find(int x) {
  while (fa[x] != x) x = fa[x] = fa[fa[x]];
  return x;
}
LL ans;
void solve() {
  std::iota(p + 1, p + 1 + n, 1);
  std::iota(fa + 1, fa + 1 + n, 1);
  std::fill(siz + 1, siz + 1 + n, 1);
  std::sort(p + 1, p + 1 + n, [](int i, int j) { return a[i] < a[j]; });
  for (int i = 1; i <= n; i++) id[p[i]] = i;
  for (int i = 1; i <= n; i++) {
    int x = p[i], v = a[x];
    for (int y : g[x]) {
      if (id[y] > i) continue;
      x = find(x), y = find(y);
      ans += 1LL * siz[x] * siz[y] * v;
      if (siz[x] > siz[y]) std::swap(x, y);
      siz[y] += siz[x], fa[x] = y;
    }
  }
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cin >> n;
  for (int i = 1; i <= n; i++) std::cin >> a[i];
  for (int i = 1, x, y; i < n; i++) {
    std::cin >> x >> y;
    g[x].push_back(y), g[y].push_back(x);
  }
  solve();
  for (int i = 1; i <= n; i++) a[i] = -a[i];
  solve();
  std::cout << ans;
  return 0;
}
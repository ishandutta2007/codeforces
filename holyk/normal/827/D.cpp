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

constexpr int N(2e5 + 5);
struct Dsu {
  std::vector<int> f;
  Dsu(int n) : f(n) {
    std::iota(f.begin(), f.end(), 0);
  }
  int find(int x) {
    while (x != f[x]) x = f[x] = f[f[x]];
    return x;
  }
  bool same(int x, int y) {
    return find(x) == find(y);
  }
  bool merge(int x, int y) {
    return same(x, y) ? false : f[find(x)] = find(y);
  }
};
int n, val[N], dep[N], up[20][N], max[20][N];
std::vector<int> g[N];
std::vector<std::array<int, 4>> e;
void dfs(int x) {
  for (int i : g[x]) {
    int y = e[i][1] ^ e[i][2] ^ x;
    if (y == up[0][x]) continue;
    dep[y] = dep[x] + 1;
    up[0][y] = x;
    max[0][y] = e[i][0];
    val[y] = e[i].back();
    dfs(y);
  }
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  std::cin >> n;
  int m;
  std::cin >> m;
  e.resize(m);
  for (int i = 0; i < m; i++) {
    std::cin >> e[i][1] >> e[i][2] >> e[i][0];
    e[i][3] = i;
  }
  std::sort(e.begin(), e.end());
  Dsu d(n + 1);
  for (int i = 0; i < m; i++) {
    auto [z, x, y, id] = e[i];
    if (d.same(x, y)) continue;
    d.merge(x, y);
    g[x].push_back(i), g[y].push_back(i);
  }
  dfs(1);
  for (int i = 1; i < 20; i++) {
    for (int j = 1; j <= n; j++) {
      up[i][j] = up[i - 1][up[i - 1][j]];
      max[i][j] = std::max(max[i - 1][j], max[i - 1][up[i - 1][j]]);
    }
  }
  std::vector<int> ans(m, -1);
  d = Dsu(n + 1);
  for (int i = 0; i < m; i++) {
    auto [z, x, y, id] = e[i];
    if (up[0][x] == y || up[0][y] == x) continue;
    if (dep[x] < dep[y]) std::swap(x, y);
    int maxw = 0;
    for (int j = 19; j >= 0; j--) {
      if (dep[x] - dep[y] >> j & 1) smax(maxw, max[j][x]), x = up[j][x];
    }
    if (x != y) {
      for (int j = 19; j >= 0; j--) {
        if (up[j][x] == up[j][y]) continue;
        smax(maxw, max[j][x]);
        smax(maxw, max[j][y]);
        x = up[j][x];
        y = up[j][y];
      }
      smax(maxw, max[0][x]), smax(maxw, max[0][y]), x = up[0][x];
    }
    for (int p = d.find(e[i][1]); dep[p] > dep[x]; d.merge(p, up[0][p]), p = d.find(p)) {
      ans[val[p]] = z - 1;
    }
    for (int p = d.find(e[i][2]); dep[p] > dep[x]; d.merge(p, up[0][p]), p = d.find(p)) {
      ans[val[p]] = z - 1;
    }
    ans[id] = maxw - 1;
  }
  for (auto x : ans) std::cout << x << " ";
  return 0;
}
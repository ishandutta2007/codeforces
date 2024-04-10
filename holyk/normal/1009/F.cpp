#include <bits/stdc++.h>
#define dbg(...) std::cerr << "\033[32;1m", fprintf(stderr, __VA_ARGS__), std::cerr << "\033[0m"
template <class T, class U>
inline bool smin(T &x, const U &y) { return y < x ? x = y, 1 : 0; }
template <class T, class U>
inline bool smax(T &x, const U &y) { return x < y ? x = y, 1 : 0; }
using LL = long long;
using PII = std::pair<int, int>;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n;
  std::cin >> n;
  std::vector<std::vector<int>> g(n);
  for (int i = 1, x, y; i < n; i++) {
    std::cin >> x >> y;
    x--, y--;
    g[x].push_back(y);
    g[y].push_back(x);
  }
  std::vector<int> ans(n), siz(n), son(n), dep(n), maxd(n), cnt(n);
  std::function<void(int, int)> dfs = [&](int x, int fa) {
    siz[x] = 1;
    maxd[x] = dep[x];
    int max = 0;
    for (int y : g[x]) {
      if (y == fa) {
        continue;
      }
      dep[y] = dep[x] + 1;
      dfs(y, x);
      smax(maxd[x], maxd[y]);
      siz[x] += siz[y];
      if (smax(max, siz[y])) son[x] = y;
    }
  }, add = [&](int x, int fa) {
    cnt[dep[x]]++;
    for (int y : g[x]) {
      if (y == fa) {
        continue;
      }
      add(y, x);
    }
  }, dfs2 = [&](int x, int fa) {
    cnt[dep[x]]++;
    ans[x] = dep[x];
    if (!son[x]) return;
    for (int y : g[x]) {
      if (y == fa || y == son[x]) {
        continue;
      }
      dfs2(y, x);
      for (int i = dep[y]; i <= maxd[y]; i++) cnt[i] = 0;
    }
    dfs2(son[x], x);
    int r = 0;
    for (int y : g[x]) {
      if (y == fa || y == son[x]) {
        continue;
      }
      add(y, x);
      smax(r, maxd[y]);
    }
    int max = 1;
    for (int i = dep[x]; i <= r; i++) {
      if (smax(max, cnt[i])) {
        ans[x] = i;
      }
    }
    if (smax(max, cnt[ans[son[x]]]) || max == cnt[ans[son[x]]] && ans[son[x]] < ans[x])
      ans[x] = ans[son[x]];
  };
  dfs(0, -1), dfs2(0, -1);
  for (int i = 0; i < n; i++)
    std::cout << ans[i] - dep[i] << "\n";
  return 0;
}
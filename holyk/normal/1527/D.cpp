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

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  std::cin >> t;
  while (t--) {
    int n;
    std::cin >> n;
    std::vector<std::vector<int>> g(n);
    for (int i = 1; i < n; i++) {
      int x, y;
      std::cin >> x >> y;
      g[x].push_back(y), g[y].push_back(x);
    }
    std::vector<int> in(n), siz(n), fa(n, -1), vis(n);
    int cnt = 0;
    std::function<void(int)> dfs = [&](int x) {
      in[x] = ++cnt;
      siz[x] = 1;
      for (int y : g[x]) {
	if (y == fa[x]) continue;
	fa[y] = x;
	dfs(y);
	siz[x] += siz[y];
      }
    };
    dfs(0);
    std::vector<LL> ans(n + 2);
    cnt = 1;
    ans[0] = 1LL * n * (n - 1) / 2;
    for (int x : g[0]) {
      ans[1] += 1LL * cnt * siz[x];
      cnt += siz[x];
    }
    vis[0] = 1;
    int a = 0, b = 0;
    for (int i = 1; i < n; i++) {
      if (!vis[i]) {
	int x = i, p = x;
	while (!vis[x]) vis[x] = 1, p = x, x = fa[x];
	if (x == a) {
	  siz[a] -= siz[p];
	  a = i;
	} else if (x == b) {
	  siz[b] -= siz[p];
	  b = i;
	} else {
	  break;
	}
      }
      ans[i + 1] = 1LL * siz[a] * siz[b];
    }
    // for (auto i : ans) dbg("??? %lld\n", i);
    for (int i = 0; i <= n; i++) std::cout << ans[i] - ans[i + 1] << " \n"[i == n];
  }
  return 0;
}
/*
2
4
0 1
0 2
2 3
2
1 0

 */
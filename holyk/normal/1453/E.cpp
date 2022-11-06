#include <bits/stdc++.h>

template <class T, class U>
inline bool smin(T &x, const U &y) { return y < x ? x = y, 1 : 0; }
template <class T, class U>
inline bool smax(T &x, const U &y) { return x < y ? x = y, 1 : 0; }

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t; std::cin >> t;
  while (t--) {
    int n; std::cin >> n;
    std::vector<std::vector<int>> g(n + 1);
    for (int i = 1, x, y; i < n; i++) {
      std::cin >> x >> y;
      g[x].push_back(y), g[y].push_back(x);
    }
    int ans = 0;
    std::function<int(int, int)> dfs = [&](int x, int fa) {
      int min = n, max = 0, max2 = 0, c = 0;
      for (int y: g[x]) {
        if (y == fa) continue;
        c++;
        int dy = dfs(y, x) + 1;
        smin(min, dy);
        if (dy >= max)
          max2 = max, max = dy;
        else
          smax(max2, dy);
      }
      if (!c) return 0;
      if (x > 1) {
        smax(ans, c > 1 ? max + 1 : max);
      }
      else {
        smax(ans, max);
        if (c > 1) smax(ans, max2 + 1);
      }
      return min;
    };
    dfs(1, 0);
    std::cout << ans << "\n";
  }
  return 0;
}
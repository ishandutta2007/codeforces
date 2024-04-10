#include <algorithm>
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
    std::vector<int> a(n);
    std::vector<std::vector<LL>> g(n);
    for (int &x : a) std::cin >> x, x--;
    for (int i = 0; i < n; i++) {
      int x;
      std::cin >> x;
      g[a[i]].push_back(x);
    }
    std::vector<LL> ans(n + 1);
    for (int i = 0; i < n; i++) {
      std::sort(g[i].begin(), g[i].end(), std::greater<LL>());
      int m = g[i].size();
      for (int j = 1; j < m; j++) g[i][j] += g[i][j - 1];
      for (int j = 1; j <= m; j++) {
        if (m - m % j - 1 >= 0)
          ans[j] += g[i][m - m % j - 1];
      }
    }
    for (int i = 1; i <= n; i++) std::cout << ans[i] << " \n"[i == n];
  }
  return 0;
}
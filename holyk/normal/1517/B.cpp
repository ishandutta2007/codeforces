#include <algorithm>
#include <bits/stdc++.h>
#include <numeric>
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
    int n, m;
    std::cin >> n >> m;
    std::vector<std::vector<int>> a(n, std::vector<int>(m)), b = a;
    std::vector<int> s(n, m - 1);
    std::vector<std::array<int, 3>> c;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < m; j++) {
        std::cin >> a[i][j];
      } 
      std::sort(a[i].begin(), a[i].end());
      for (int j = 0; j < m; j++) {
        c.push_back({a[i][j], i, j});
      }
    }
      
    for (auto &x : b) std::iota(x.begin(), x.end(), 0);
    std::sort(c.begin(), c.end());
    for (int i = 0; i < m; i++) {
      auto [z, x, y] = c[i];
      for (int j = 0; j < m; j++) if (b[x][j] == i) {
        std::swap(b[x][y], b[x][j]);
        break;
      }
    }
    for (int i = 0; i < n; i++) {
      std::vector<int> ans(m);
      for (int j = 0; j < m; j++) ans[b[i][j]] = a[i][j];
      for (int x : ans) std::cout << x << " ";
      std::cout << "\n";
    }
  }
  return 0;
}
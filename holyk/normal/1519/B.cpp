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
    int n, m, k;
    std::cin >> n >> m >> k;
    std::vector<std::bitset<10001>> f(m), g(m);
    f[0][0] = 1;
    for (int i = 1; i < m; i++) f[i] = f[i - 1] << 1;
    for (int i = 1; i < n; i++) {
      g[0] = f[0] << 1;
      for (int j = 1; j < m; j++) g[j] = f[j] << (j + 1) | g[j - 1] << (i + 1); 
      f.swap(g);
    }
    puts(f.back()[k] ? "yes" : "no");
  }
  return 0;
}
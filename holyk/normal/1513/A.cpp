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
    int n, k;
    std::cin >> n >> k;
    if (k + k + 1 > n) {
      std::cout << -1 << "\n";
      continue;
    }
    for (int i = 1, u = 1, v = k + 2; i <= k + k + 1; i++) {
      if (i & 1) std::cout << u++ << " ";
      else std::cout << v++ << " ";
    }
    for (int i = k + k + 2; i <= n; i++) std::cout << i << " ";
    std::cout << "\n";
  }

  return 0;
}
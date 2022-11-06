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
    std::map<int, std::vector<int>> g;
    for (int i = 0; i < n; i++) {
      int x;
      std::cin >> x;
      g[x].push_back(i);
    }
    LL ans = 0;
    for (auto &[u, v] : g) {
      LL sum = 0;
      for (int x : v) {
	ans += sum * (n - x);
	sum += x + 1;
      }
    }
    std::cout << ans << "\n";
  }
  return 0;
}
/*
2
4
1 2 1 1
4
1 2 3 4

 */
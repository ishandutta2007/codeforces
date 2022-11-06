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
    int n, m;
    std::cin >> n;
    m = n >> 1;
    std::vector<int> p(n);
    std::vector<PII> ans;
    std::iota(p.begin(), p.end(), 1);
    LL sum = 0;
    auto sqr = [](int x) { return 1LL * x * x; };
    for (int i = 0; i < m; i++) {
      std::swap(p[i], p.back());
      sum += sqr(n - i - 1);
      ans.emplace_back(i + 1, n);
    }
    for (int i = m; i < n - 1; i++) {
      std::swap(p[i], p.front());
      sum += sqr(i);
      ans.emplace_back(i + 1, 1);
    }
    std::cout << sum << "\n";
    for (auto x : p) std::cout << x << " ";
    std::cout << "\n" << ans.size() << "\n";
    std::reverse(ans.begin(), ans.end());
    for (auto [x, y] : ans) std::cout << x << " " << y << "\n";
  }
  return 0;
}
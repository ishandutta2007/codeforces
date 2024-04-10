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

constexpr int P(1e9 + 7);
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  std::cin >> t;
  while (t--) {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    int u = INT_MAX;
    for (auto &x : a) std::cin >> x, u &= x;
    int c = 0;
    for (auto x : a) if (x == u) c++;
    int ans = 1LL * c * (c - 1)  % P;
    for (int i = 1; i <= n - 2; i++) ans = 1LL * ans * i % P;
    std::cout << ans << "\n";
  }
  return 0;
}
#include <bits/stdc++.h>
#include <stdlib.h>
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
  int n;
  std::cin >> n;
  std::vector<int> a(n);
  for (int &x : a) std::cin >> x;
  int ans = 1e9, tt = 0;
  for (int t = 1; t <= 101; t++) {
    int r = 0;
    for (int x : a) {
      r += std::min({abs(x - t), abs(x - t - 1), abs(x - t + 1)});
    }
    if (smin(ans, r)) tt = t;
  }
  std::cout << tt << " " << ans << "\n";
  return 0;
}
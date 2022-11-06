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
  while (t--) [&]{
    int n;
    std::cin >> n;
    bool ok = false;
    while (n--) {
      int x;
      std::cin >> x;
      int t = sqrt(x);
      if (t * t != x) ok = true;
    }
    puts(ok ? "YES" : "NO");
  }();
  return 0;
}
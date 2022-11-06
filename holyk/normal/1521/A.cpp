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
    int a, b;
    std::cin >> a >> b;
    if (b == 1) {
      std::cout << "NO\n";
      continue;
    }
    [&] {
      LL m = 1LL * a * b;
      for (int k = 1; ; k++) {
        LL c = m * k;
        if (a % m == 0 || (c - a) % m == 0 || a == c - a) continue;
        std::cout << "YES\n";
        std::cout << a << " " << c - a << " " << c << "\n";
        return;
      }
    }();
  }
  return 0;
}
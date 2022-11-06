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
    int q, d, x;
    std::cin >> q >> d;
    std::vector<int> v;
    for (int i = 1; i <= 10; i++) v.push_back(i * d);
    while (q--) {
      std::cin >> x;
      
      if (d == 1) {
        puts("YES");
        continue;
      }
      bool ok = false;
      for (int i = 1; i < 233 && x > 0; i++) {
        if (x % d == 0 || x % 10 == d || x / 10 % 10 == d) {
          ok = true; break;
        }
        x -= d;
      }
      puts(!ok ? "NO" : "YES");
    }
  }
  return 0;
}
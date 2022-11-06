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
#define int LL
signed main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  std::cin >> t;
  while (t--) {
    int n;
    std::cin >> n;
    std::vector<int> a(n << 1);
    for (int &x : a) std::cin >> x;
    
    auto check = [&] {
      auto b = a;
      std::sort(b.begin(), b.end());
      if (b[0] & 1) return false;
      int now = 0;
      LL sum = b[0] / 2;
      for (int i = 0; i < n << 1; i += 2) {
        if (b[i] != b[i + 1]) return false;
        if (i + 2 < n << 1) {
          int r = i + 2;
          if ((b[i + 2] - b[i]) % r) return false;
          r = (b[i + 2] - b[i]) / r;
          if (!r) return false;
          now += r;
          sum -= now;
          // dbg("%d ", now);
        }
      }
      // dbg("%d\n", sum);
      return sum > 0 && sum % n == 0;
    }; 
    puts(check() ? "YES" : "NO");
  }
  return 0;
}
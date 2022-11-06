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
    int a = 0, b = 0, c = 0, d = 0;

    for (int i = 1; i <= n; i++) {
      int r;
      std::cin >> r;
      switch (r) {
      case 1:
        if (a >= c) a++;
        else c++;
        break;
      case 2:
        if (b < a) b++;
        else d++;
        break;
      case 3:
        if (b <= a) a++;
        else {
          if (d <= c) c++;
          else d++;
        }
      }
      
    }
    std::cout << std::max(a, c) << "\n";
  }
  return 0;
}
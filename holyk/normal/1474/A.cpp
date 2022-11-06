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
    std::string a, b;
    std::cin >> n >> a;
    for (int i = 0, last = -1; i < n; i++) {
      int x = a[i] - '0';
      for (int y = 1; y >= -1; y--) {
        if (y == -1) {
          dbg("%s\n", b.data());
          assert(0);
        } else if (x + y != last) {
          last = x + y;
          b += char(y + '0');
          break;
        }
      }
    }
    std::cout << b << "\n";
  }
  return 0;
}
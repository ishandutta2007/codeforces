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
    int a, b, c;
    std::cin >> a >> b >> c;
    int u = 1, v = 1, x = 1;
    while (--c) x *= 10;
    while (--a) u *= 10;
    while (--b) v *= 10;
    LL p = x, q = x;
    while (p <= u) p *= 2;
    while (q <= v) q *= 3;
    std::cout << p << " " << q << "\n";
  }
  return 0;
}
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
    int n, k;
    std::cin >> n >> k;
    std::vector<int> a(n);
    for (int &x : a) std::cin >> x;
    for (int i = 0; i < n - 1 && k; i++) {
      int &x = a[i];
      if (x <= k) k -= x, a.back() += x, x = 0;
      else x -= k, a.back() += k, k = 0;
    }
    for (int x : a) std::cout << x << " ";
    std::cout << "\n";
  }
  return 0;
}
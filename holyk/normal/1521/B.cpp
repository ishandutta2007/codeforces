#include <algorithm>
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
    std::vector<int> a(n);
    for (int &x : a) std::cin >> x;
    int p = std::min_element(a.begin(), a.end()) - a.begin();
    std::cout << n - 1 << "\n";
    for (int i = 0; i < n; i++) {
      if (i == p) continue;
      std::cout << i + 1 << " " << p + 1 << " " << (i & 1 ? 1000000007 : 1000000009) << " " << a[p] << "\n";
    }
  }
  return 0;
}
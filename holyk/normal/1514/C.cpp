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
  int n;
  std::cin >> n;
  std::vector<int> a;
  int ans = 0;
  for (int i = 1, r = 1; i < n; i++) {
    if (std::gcd(i, n) > 1) continue;
    r = 1LL * r * i % n;
    a.push_back(i);
    if (r == 1) ans = a.size();
  }
  std::cout << ans << "\n";
  for (int i = 0; i < ans; i++) std::cout << a[i] << " ";
  return 0;
}
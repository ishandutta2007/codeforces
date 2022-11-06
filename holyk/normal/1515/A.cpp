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
    int n, x;
    std::cin >> n >> x;
    std::vector<int> a(n);
    for (int &x : a) std::cin >> x;
    std::sort(a.begin(), a.end());
    int i = 0, s = 0;
    while (i < n && s + a[i] < x) s += a[i++];
    std::reverse(a.begin() + i, a.end());
    if (i < n && s + a[i] == x) {
      std::cout << "NO\n";
    } else {
      std::cout << "YES\n";
      for (int x : a) std::cout << x << " ";
      std::cout << "\n";
    }
  }
  return 0;
}
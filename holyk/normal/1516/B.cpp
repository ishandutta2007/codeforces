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
  while (t--) [&]{
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int &x : a) std::cin >> x;
    if (*std::min_element(a.begin(), a.end()) == *std::max_element(a.begin(), a.end())) {
      puts("YES");
      return;
    }
    for (int i = 1; i < n; i++) a[i] ^= a[i - 1];
    int u = 0;
    for (int x : a) {
      if (x) u = x;
    }
    int s = 0;
    int cnt = 0;
    for (int x : a) {
      if (x == (s ^ u)) s ^= u, cnt++;
    }
    puts(cnt > 1 ? "YES" : "NO");
  }();
  return 0;
}
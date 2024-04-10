#include <bits/stdc++.h>
#define dbg(...) std::cerr << "\033[32;1m", fprintf(stderr, __VA_ARGS__), std::cerr << "\033[0m"
template <class T, class U>
inline bool smin(T &x, const U &y) { return y < x ? x = y, 1 : 0; }
template <class T, class U>
inline bool smax(T &x, const U &y) { return x < y ? x = y, 1 : 0; }
using LL = long long;
using PII = std::pair<int, int>;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n, m, s, k;
  std::cin >> n >> m >> s >> k;
  std::vector<int> a(n), rb(n, -1);
  int l = 1, r = 0;
  for (auto &x : a) std::cin >> x, smax(r, x);
  while (m--) {
    int x, y; std::cin >> x >> y;
    for (int i = x - 1; i < y; i++) smax(rb[i], y - 1);
  }
  int ans = -1;
  while (l <= r) {
    int m = l + r >> 1;
    std::vector<int> b(n), f(n);
    for (int i = 0; i < n; i++) {
      b[i] = (i ? b[i - 1] : 0) + (a[i] <= m);
    }
    for (int i = 0; i < s; i++) {
      for (int j = n - 1; j >= 0; j--) {
        if (rb[j] == -1) continue;
        smax(f[rb[j]], j ? f[j - 1] + b[rb[j]] - b[j - 1] : b[rb[j]]);
      }
      for (int j = 1; j < n; j++) {
        smax(f[j], f[j - 1]);
      }
    }
    if (f.back() >= k)
      r = m - 1, ans = m;
    else
      l = m + 1;
  }
  std::cout << ans << "\n";
  return 0;
}
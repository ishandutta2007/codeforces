#include <bits/stdc++.h>

template <class T, class U>
inline bool smax(T &x, const U &y) { return x < y ? x = y, 1 : 0; }

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n; std::cin >> n;
  std::vector<int> p(n), s(n, 1);
  for (int i = 1; i < n; i++) std::cin >> p[i], s[--p[i]] = 0;
  std::vector<int64_t> a(n);
  for (auto &x: a) std::cin >> x;
  int64_t ans = 0;
  for (int i = n - 1; i >= 0; i--) {
    smax(ans, (a[i] + s[i] - 1) / s[i]);
    a[p[i]] += a[i];
    s[p[i]] += s[i];
  }
  std::cout << ans << "\n";
  return 0;
}
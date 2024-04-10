// Author:  HolyK
// Created: Thu Oct 28 14:36:53 2021
#include <bits/stdc++.h>
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

struct Info {
  int a, b;
  bool operator<(const Info &r) const {
    return std::max(a, b) < std::max(r.a, r.b) || std::max(a, b) == std::max(r.a, r.b) &&
      (a < r.a || a == r.a && b < r.b);
  }
};
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n, d;
  std::cin >> n >> d;
  std::vector<Info> a(n);
  for (int i = 0; i < n; i++) std::cin >> a[i].a >> a[i].b;
  std::sort(a.begin(), a.end());
  int ans = 0;
  for (auto [x, y] : a) {
    if (x >= d) {
      ans++;
      smax(d, y);
    }
  }
  std::cout << ans << "\n";
  return 0;
}
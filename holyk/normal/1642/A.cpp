// Author:  HolyK
// Created: Tue Aug  2 09:04:25 2022
#include <bits/stdc++.h>
#include <iomanip>
#include <ios>

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

struct Pt {
  int x, y;
  Pt operator-(const Pt &r) const {
    return {x - r.x, y - r.y};
  }
  double len() const {
    return sqrt(1LL * x * x + 1LL * y * y);
  }
  void read() {
    std::cin >> x >> y;
  }
};

void solve() {
  std::vector<Pt> a(3);
  a[0].read(), a[1].read(), a[2].read();
  std::sort(a.begin(), a.end(), [&](const auto &i, const auto &j) {
    return i.y < j.y;
  });
  double ans = 0;
  if (a[1].y == a[2].y) {
    ans += std::abs(a[1].x - a[2].x);
  }
  std::cout << std::fixed << std::setprecision(10) << ans << "\n";
}

int main() {
  // freopen("t.in", "r", stdin);
  
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  int t = 1;
  
  std::cin >> t;
  
  while (t--) {
    solve();
  }
  return 0;
}
// Author:  HolyK
// Created: Tue Aug 24 23:57:37 2021
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

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  std::cin >> t;
  while (t--) {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; i++) {
      std::cin >> a[i];
    }
    bool ok = true;
    for (int i = 0; i < n; i++) {
      if (!((i ^ a[i]) & 1)) {
        ok = false;
        break;
      }
    }
    if (!ok) {
      std::cout << "-1\n";
      continue;
    }
    std::vector<int> ans;
    auto rev = [&](int p) {
      if (p == 1) return;
      ans.push_back(p);
      std::reverse(a.begin(), a.begin() + p);
    };
    for (; n > 1; n -= 2) {
      int p = 0;
      while (p < n && a[p] != n) p++;
      rev(p + 1);
      p = 0;
      while (p < n && a[p] != n - 1) p++;
      rev(p);
      rev(p + 2);
      rev(3);
      rev(n);
    }
    // for (int x : a) std::cerr << x << " "; std::cerr << "\n";
    std::cout << ans.size() << "\n";
    for (int x : ans) std::cout << x << " ";

    std::cout << "\n";
  }
  return 0;
}
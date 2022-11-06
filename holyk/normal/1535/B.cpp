// Author:  HolyK
// Created: Fri Jun  4 22:37:56 2021
#include <bits/stdc++.h>
#define dbg(a...) fprintf(stderr, a)
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
    LL ans = 0;
    std::vector<int> a;
    int m = n;
    for (int i = 0; i < n; i++) {
      int x;
      std::cin >> x;
      if (x & 1) {
	a.push_back(x);
      } else {
	ans += --m;
      }
    }
    n = m;
    std::sort(a.begin(), a.end());
    for (int i = 0; i < n; i++) {
      for (int j = i + 1; j < n; j++) {
	if (std::gcd(a[i], a[j]) > 1) ans++;
      }
    }
    std::cout << ans << "\n";
  }
  return 0;
}
/*
3
4
3 6 5 3
2
1 7
5
1 4 2 4 1

 */
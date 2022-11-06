// Author:  HolyK
// Created: Thu Jul 29 22:42:40 2021
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
    int n, m;
    std::cin >> n >> m;
    std::vector<PII> v(1);
    v[0] = {n ^ m, (n ^ m) + 1};
    for (int i = 29, nw = 0, p = 1 << 29; i >= 0; i--, p >>= 1) {
      if (m >> i & 1) {
        int l = nw | (n & p);
        v.push_back({l, l + p});
      }
      nw |= (n ^ m) & p;
    }
    std::sort(v.begin(), v.end());
    if (v[0].first > 0) {
      std::cout << "0\n";
    } else {
      int i = 0;
      while (i + 1 < v.size() && v[i + 1].first == v[i].second) i++;
      std::cout << v[i].second << "\n";
    }
  }
  return 0;
}
/*

 */
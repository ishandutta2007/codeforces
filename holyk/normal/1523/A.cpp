// Author:  HolyK
// Created: Sun May 30 22:34:27 2021
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
    smin(m, n);
    std::string s;
    std::cin >> s;
    std::vector<int> a(n);
    int now = -1e9;
    for (int i = 0; i < n; i++) {
      if (s[i] == '1') now = i;
      a[i] = i - now;
    }
    now = 1e9;
    for (int i = n - 1; i >= 0; i--) {
      if (s[i] == '1') now = i;
      if (a[i] == now - i) continue;
      smin(a[i], now - i);
      if (a[i] <= m) s[i] = '1';
    }
    std::cout << s << "\n";
  }
  return 0;
}
/*
4
11 3
01000000001
10 2
0110100101
5 2
10101
3 100
000

 */
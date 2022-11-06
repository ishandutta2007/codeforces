// Author:  HolyK
// Created: Sun Jul 25 23:15:11 2021
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
    std::vector<int> a(n), b(n);
    for (int i = 0; i < n; i++) std::cin >> a[i];
    bool ok = false;
    std::vector<int> pw(n + 1);
    pw[0] = 1;
    for (int i = 0; i < n; i++) pw[i + 1] = pw[i] * 3;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < pw[n]; j++) {
        if (j / pw[i] % 3) continue;
        LL s = 0;
        for (int k = 0; k < n; k++) {
          int x = j / pw[k] % 3;
          if (x == 1) s += a[k];
          else if (x == 2) s -= a[k];
        }
        if (a[i] == s) ok = true;
      }
    }
    std::cout << (ok ? "YES\n" : "NO\n");
  }
  return 0;
}
/*

 */
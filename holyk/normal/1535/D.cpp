// Author:  HolyK
// Created: Fri Jun  4 23:01:40 2021
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
  int k;
  std::cin >> k;
  int n = 1 << k;
  std::string s, t(n * 2, '?');
  std::cin >> s;
  std::vector<int> a(n * 2), id(n);
  for (int i = n; i < n * 2; i++) a[i] = 1;
  auto up = [&](int i) {
    if (isdigit(t[i])) {
      a[i] = a[i * 2 + t[i] - '0'];
    } else {
      a[i] = a[i * 2] + a[i * 2 + 1];
    }
  };
  for (int i = k - 1, p = 0; i >= 0; i--) {
    for (int j = 1 << i; j < 2 << i; j++) id[p] = j, t[j] = s[p++], up(j);
  }
  int q;
  std::cin >> q;
  while (q--) {
    int x;
    std::string y;
    std::cin >> x >> y;
    s[x - 1] = t[id[x - 1]] = y[0];
    for (int i = id[x - 1]; i; i >>= 1) up(i);
    std::cout << a[1] << "\n";
  }
  return 0;
}
/*

3
0110?11
6
5 1
6 ?
7 ?
1 ?
5 ?
1 1
 */
// Author:  HolyK
// Created: Sun May 30 22:42:23 2021
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
void print(int k, int i, int j) {
  std::cout << k << " " << i + 1 << " " << j + 1 << "\n";
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  std::cin >> t;
  while (t--) {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int &x : a) std::cin >> x;
    std::cout << n * 3 << "\n";
    for (int i = 0; i < n; i += 2) {
      print(2, i, i + 1);
      print(1, i, i + 1);
      print(2, i, i + 1);
      print(1, i, i + 1);
      print(2, i, i + 1);
      print(1, i, i + 1);
    }
  }
  return 0;
}
/*
2
4
1 1 1 1
4
4 3 1 2

 */
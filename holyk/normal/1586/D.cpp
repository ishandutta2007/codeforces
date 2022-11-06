// Author:  HolyK
// Created: Mon Oct 18 11:31:05 2021
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

int a[101];
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n;
  std::cin >> n;
  int x = 1;
  while (x < n) {
    std::cout << "? ";
    for (int i = 1; i < n; i++) std::cout << x << " ";
    std::cout << n << std::endl;
    int r;
    std::cin >> r;
    if (r) break;
    x++;
  }
  a[n] = x;
  for (int i = 1; i <= n; i++) {
    if (i == x) continue;
    std::cout << "? ";
    for (int j = 1; j < n; j++) std::cout << x << " ";
    std::cout << i << std::endl;
    int r;
    std::cin >> r;
    a[r] = i;
  }
  std::cout << "! ";
  for (int i = 1; i <= n; i++) std::cout << a[i] << " \n"[i == n];
  std::cout.flush();
  return 0;
}
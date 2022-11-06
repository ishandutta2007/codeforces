// Author:  HolyK
// Created: Sun Aug 29 23:16:59 2021
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
LL ask(int i, int j) {
  LL a, b;
  std::cout << "or " << i + 1 << " " << j + 1 << std::endl;
  std::cin >> a;
  std::cout << "and " << i + 1 << " " << j + 1 << std::endl;
  std::cin >> b;
  return a + b;
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int n, k;
  std::cin >> n >> k;
  std::vector<int> p(n);
  std::vector<LL> val(n);
  std::iota(p.begin(), p.end(), 0);

  for (int i = 1; i < n; i++) val[i] = ask(0, i);
  val[0] = ask(1, 2);
  val[0] = (val[1] + val[2] - val[0]) / 2;
  for (int i = 1; i < n; i++) val[i] -= val[0];
  std::sort(val.begin(), val.end());
  std::cout << "finish " << val[k - 1] << std::endl;
  return 0;
}
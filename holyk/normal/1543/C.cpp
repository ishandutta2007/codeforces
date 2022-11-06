// Author:  HolyK
// Created: Thu Jul  8 09:26:20 2021
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

constexpr double EPS(1e-10);
std::map<std::pair<double, double>, double> f;
double c, m, p, v;
double dfs(double a, double b) {
  // a = round(a * 1e8) / 1e8;
  // b = round(b * 1e8) / 1e8;
  if (a > b) std::swap(a, b);
  auto it = f.find({a, b});
  if (it != f.end()) return it->second;
  f[{a, b}] = 1;
  if (a > EPS) f[{a, b}] += a * dfs(std::max(a - v, 0.0), b > EPS ? b + std::min(a, v) / 2 : 0);
  if (b > EPS) f[{a, b}] += b * dfs(std::max(b - v, 0.0), a > EPS ? a + std::min(b, v) / 2 : 0);
  return f[{a, b}];
}
int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  std::cin >> t;
  std::cout.precision(10);
  while (t--) {
    std::cin >> c >> m >> p >> v;
    if (c > m) std::swap(c, m);
    f.clear();
    f[{0, 0}] = 1;
    
    std::cout << dfs(c, m) << "\n";
  }
  return 0;
}
/*
4
0.2 0.2 0.6 0.2
0.4 0.2 0.4 0.8
0.4998 0.4998 0.0004 0.1666
0.3125 0.6561 0.0314 0.2048

 */
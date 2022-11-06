// Author:  HolyK
// Created: Thu Sep 22 08:05:36 2022
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


void solve() {
  int n;
  std::string s;
  std::cin >> n >> s;
  n = 1 << n;
  
  int m = 1;

  std::vector<int> p(n), r(n), c(n), x(n);
  std::iota(p.begin(), p.end(), 0);
  std::sort(p.begin(), p.end(), [&](int i, int j) { return s[i] < s[j]; });
  r[p[0]] = 0;
  for (int i = 1; i < n; i++) {
    r[p[i]] = s[p[i]] != s[p[i - 1]] ? m++ : m - 1;
  }

  for (int k = 1; k < n; k <<= 1) {
    for (int i = 0; i < n; i++) x[i] = p[i] ^ k;
    for (int i = 0; i < m; i++) c[i] = 0;
    for (int i = 0; i < n; i++) c[r[i]]++;
    for (int i = 1; i < m; i++) c[i] += c[i - 1];
    for (int i = n - 1; i >= 0; i--) p[--c[r[x[i]]]] = x[i];
    r.swap(x), r[p[0]] = 0, m = 1;
    for (int i = 1; i < n; i++) {
      r[p[i]] = x[p[i - 1]] < x[p[i]] || x[p[i - 1] ^ k] < x[p[i] ^ k] ? m++ : m - 1;
    }
  }

  std::string t;
  int v = p[0];
  for (int i = 0; i < n; i++) t += s[i ^ v];
  std::cout << t << "\n";
}

int main() {
  // freopen("t.in", "r", stdin);
  
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  int t = 1;
  
  // std::cin >> t;
  
  while (t--) {
    solve();
  }
  return 0;
}
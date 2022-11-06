// Author:  HolyK
// Created: Thu May  5 23:37:30 2022
#include <algorithm>
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
  int n, k;
  std::string s;
  std::cin >> n >> k >> s;
  int p = 0;
  while (p < n && k >= s[p] - 'a') p++;
  if (p >= n) {
    std::cout << std::string(n, 'a') << "\n";
  } else {
    if (p) {
      char t = *std::max_element(s.begin(), s.begin() + p);
      k -= t - 'a';
      for (char &c : s) if (c <= t) c = 'a';
    }
    char l = s[p] - k, r = s[p];
    for (char &c : s) if (l <= c && c <= r) c = l;
    std::cout << s << "\n";
  }
  
}

int main() {
  // freopen("t.in", "r", stdin);
  
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  int t = 1;
  
  std::cin >> t;
  
  while (t--) {
    solve();
  }
  return 0;
}
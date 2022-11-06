// Author:  HolyK
// Created: Wed Dec 29 23:55:20 2021
#include <bits/stdc++.h>
template <class T, class U>
inline bool smin(T &x, const U &y) {
  return y < x ? x = y, 1 : 0;
}
template <class T, class U>
inline bool smax(T &x, const U &y) {
  return x < y ? x = y, 1 : 0;
}
template <int S>
using AI = std::array<int, S>;
using LL = long long;
using PII = std::pair<int, int>;

void solve() {
  int n;
  std::string s;
  std::cin >> n >> s;
  if (n == 1 || s[0] == s[1]) {
    std::cout << s[0] << s[0] << "\n";
    return;
  }
  std::string t;
  t += s[0];
  
  for (int i = 1; i < n; i++) {
    if (s[i] <= s[i - 1]) {
      t += s[i];
    } else {
      break;
    }
  }
  s = t;
  std::reverse(t.begin(), t.end());
  std::cout << s + t << "\n";
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t = 1;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
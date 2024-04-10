// Author:  HolyK
// Created: Thu May  5 23:18:36 2022
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
  std::string s;
  std::cin >> s;
  int n = s.length();
  int ans = 0, cnt[2] = {}, c[2] = {};
  for (char x : s) if (isdigit(x)) cnt[x - '0']++;
  for (char x : s) {
    bool ok = !c[0];
    if (isdigit(x)) c[x - '0']++;
    ok = ok && cnt[1] == c[1];
    ans += ok;
  }
  std::cout << ans << "\n";
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
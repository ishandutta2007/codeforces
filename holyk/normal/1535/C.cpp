// Author:  HolyK
// Created: Fri Jun  4 22:44:16 2021
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
    std::string s;
    std::cin >> s;
    int pos[2][2];
    memset(pos, -1, sizeof pos);
    int n = s.length();
    LL ans = 0;
    for (int i = 0, j = 0; i < n; i++) {
      if (s[i] != '?') {
	pos[i & 1][s[i] - '0'] = i;
	smax(j, pos[i & 1][s[i] - '0' ^ 1] + 1);
	smax(j, pos[i & 1 ^ 1][s[i] - '0'] + 1);
      }
      ans += i - j + 1;
    }
    std::cout << ans << "\n";
  }
  return 0;
}
/*
3
0?10
???
?10??1100

 */
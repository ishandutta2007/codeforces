// Author:  HolyK
// Created: Tue Sep  7 13:53:34 2021
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

int main() {
  // freopen("t.in", "r", stdin);
  // freopen(".out", "w", stdout);
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  std::cin >> t;
  while (t--) {
    std::string s;
    int n;
    std::cin >> s >> n;
    std::vector<int> ans;
    for (int d = 0; d < s.size(); d++) {
      int k = s[d] - '0';
      int x = 1;
      for (int i = d + 1; i < s.size(); i++) x *= 10;
      while (n && k) {
        n--, k--;
        ans.push_back(x);
      }
      if (k) ans[0] += x * k;
    }
    std::priority_queue<int, std::vector<int>, std::greater<int>> q(ans.begin(), ans.end());
    while (!q.empty()) {
      int x = q.top(); q.pop();
      if (x == 1 || n <= 0) {
        std::cout << x << " ";
        continue;
      }
      int d = x / 10;
      if (n < 9) {
        while (n--) {
          std::cout << d << " ";
          x -= d;
        }
        std::cout << x << " ";
      } else {
        for (int i = 0; i < 10; i++) {
          q.push(d);
        }
        n -= 9;
      }
    }
    std::cout << "\n";
  }
  return 0;
}
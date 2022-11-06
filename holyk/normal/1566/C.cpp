// Author:  HolyK
// Created: Sun Sep 12 22:46:15 2021
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
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t;
  std::cin >> t;
  while (t--) {
    int n;
    std::string a, b;
    std::cin >> n >> a >> b;
    std::vector<std::vector<int>> s(n, std::vector<int>(2));
    for (int i = 0; i < n; i++) {
      s[i][a[i] - '0']++;
      s[i][b[i] - '0']++;
    }
    for (int i = 1; i < n; i++) {
      s[i][0] += s[i - 1][0];
      s[i][1] += s[i - 1][1];
    }
    std::vector<int> f(n);

    auto cal = [&](int a, int b) {
      return a ? b ? 2 : 1 : 0;
    };
    int p[3] = {0, 0, 0};
    for (int i = 0; i < n; i++) {
      f[i] = cal(s[i][0], s[i][1]);
      for (int j = 0; j < 3; j++) {
        while (p[j] + 1 < i && cal(s[i][0] - s[p[j] + 1][0], s[i][1] - s[p[j] + 1][1]) >= j) p[j]++;
        if (p[j] < i) {
          smax(f[i], f[p[j]] + cal(s[i][0] - s[p[j]][0], s[i][1] - s[p[j]][1]));
        }
      }
      // std::cerr << i << " " << p[0] << " " << p[1] << " " << p[2] << "\n";
    }
    // for (int i = 0; i < n; i++) std::cerr << f[i] << " \n"[i + 1 == n];
    std::cout << f[n - 1] << "\n";
  }
  return 0;
}
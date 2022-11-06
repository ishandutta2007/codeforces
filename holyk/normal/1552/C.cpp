// Author:  HolyK
// Created: Sun Jul 25 22:54:53 2021
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
    int n, k;
    std::cin >> n >> k;
    n *= 2;
    std::vector<std::vector<int>> s(n, std::vector<int>(n));
    std::vector<int> vis(n);
    LL ans = 0;
    auto add = [&](int x, int y) {
      ans += s[x][y];
      vis[x] = vis[y] = 1;
      for (int i = (x + 1) % n; i != y; i = (i + 1) % n) {
        for (int j = (x - 1 + n) % n; j != y; j = (j - 1 + n) % n) {
          assert(j != i);
          s[i][j]++;
          s[j][i]++;
        }
      }
    };
    while (k--) {
      int x, y;
      std::cin >> x >> y;
      x--, y--;
      add(x, y);
    }
    // std::cerr << ans << "\n";
    std::vector<int> v;
    for (int i = 0; i < n; i++) {
      if (!vis[i]) v.push_back(i);
    }
    for (int i = 0; i < v.size() / 2; i++) {
      add(v[i], v[i + v.size() / 2]);
    }
    // while (!q.empty()) {
    //   auto [d, _, i, j] = q.top();
    //   q.pop();
    //   if (s[i][j] != d) continue;
    //   if (vis[i] || vis[j]) continue;
    //   add(i, j);
    // }
    std::cout << ans << "\n";
  }
  return 0;
}
/*

 */
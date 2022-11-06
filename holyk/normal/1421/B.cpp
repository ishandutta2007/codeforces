#include <bits/stdc++.h>

template <class T, class U>
inline bool smin(T &x, const U &y) {
  return y < x ? x = y, 1 : 0;
}
template <class T, class U>
inline bool smax(T &x, const U &y) {
  return x < y ? x = y, 1 : 0;
}
typedef long long LL;
typedef std::pair<int, int> PII;

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t; std::cin >> t;
  while (t--) {
    int n;
    std::cin >> n;
    std::vector<std::string> a(n);
    for (int i = 0; i < n; i++)
      std::cin >> a[i];
    auto bfs = [&](char c) {
      std::queue<PII> q;
      q.push({0, 0});
      std::vector<std::vector<int>> v(n, std::vector<int>(n, 0));
      v[0][0] = 1;
      a[n - 1][n - 1] = c;
      std::vector<PII> dir {PII(-1, 0), PII(0, 1), PII(1, 0), PII(0, -1)};
      while (!q.empty()) {
        auto [x, y] = q.front(); q.pop();
        for (auto [dx, dy] : dir) {
          int tx = x + dx, ty = y + dy;
          if (0 <= tx && tx < n && 0 <= ty && ty < n && !v[tx][ty] && a[tx][ty] == c) {
            v[tx][ty] = 1;
            q.push({tx, ty});
          }
          
        }
      }
      return v[n - 1][n - 1];
    };
    std::vector<PII> ans;
    ans.push_back({1, 0});
    ans.push_back({0, 1});
    ans.push_back({n - 2, n - 1});
    ans.push_back({n - 1, n - 2});
    auto solve = [&]() {
      for (int i = 0; i < ans.size(); i++) {
        auto [ax, ay] = ans[i];
        a[ax][ay] ^= '0' ^ '1';
        if (!bfs('0') && !bfs('1')) {
          std::cout << "1\n" << ax + 1 << " " << ay + 1 << "\n";
          return;
        }
        for (int j = i + 1; j < ans.size(); j++) {
          auto [bx, by] = ans[j];
          a[bx][by] ^= '0' ^ '1';
          if (!bfs('0') && !bfs('1')) {
            std::cout << "2\n" << ax + 1 << " " << ay + 1 << "\n" << bx + 1 << " " << by + 1 << "\n";
            return;
          }
          a[bx][by] ^= '0' ^ '1';
        }
        a[ax][ay] ^= '0' ^ '1';
      }
    };
    solve();
  }
  return 0;
}
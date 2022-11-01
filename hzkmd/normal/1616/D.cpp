#include <bits/stdc++.h>

int main() {
  std::ios_base::sync_with_stdio(false);
  std::cin.tie(nullptr);

  int T;
  std::cin >> T;
  while (T--) {
    int n;
    std::cin >> n;
    std::vector<int> a(n);
    for (int i = 0; i < n; ++i) {
      std::cin >> a[i];
    }
    int x;
    std::cin >> x;
    for (int i = 0; i < n; ++i) {
      a[i] -= x;
    }
    
    std::vector<long long> sum(n + 1);
    for (int i = 0; i < n; ++i) {
      sum[i + 1] = sum[i] + a[i];
    }
    std::vector<std::array<std::array<int, 2>, 2>> f(n + 1);
    for (int i = 0; i < n; ++i) {
      for (int x = 0; x < 2; ++x) {
        for (int y = 0; y < 2; ++y) {
          f[i + 1][y][0] = std::max(f[i + 1][y][0], f[i][x][y]);
          bool ok = true;
          if (y && i >= 1) {
            ok &= sum[i + 1] - sum[i - 1] >= 0;
          }
          if (x && y && i >= 2) {
            ok &= sum[i + 1] - sum[i - 2] >= 0;
          }
          if (ok) {
            f[i + 1][y][1] = std::max(f[i + 1][y][1], f[i][x][y] + 1);
          }
        }
      }
    }
    int ans = 0;
    for (int x = 0; x < 2; ++x) {
      for (int y = 0; y < 2; ++y) {
        ans = std::max(ans, f[n][x][y]);
      }
    }
    std::cout << ans << "\n";
  }
}
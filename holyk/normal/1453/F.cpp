#include <bits/stdc++.h>

template <class T, class U>
inline bool smin(T &x, const U &y) { return y < x ? x = y, 1 : 0; }

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  int t; std::cin >> t;
  while (t--) {
    int n; std::cin >> n;
    std::vector<int> a(n);
    for (int &x: a) std::cin >> x;
    std::vector<std::vector<int>> dp(n, std::vector<int>(n, 1e9));
    dp[0].assign(n, 0);
    for (int i = 1; i < n; i++) {
      for (int j = i - 1, c = 0; j >= 0; j--) {
        if (j + a[j] < i) continue;
        smin(dp[i][std::min(n - 1, j + a[j])], dp[j][i - 1] + c);
        c++;
      }
      for (int j = i + 1; j < n; j++) smin(dp[i][j], dp[i][j - 1]);
    }
    std::cout << dp[n - 1][n - 1] << "\n";
  }
  return 0;
}
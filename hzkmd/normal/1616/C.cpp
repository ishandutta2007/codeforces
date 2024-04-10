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
    int ans = n - 1;
    for (int i = 0; i < n; ++i) {
      for (int j = i + 1; j < n; ++j) {
        int cnt = 0;
        for (int k = 0; k < n; ++k) {
          int x = (a[j] - a[i]) * (k - i), y = j - i;
          cnt += x % y != 0 || x / y + a[i] != a[k];
        }
        ans = std::min(ans, cnt);
      }
    }
    std::cout << ans << "\n";
  }
}
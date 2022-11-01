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
    std::map<int, int> cnt;
    for (int i = 0; i < n; ++i) {
      std::cin >> a[i];
      ++cnt[std::abs(a[i])];
    }
    int ans = 0;
    for (auto [x, c] : cnt) {
      ans += std::min(c, 1 + (x > 0));
    }
    std::cout << ans << "\n";
  }
}
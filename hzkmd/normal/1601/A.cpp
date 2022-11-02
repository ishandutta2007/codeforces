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
    int g = 0;
    for (int i = 0; i < 30; ++i) {
      int c = 0;
      for (int j = 0; j < n; ++j) {
        c += a[j] >> i & 1;
      }
      g = std::__gcd(g, c);
    }
    for (int i = 1; i <= n; ++i) {
      if (g % i == 0) {
        std::cout << i << " ";
      }
    }
    std::cout << "\n";
  }
}
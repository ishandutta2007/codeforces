#include <bits/stdc++.h>

int main() {
  std::ios::sync_with_stdio(0);
  std::cin.tie(0);
  int t;
  std::cin >> t;
  while (t--) {
    int n;
    std::cin >> n;
    std::vector<int> a(10, -1e5);
    for (int i = 0; i < n; i++) {
      int x, y;
      std::cin >> x >> y;
      y--;
      a[y] = std::max(a[y], x);
    }
    
    int ans = 0;
    for (int i = 0; i < 10; i++) ans += a[i];
    if (ans >= 0) {
      std::cout << ans << "\n";
    } else {
      std::cout << "MOREPROBLEMS\n";
    }
  }
  return 0;
}
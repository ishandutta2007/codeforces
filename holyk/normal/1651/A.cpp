#include <bits/stdc++.h>

using LL = long long;
using PII = std::pair<int, int>;

void solve() {
  int n;
  std::cin >> n;
  std::cout << (1 << n) - 1 << "\n";
}

int main() {
  std::ios::sync_with_stdio(false);
  std::cin.tie(nullptr);
  
  int t = 1;
  std::cin >> t;
  while (t--) {
    solve();
  }
  return 0;
}
#include <bits/stdc++.h>

using LL = long long;
int main() {
  LL n;
  std::cin >> n;
  std::vector<LL> f(100, 1e18);
  f[0] = 1, f[1] = 2;
  for (int i = 2; i < 99; i++) {
    f[i] = std::min({f[i - 1] + f[i - 1], f[i - 2] + f[i - 1]});
    if (f[i] > n) return printf("%d\n", i - 1), 0;
  }
  return 0;
}
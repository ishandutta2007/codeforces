#include <iostream>
#include <algorithm>

typedef long long int64;

const int N = 200000 + 10;

int n, a[N];

int main() {
  std::ios::sync_with_stdio(false);
  std::cin >> n;
  for (int i = 1; i <= n; ++i) std::cin >> a[i];
  std::sort(a + 1, a + 1 + n);
  int p = 1, q = n;
  while (a[p + 1] == a[1]) ++p;
  while (a[q - 1] == a[n]) --q;
  int64 ans = (p >= q) ? (int64)n * (n - 1) / 2 : (int64)p * (n - q + 1);
  std::cout << a[n] - a[1] << ' ' << ans << std::endl;
  return 0;
}
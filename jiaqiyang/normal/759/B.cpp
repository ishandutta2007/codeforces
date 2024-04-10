#include <cstdio>
#include <algorithm>

const int N = 100000 + 10;

int n, t[N], f[N];

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", &t[i]);
  for (int i = 1, j = 1, k = 1; i <= n; ++i) {
    while (t[i] - t[j] >= 90) ++j;
    while (t[i] - t[k] >= 1440) ++k;
    f[i] = std::min({f[i - 1] + 20, f[j - 1] + 50, f[k - 1] + 120});
  }
  for (int i = 1; i <= n; ++i) printf("%d\n", f[i] - f[i - 1]);
  return 0;
}
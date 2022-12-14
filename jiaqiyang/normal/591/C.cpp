#include <cstdio>
#include <cstring>
#include <algorithm>

const int N = 500000 + 10;

int n, a[N], f[N];

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", a + i);
  memset(f, -1, sizeof f);
  f[1] = f[n] = 0;
  for (int i = 2; i < n; ++i) if (a[i] == a[i - 1] || a[i] == a[i + 1]) f[i] = 0;
  for (int i = 2; i < n; ++i) {
    if (f[i] == -1) {
      int j = i;
      while (f[j + 1] == -1) ++j;
      for (int l = i, r = j, c = 1; l <= r; ++l, --r, ++c) f[l] = f[r] = c;
    }
  }
  printf("%d\n", *std::max_element(f + 1, f + n + 1));
  for (int i = 1; i <= n; ++i) printf("%d%c", a[i] ^ (f[i] & 1), i == n ? '\n' : ' ');
  return 0;
}
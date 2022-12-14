#include <cstdio>
#include <algorithm>

const int N = 100000 + 10;

int n, a[N], f[N];
int p[N], cnt;

void sieve() {
  cnt = 0;
  static int flag[N];
  for (int i = 2; i < N; ++i) {
    if (!flag[i]) p[cnt++] = i;
    for (int j = 0; j < cnt && i * p[j] < N; ++j) {
      flag[i * p[j]] = true;
      if (i % p[j] == 0) break;
    }
  }
}

int main() {
  sieve();
  scanf("%d", &n);
  for (int i = 1; i <= n; ++i) scanf("%d", &a[i]);
  for (int i = 1; i <= n; ++i) {
    static int cur[N];
    int tot = 0;
    int x = a[i];
    for (int j = 0; j < cnt && p[j] * p[j] <= x; ++j) {
      if (x % p[j] == 0) {
        while (x % p[j] == 0) x /= p[j];
        cur[tot++] = p[j];
      }
    }
    if (x > 1) cur[tot++] = x;
    int val = 0;
    for (int j = 0; j < tot; ++j) {
      int k = cur[j];
      val = std::max(val, f[k] + 1);
    }
    for (int j = 0; j < tot; ++j) {
      int k = cur[j];
      f[k] = std::max(f[k], val);
    }
  }
  printf("%d\n", std::max(1, *std::max_element(f, f + N)));
  return 0;
}
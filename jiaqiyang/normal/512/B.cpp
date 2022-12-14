#include <cstdio>
#include <cstring>

const int N = 300 + 10, M = 100000 + 10, S = 10, INF = 0x3f3f3f3f;

inline void check(int &lhs, int rhs) { if (rhs < lhs) lhs = rhs; }

int n, l[N], c[N];

int prime[M], m;

void sieve() {
  static bool flag[M];
  m = 0;
  for (int i = 2; i < M; ++i) {
    if (!flag[i]) prime[++m] = i;
    for (int j = 1; j <= m && i * prime[j] < M; ++j) {
      flag[i * prime[j]] = true;
      if (i % prime[j] == 0) break;
    }
  }
}

int p[N], cnt;

void factor(int x) {
  for (int i = 1; i <= m && prime[i] * prime[i] <= x; ++i) {
    if (x % prime[i] == 0) {
      while (x % prime[i] == 0) x /= prime[i];
      p[cnt++] = prime[i];
    }
  }
  if (x > 1) p[cnt++] = x;
}

int solve(int x) {
  cnt = 0, factor(x);
  static int mask[N];
  for (int i = 0; i < n; ++i) {
    mask[i] = 0;
    for (int j = 0; j < cnt; ++j) if (l[i] % p[j] == 0) mask[i] |= 1 << j;
  }
  static int f[1 << S];
  memset(f, 0x3f, sizeof f);
  int tot = 1 << cnt;
  f[tot - 1] = 0;
  for (int i = 0; i < n; ++i)
    for (int j = 0; j < tot; ++j)
      check(f[j & mask[i]], f[j] + c[i]);
  return f[0];
}

int main() {
  sieve();
  scanf("%d", &n);
  for (int i = 0; i < n; ++i) scanf("%d", &l[i]);
  for (int i = 0; i < n; ++i) scanf("%d", &c[i]);
  int ans = INF;
  for (int i = 0; i < n; ++i) check(ans, solve(l[i]) + c[i]);
  printf("%d\n", ans == INF ? -1 : ans);
  return 0;
}
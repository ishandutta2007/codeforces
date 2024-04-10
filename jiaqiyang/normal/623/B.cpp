#include <cstdio>
#include <algorithm>

typedef long long i64;

const int N = 1000000 + 10;
const i64 INF = 1LL << 50;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

int n, a, b, val[N];

int prime[N], cnt;

inline void preprocess() {
  static bool flag[N];
  for (int i = 2; i < N; ++i) {
    if (!flag[i]) prime[++cnt] = i;
    for (int j = 1; j <= cnt && i * prime[j] < N; ++j) {
      flag[i * prime[j]] = true;
      if (i % prime[j] == 0) break;
    }
  }
}

i64 ans = INF;

void check(int t) {
  static i64 f[N], g[N];
  for (int i = 1; i <= n; ++i) {
    if (val[i] % t == 0)
      f[i] = f[i - 1];
    else if ((val[i] + 1) % t == 0 || (val[i] - 1) % t == 0)
      f[i] = f[i - 1] + b;
    else {
      for (int j = i; j <= n; ++j) f[j] = INF;
      break;
    }
  }
  g[n + 1] = 0;
  for (int i = n; i > 0; --i) {
    if (val[i] % t == 0) {
      g[i] = g[i + 1];
    } else if ((val[i] + 1) % t == 0 || (val[i] - 1) % t == 0) {
      g[i] = g[i + 1] + b;
    } else {
      for (int j = 1; j <= i; ++j) g[j] = INF;
      break;
    }
  }
  ans = std::min(ans, f[n]);
  ans = std::min(ans, g[1]);
  i64 temp = 0;
  for (int i = 1; i <= n; ++i) {
    ans = std::min(ans, g[i] + (i - 1LL) * a + temp);
    ans = std::min(ans, f[i] + ((i64)n - i) * a);
    temp = std::min(temp, f[i] - (i64)i * a);
  }
}

void factor(int x) {
  for (int i = 1; prime[i] * prime[i] <= x; ++i) {
    if (x % prime[i] == 0) {
      while (x % prime[i] == 0) x /= prime[i];
      check(prime[i]);
    }
  }
  if (x > 1) check(x);
}

int main() {
  preprocess();
  scanf("%d%d%d", &n, &a, &b);
  for (int i = 1; i <= n; ++i) scanf("%d", &val[i]);
  for (int i = -1; i <= 1; ++i) factor(val[1] + i), factor(val[n] + i);
  printf("%I64d\n", ans);
  return 0;
}
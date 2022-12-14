#include <cstdio>
#include <cstring>

typedef long long i64;

const int N = 1000000 + 10;

int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }

i64 n, m;

char x[N], y[N];

int a[26], b[26];

int main() {
  scanf("%lld%lld %s %s", &n, &m, x, y);
  for (char *i = x; *i; ++i) ++a[*i - 'a'];
  for (char *i = y; *i; ++i) ++b[*i - 'a'];
  int p = strlen(x), q = strlen(y), t = gcd(p, q);
  i64 ans = n * p;
  i64 c = ans / ((i64)p / t * q);
  static int sum[N][26];
  for (int i = 0; i < p; ++i) ++sum[i % t][x[i] - 'a'];
  for (int i = 0; i < q; ++i) ans -= (i64)c * sum[i % t][y[i] - 'a'];
  printf("%lld\n", ans);
  return 0;
}
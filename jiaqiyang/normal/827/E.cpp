#include <cstdio>
#include <algorithm>

typedef long long i64;

const int N = 1 << 20, MOD = 998244353;

int power(int base, int exp) {
  int res = 1;
  for (; exp; exp >>= 1) {
    if (exp & 1) res = (i64)res * base % MOD;
    base = (i64)base * base % MOD;
  }
  return res;
}

void dft(int a[], int n) {
  for (int i = 0, j = 0; i < n; ++i) {
    if (i < j) std::swap(a[i], a[j]);
    for (int k = n >> 1; (j ^= k) < k;) k >>= 1;
  }
  for (int m = 2; m <= n; m *= 2) {
    int gap = m / 2;
    int w = power(3, (MOD - 1) / m);
    for (int i = 0; i < n; i += m) {
      for (int j = i, o = 1; j < i + gap; ++j, o = (i64)o * w % MOD) {
        int u = a[j], v = (i64)a[j + gap] * o % MOD;
        a[j] = (u + v) % MOD;
        a[j + gap] = (u - v) % MOD;
      }
    }
  }
}

void idft(int a[], int n) {
  dft(a, n);
  std::reverse(a + 1, a + n);
  for (int i = 0, inv = power(n, MOD - 2); i < n; ++i) a[i] = (i64)a[i] * inv % MOD;
}

int p[N], tot;

void sieve() {
  tot = 0;
  static bool flag[N];
  for (int i = 2; i < N; ++i) {
    if (!flag[i]) p[++tot] = i;
    for (int j = 1; j <= tot && i * p[j] < N; ++j) {
      flag[i * p[j]] = true;
      if (i % p[j] == 0) break;
    }
  }
}

int n;
char s[N];

bool flag[N];

int main() {
  sieve();
  int tcase;
  for (scanf("%d", &tcase); tcase--;) {
    scanf("%d %s", &n, s);
    static int a[N], b[N];
    int m = 1;
    while (m < 2 * n) m *= 2;
    std::fill(a, a + m + 1, 0);
    std::fill(b, b + m + 1, 0);
    for (int i = 0; i < n; ++i) if (s[i] == 'V') a[i] = 1; else if (s[i] == 'K') b[n - i] = 1;
    dft(a, m);
    dft(b, m);
    for (int i = 0; i < m; ++i) a[i] = (i64)a[i] * b[i] % MOD;
    idft(a, m);
    std::fill(flag, flag + n + 1, false);
    for (int i = -n; i <= n; ++i) if (a[n + i]) flag[abs(i)] = true;
    for (int i = 1; p[i] <= n; ++i)
      for (int j = n / p[i] * p[i]; j; j -= p[i])
        flag[j / p[i]] |= flag[j];
    static int ans[N];
    int cnt = 0;
    for (int i = 1; i <= n; ++i) if (!flag[i]) ans[++cnt] = i;
    printf("%d\n", cnt);
    for (int i = 1; i <= cnt; ++i) printf("%d ", ans[i]);
    putchar('\n');
  }
  return 0;
}
#include <cmath>
#include <cstdio>
#include <cctype>
#include <map>
#include <algorithm>

typedef long long i64;

const int N = 100000 + 10;

inline int nextInt() {
  char ch;
  while (!isdigit(ch = getchar())) {}
  int res = ch - '0';
  while (isdigit(ch = getchar())) res = 10 * res + ch - '0';
  return res;
}

i64 gcd(i64 a, i64 b) { return b ? gcd(b, a % b) : a; }

int n, m, mod, a[N];

int power(int base, int exp, int mod) {
  int res = 1;
  for (; exp; exp >>= 1) {
    if (exp & 1) res = (i64)res * base % mod;
    base = (i64)base * base % mod;
  }
  return res;
}

int p[N], c[N], tot;
int d[N], phi[N], cnt;

std::map<int, int> pos;

void factor(int x) {
  tot = 0;
  int y = x;
  for (int i = 2; i * i <= y; ++i) {
    if (y % i == 0) {
      p[++tot] = i;
      c[tot] = 0;
      for (; y % i == 0; y /= i) ++c[tot];
    }
  }
  if (y > 1) p[++tot] = y, c[tot] = 1;
  cnt = 0;
  for (int i = 1; i * i <= x; ++i) {
    if (x % i == 0) {
      d[++cnt] = i;
      if (i * i != x) d[++cnt] = x / i;
    }
  }
  std::sort(d + 1, d + cnt + 1);
  for (int i = 1; i <= cnt; ++i) pos[d[i]] = i;
  for (int i = 1; i <= cnt; ++i) {
    phi[i] = 1;
    for (int j = 1; j <= tot; ++j) {
      if (d[i] % p[j] == 0) {
        phi[i] *= p[j] - 1;
        for (int t = d[i] / p[j]; t % p[j] == 0; t /= p[j]) phi[i] *= p[j];
      }
    }
  }
}

int ind(int x) {
  int res = mod - 1;
  for (int i = 1; i <= tot; ++i) while (res % p[i] == 0 && power(x, res / p[i], mod) == 1) res /= p[i];
  return res;
}

int main() {
  scanf("%d%d%d", &n, &m, &mod);
  factor(mod - 1);
  for (int i = 1; i <= n; ++i) a[i] = nextInt();
  int b = 0;
  for (int i = 1; i <= m; ++i) b = gcd(b, nextInt());
  for (int i = 1; i <= n; ++i) a[i] = (mod - 1) / ind(power(a[i], b, mod));
  static bool flag[N];
  std::fill(flag + 1, flag + cnt + 1, false);
  for (int i = 1; i <= n; ++i) flag[pos[a[i]]] = true;
  for (int i = 1; i <= cnt; ++i)
    if (flag[i])
      for (int j = 1; j <= tot; ++j)
        if (pos.count(d[i] * p[j])) flag[pos[d[i] * p[j]]] = true;
  int ans = 0;
  for (int i = 1; i <= cnt; ++i) if (flag[i]) ans += phi[pos[(mod - 1) / d[i]]];
  printf("%d\n", ans);
  return 0;
}
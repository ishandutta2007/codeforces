#include <cstdio>
#include <algorithm>

typedef long long i64;

const int N = 200000 + 10, M = 2000 + 10, S = 20 + 3, MOD = 1000000007;

int power(int base, int exp) {
  int res = 1;
  for (; exp; exp >>= 1) {
    if (exp & 1) res = (i64)res * base % MOD;
    base = (i64)base * base % MOD;
  }
  return res;
}

inline void add(int &lhs, i64 rhs) { lhs = (lhs + rhs) % MOD; }

int n, m, k, s, fact[N], ifact[N];

struct Point {
  int x, y;
  Point() {}
  Point(int _x, int _y): x(_x), y(_y) {}
  inline bool operator< (const Point &rhs) const {
    return x < rhs.x || (x == rhs.x && y < rhs.y);
  }
} p[M];

int binom(int n, int m) {
  if (m < 0 || m > n) return 0;
  return (i64)fact[n] * ifact[m] % MOD * ifact[n - m] % MOD;
}

int calc(const Point &a, const Point &b) {
  return binom(b.x - a.x + b.y - a.y, b.x - a.x);

}

int f[M][S], g[M][S], h[S];

int main() {
  scanf("%d%d%d%d", &n, &m, &k, &s);
  fact[0] = 1;
  for (int i = 1; i < N; ++i) fact[i] = (i64)fact[i - 1] * i % MOD;
  ifact[0] = ifact[1] = 1;
  for (int i = 2; i < N; ++i) ifact[i] = ((i64)MOD - MOD / i) * ifact[MOD % i] % MOD;
  for (int i = 1; i < N; ++i) ifact[i] = (i64)ifact[i - 1] * ifact[i] % MOD;
  p[0] = Point(1, 1);
  p[k + 1] = Point(n, m);
  for (int i = 1; i <= k; ++i) scanf("%d%d", &p[i].x, &p[i].y);
  std::sort(p + 1, p + k + 1);
  f[0][0] = 1;
  for (int i = 0; i < S; ++i) h[i] = binom(S - 1, i);
  for (int i = 1; i <= k + 1; ++i) {
    for (int t = 0; t < i; ++t) {
      int temp = calc(p[t], p[i]);
      for (int j = 1; j < S; ++j) add(f[i][j], (i64)f[t][j - 1] * temp);
      for (int j = 0; j < S; ++j) {
        add(g[i][j], (i64)-g[t][j] * temp);
        if (j) add(g[i][j], (i64)-g[t][j - 1] * temp);
        add(g[i][j], (i64)f[t][S - 1] * temp % MOD * h[j]);
      }
    }
  }
  int ans = calc(p[0], p[k + 1]);
  static int mem[M];
  mem[0] = s;
  for (int i = 1; i < M; ++i) mem[i] = (mem[i - 1] + 1) / 2;
  for (int i = 1; i < S; ++i) {
    int cur = (((S - i) & 1) ? -1 : 1) * g[k + 1][i - 1];
    for (int j = i; j < S; ++j) add(cur, (((j - i) & 1) ? -1LL : 1LL) * f[k + 1][j] * binom(j - 1, i - 1));
    add(ans, cur * (mem[i - 1] - 1LL));
  }
  ans = (i64)ans * power(calc(p[0], p[k + 1]), MOD - 2) % MOD;
  ans = (ans + MOD) % MOD;
  printf("%d\n", ans);
  return 0;
}
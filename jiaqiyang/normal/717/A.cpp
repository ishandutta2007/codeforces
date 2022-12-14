#include <cstdio>

typedef long long i64;

const int N = 200 + 10, MOD = 1000000007;

struct Info {
  int x, y;
  Info() { x = y = 0; }
  Info(int _x): x(_x), y(0) {}
  Info(int _x, int _y): x(_x), y(_y) {}
  inline Info conj() const { return Info(x, (MOD - y) % MOD); }
};

int power(int base, int exp) {
  int res = 1;
  for (; exp; exp >>= 1) {
    if (exp & 1) res = (i64)res * base % MOD;
    base = (i64)base * base % MOD;
  }
  return res;
}

inline Info operator+ (const Info &lhs, const Info &rhs) {
  return Info((lhs.x + rhs.x) % MOD, (lhs.y + rhs.y) % MOD);
}

inline Info operator- (const Info &lhs, const Info &rhs) {
  return Info((lhs.x - rhs.x + MOD) % MOD, (lhs.y - rhs.y + MOD) % MOD);
}

inline Info operator* (const Info &lhs, const Info &rhs) {
  return Info(((i64)lhs.x * rhs.x + 5LL * lhs.y * rhs.y) % MOD, ((i64)lhs.x * rhs.y + (i64)lhs.y * rhs.x) % MOD);
}

inline Info operator/ (Info lhs, Info rhs) {
  Info temp = rhs.conj();
  lhs = lhs * temp;
  rhs = rhs * temp;
  lhs = lhs * power(rhs.x, MOD - 2);
  return lhs;
}

inline Info operator^ (Info base, i64 exp) {
  Info res = 1;
  for (; exp; exp >>= 1) {
    if (exp & 1) res = res * base;
    base = base * base;
  }
  return res;
}

const Info S(0, 1), A = (1 + S) / 2, B = (1 - S) / 2;

Info binom[N][N];

Info sum(const Info &x, i64 n) {
  if (x.x == 1 && x.y == 0) return n % MOD;
  Info res = (1 - (x ^ n)) / (1 - x);
  return res * x;
}

Info fib(int n) {
  Info res = (A ^ n) - (B ^ n);
  res = res / S;
  return res;
}

Info calc(i64 n, int k) {
  Info res = 0;
  for (int i = 0; i <= k; ++i) {
    Info cur = binom[k][i] * sum((A ^ i) * (B ^ (k - i)), n);
    if ((k - i) & 1) res = res - cur; else res = res + cur;
  }
  return res * ((1 / S) ^ k);
}

Info s[N][N];

Info solve(i64 n, int k) {
  static Info f[N];
  for (int i = 0; i <= k; ++i) f[i] = calc(n, i);
  Info res = 0;
  for (int i = 1; i <= k; ++i) {
    Info cur = s[k][i] * f[i];
    if ((k - i) & 1) res = res - cur; else res = res + cur;
  }
  return res;
}

int main() {
  binom[0][0] = 1;
  for (int i = 1; i < N; ++i)
    for (int j = 0; j < N; ++j)
      binom[i][j] = binom[i - 1][j] + (j ? binom[i - 1][j - 1] : 0);
  s[1][1] = 1;
  for (int i = 2; i < N; ++i)
    for (int j = 1; j <= i; ++j)
      s[i][j] = s[i - 1][j - 1] + (i - 1) * s[i - 1][j];
  int k;
  i64 l, r;
  scanf("%d%lld%lld", &k, &l, &r);
  l += 2, r += 2;
  Info ans = solve(r, k) - solve(l - 1, k);
  for (int i = k; i; --i) ans = ans / i;
  printf("%d\n", ans.x);
  return 0;
}
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>

typedef long long i64;

const int N = 1 << 16, MOD = 1000000007;

struct Complex {
  double x, y;
  Complex(double _x = 0., double _y = 0.): x(_x), y(_y) {}
  inline Complex conj() { return Complex(x, -y); }
};

inline Complex operator+ (const Complex &lhs, const Complex &rhs) {
  return Complex(lhs.x + rhs.x, lhs.y + rhs.y);
}

inline Complex operator- (const Complex &lhs, const Complex &rhs) {
  return Complex(lhs.x - rhs.x, lhs.y - rhs.y);
}

inline Complex operator* (const Complex &lhs, const Complex &rhs) {
  return Complex(lhs.x * rhs.x - lhs.y * rhs.y, lhs.x * rhs.y + lhs.y * rhs.x);
}

const Complex I(0., 1.);

int len;

Complex w[N + 1];

void fft(Complex a[]) {
  for (register int i = 0, j = 0; i < len; ++i) {
    if (j < i) std::swap(a[i], a[j]);
    for (register int k = len >> 1; (j ^= k) < k;) k >>= 1;
  }
  for (int m = 2; m <= len; m *= 2) {
    int gap = m / 2, step = N / m;
    for (int i = 0; i < len; i += m) {
      Complex *o = w, *p = &a[i], *q = &a[i + gap];
      for (int j = gap; j--; ++p, ++q, o += step) {
        Complex u = *p, v = *o * *q;
        *p = u + v;
        *q = u - v;
      }
    }
  }
}

inline int power(int base, int exp) {
  int res = 1;
  for (; exp; exp >>= 1) {
    if (exp & 1) res = (i64)res * base % MOD;
    base = (i64)base * base % MOD;
  }
  return res;
}

i64 n;
int k;

inline void convolution(int lhs[], const int rhs[]) {
  Complex a[N], b[N];
  for (int i = 0; i < len; ++i) a[i] = Complex(lhs[i] & 32767, lhs[i] >> 15);
  for (int i = 0; i < len; ++i) b[i] = Complex(rhs[i] & 32767, rhs[i] >> 15);
  fft(a);
  fft(b);
  static Complex res[4][N];
  for (int i = 0; i < len; ++i) {
    int j = (len - i) & (len - 1);
    Complex aLo = (a[i] + a[j].conj()) * Complex(.5, 0);
    Complex aHi = (a[i] - a[j].conj()) * Complex(0, -.5);
    Complex bLo = (b[i] + b[j].conj()) * Complex(.5, 0);
    Complex bHi = (b[i] - b[j].conj()) * Complex(0, -.5);
    res[0][i] = aLo * bLo;
    res[1][i] = aLo * bHi;
    res[2][i] = aHi * bLo;
    res[3][i] = aHi * bHi;
  }
  for (int i = 0; i < len; ++i) a[i] = res[0][i] + I * res[1][i];
  for (int i = 0; i < len; ++i) b[i] = res[2][i] + I * res[3][i];
  std::reverse(a + 1, a + len);
  std::reverse(b + 1, b + len);
  fft(a);
  fft(b);
  for (int i = 0; i <= k; ++i) {
    int lo = (i64)(a[i].x / len + .5) % MOD;
    int mid = ((i64)(a[i].y / len + .5) + (i64)(b[i].x / len + .5)) % MOD;
    int hi = (i64)(b[i].y / len + .5) % MOD;
    lhs[i] = (lo + ((i64)mid << 15) + ((i64)hi << 30)) % MOD;
  }
  for (int i = k + 1; i < len; ++i) lhs[i] = 0;
}

inline void merge(int lhs[], const int rhs[], int rlen) {
  static int temp[N];
  memcpy(temp, rhs, sizeof temp);
  for (int i = 0, j = 1, t = power(2, rlen); i < len; ++i, j = (i64)j * t % MOD) lhs[i] = (i64)lhs[i] * j % MOD;
  convolution(lhs, temp);
}

int main() {
  scanf("%I64d%d", &n, &k);
  if (n > k) return puts("0"), 0;
  for (int i = 0; i <= N; ++i) w[i] = Complex(cos(i * 2. * M_PI / N), sin(i * 2. * M_PI / N));
  static int fact[N], inv[N];
  fact[0] = 1;
  for (int i = 1; i < N; ++i) fact[i] = (i64)fact[i - 1] * i % MOD;
  inv[N - 1] = power(fact[N - 1], MOD - 2);
  for (int i = N - 2; i >= 0; --i) inv[i] = inv[i + 1] * (i + 1LL) % MOD;
  static int base[N], res[N];
  for (int i = 1; i <= k; ++i) base[i] = inv[i];
  len = 1;
  while (len <= 2 * k) len *= 2;
  res[0] = 1;
  for (int exp = n, cur = 1; exp; cur <<= 1, exp >>= 1) {
    if (exp & 1) merge(res, base, cur);
    merge(base, base, cur);
  }
  int ans = 0;
  for (int i = n; i <= k; ++i) ans = (ans + (i64)res[i] * fact[k] % MOD * inv[k - i]) % MOD;
  printf("%d\n", ans);
  return 0;
}
#include <cstdio>
#include <algorithm>

typedef long long i64;

const int LOG = 18, N = 1 << LOG, MOD = 7 * 17 * (1 << 23) + 1;

int n, m, c[N];
int w[N + 1];

inline int Pow(int base, int exp) {
  int res = 1;
  for (; exp; exp >>= 1) {
    if (exp & 1) res = (i64)res * base % MOD;
    base = (i64)base * base % MOD;
  }
  return res;
}

inline int lg2(int x) { return 31 - __builtin_clz(x); }

void DFT(int a[], int len, int sw) {
  static int temp[N];
  for (int i = 0, t = lg2(len); i < len; ++i) {
    int j = 0;
    for (int k = i, cnt = t; cnt--; k >>= 1) (j <<= 1) |= (k & 1);
    temp[j] = a[i];
  }
  for (int m = 2; m <= len; m *= 2) {
    int gap = m / 2, layer = N / m;
    for (int i = 0; i < gap; ++i) {
      int g = w[sw == 1 ? (i * layer) : (N - i * layer)];
      for (int j = i; j < len; j += m) {
        int u = temp[j], v = temp[j + gap];
        temp[j] = (u + (i64)g * v % MOD) % MOD;
        temp[j + gap] = (u - (i64)g * v % MOD + MOD) % MOD;
      }
    }
  }
  for (int i = 0; i < len; ++i) a[i] = temp[i];
  if (sw == -1) {
    int inv = Pow(len, MOD - 2);
    for (int i = 0; i < len; ++i) a[i] = (i64)a[i] * inv % MOD;
  }
}

inline void Convolution(int lhs[], const int rhs[], int len = N / 2) {
  static int temp[N];
  std::copy(rhs, rhs + len * 2, temp);
  DFT(lhs, len * 2, 1);
  DFT(temp, len * 2, 1);
  for (int i = 0; i < len * 2; ++i) lhs[i] = (i64)lhs[i] * temp[i] % MOD;
  DFT(lhs, len * 2, -1);
  for (int i = len; i < len * 2; ++i) lhs[i] = 0;
}

inline void Add(int lhs[], int rhs[], int len = N) {
  for (int i = 0; i < len; ++i) (lhs[i] += rhs[i]) %= MOD;
}

inline void Mul(int lhs[], int rhs, int len = N) {
  for (int i = 0; i < len; ++i) lhs[i] = (i64)lhs[i] * rhs % MOD;
}

inline void Div(int lhs[], int rhs, int len = N) {
  Mul(lhs, Pow(rhs, MOD - 2), len);
}

inline void Inv(int x[], int len = N / 2) {
  static int res[N];
  std::fill(res, res + N, 0);
  res[0] = Pow(x[0], MOD - 2);
  for (int l = 2; l <= len; l *= 2) {
    static int temp[N];
    int d = l * 2;
    std::copy(x, x + l, temp);
    std::fill(temp + l, temp + d, 0);
    DFT(temp, d, 1);
    DFT(res, d, 1);
    for (int i = 0; i < d; ++i) res[i] = (2LL * res[i] % MOD - (i64)temp[i] * res[i] % MOD * res[i] % MOD + MOD) % MOD;
    DFT(res, d, -1);
    std::fill(res + l, res + d, 0);
  }
  std::copy(res, res + len, x);
}

inline void Deriv(int x[], int len = N) {
  static int res[N];
  res[len - 1] = 0;
  for (int i = 0; i + 1 < len; ++i) res[i] = (i64)x[i + 1] * (i + 1) % MOD;
  std::copy(res, res + len, x);
}

inline void Integral(int x[], int len = N) {
  static int res[N];
  res[0] = 0;
  for (int i = 1; i < len; ++i) res[i] = (i64)x[i - 1] * Pow(i, MOD - 2) % MOD;
  std::copy(res, res + len, x);
}

inline void Log(int x[], int len = N / 2) {
  static int y[N];
  std::copy(x, x + N, y);
  Deriv(y, len);
  Inv(x, len);
  Convolution(x, y, len);
  Integral(x, len);
}

inline void Exp(int x[], int len = N / 2) {
  static int res[N];
  //assert(x[0] == 0);
  std::fill(res, res + len, 0);
  res[0] = 1;
  for (int l = 2; l <= len; l *= 2) {
    static int temp[N];
    std::copy(res, res + len, temp);
    Log(temp, l);
    Mul(temp, -1, l);
    Add(temp, x, l);
    (++temp[0]) %= MOD;
    Convolution(res, temp, l);
  }
  std::copy(res, res + len, x);
}

inline void Sqrt(int x[], int len = N / 2) {
  Log(x, len);
  Div(x, 2, len);
  Exp(x, len);
}

int main() {
  scanf("%d%d", &n, &m);
  static int c[N];
  for (int i = 1, temp; i <= n; ++i) {
    scanf("%d", &temp);
    c[temp] = 1;
  }
  w[0] = 1, w[1] = Pow(3, (MOD - 1) / N);
  for (int i = 2; i <= N; ++i) w[i] = (i64)w[i - 1] * w[1] % MOD;
  Mul(c, -4);
  (++c[0]) %= MOD;
  Sqrt(c);
  (++c[0]) %= MOD;
  Inv(c);
  Mul(c, 2);
  for (int i = 1; i <= m; ++i) printf("%d\n", c[i]);
  return 0;
}
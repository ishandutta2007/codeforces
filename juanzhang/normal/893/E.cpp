#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a), i##end = (b); i <= i##end; ++i)
#define per(i, a, b) for (int i = (a), i##end = (b); i >= i##end; --i)

mt19937 Rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

template <typename T>
inline void chkmax(T &x, T y) { if (x < y) x = y; }

template <typename T>
inline void chkmin(T &x, T y) { if (x > y) x = y; }

inline int read() {
  #define nc getchar()
  int x = 0;
  char c = nc;
  while (c < 48) c = nc;
  while (c > 47) x = (x << 3) + (x << 1) + (c ^ 48), c = nc;
  return x;
  #undef nc
}

const int maxn = 1e6 + 50, P = 1e9 + 7;
int T;

int pw2[maxn], inv[maxn], fac[maxn], ifac[maxn];

int binom(int n, int m) {
  return 1ll * fac[n] * ifac[m] % P * ifac[n - m] % P;
}

int main() {
  pw2[1] = 2;
  pw2[0] = fac[0] = ifac[0] = 1;
  inv[1] = fac[1] = ifac[1] = 1;
  rep(i, 2, maxn - 1) {
    pw2[i] = 2ll * pw2[i - 1] % P;
    fac[i] = 1ll * i * fac[i - 1] % P;
    inv[i] = 1ll * (P - P / i) * inv[P % i] % P;
    ifac[i] = 1ll * inv[i] * ifac[i - 1] % P;
  }
  int T = read();
  while (T--) {
    int x = read(), y = read();
    int res = pw2[y - 1];
    int tmp = sqrt(x) + 0.5;
    rep(i, 2, tmp) if (x % i == 0) {
      int c = 0;
      while (x % i == 0) c++, x /= i;
      res = 1ll * res * binom(y + c - 1, c) % P;
    }
    if (x > 1) res = 1ll * res * y % P;
    printf("%d\n", res);
  }
  return 0;
}
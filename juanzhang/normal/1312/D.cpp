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

typedef long long ll;
const int maxn = 2e5 + 10, P = 998244353;
int n, m, fac[maxn];

int qp(int a, int k) {
  int res = 1;
  for (; k; k >>= 1, a = 1ll * a * a % P) {
    if (k & 1) res = 1ll * res * a % P;
  }
  return res;
}

int binom(int n, int m) {
  return 1ll * fac[n] * qp(fac[m], P - 2) % P * qp(fac[n - m], P - 2) % P;
}

int main() {
  cin >> n >> m;
  if (n == 2) return puts("0"), 0;
  fac[0] = 1;
  rep(i, 1, m) fac[i] = 1ll * i * fac[i - 1] % P;
  cout << 1ll * binom(m, n - 1) * (n - 2) % P * qp(2, n - 3) % P;
  return 0;
}
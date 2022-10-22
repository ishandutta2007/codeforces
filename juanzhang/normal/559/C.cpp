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

const int maxn = 2e5 + 10, P = 1e9 + 7;
int R, C, n, dp[2010], st[2010];

int inv[maxn], fact[maxn], fact_inv[maxn];

struct point {
  int x, y;
} a[2010];

int binom(int n, int m) {
  return 1ll * fact[n] * fact_inv[m] % P * fact_inv[n - m] % P;
}

int query(int p, int q) {
  int x1 = a[p].x, y1 = a[p].y;
  int x2 = a[q].x, y2 = a[q].y;
  if (x1 > x2 || y1 > y2) return 0;
  return binom(x2 - x1 + y2 - y1, x2 - x1);
}

int main() {
  fact[0] = fact_inv[0] = 1;
  inv[1] = fact[1] = fact_inv[1] = 1;
  rep(i, 2, 2e5) {
    fact[i] = 1ll * i * fact[i - 1] % P;
    inv[i] = 1ll * (P - P / i) * inv[P % i] % P;
    fact_inv[i] = 1ll * fact_inv[i - 1] * inv[i] % P;
  }
  R = read(), C = read(), n = read();
  rep(i, 1, n) {
    a[i].x = read(), a[i].y = read();
  }
  a[++n] = {1, 1}, a[++n] = {R, C};
  sort(a + 1, a + n + 1, [] (point P, point Q) {
    return P.x < Q.x || (P.x == Q.x && P.y < Q.y);
  });
  rep(i, 1, n) {
    dp[i] = query(1, i);
    rep(j, 2, i - 1) {
      dp[i] = (dp[i] - 1ll * dp[j] * query(j, i) % P + P) % P;
    }
  }
  printf("%d", dp[n]);
  return 0;
}
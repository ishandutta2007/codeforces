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
  while (c > 47) x = x * 10 + (c ^ 48), c = nc;
  return x;
  #undef nc
}

typedef long long ll;
const int maxn = 1505;
int n, m, k, p;

const int P = 1e9 + 7;

int Inc(int x, int y) {
  return x + y < P ? x + y : x + y - P;
}

int Dec(int x, int y) {
  return x < y ? x - y + P : x - y;
}

void Add(int &x, int y) {
  x += y;
  if (x >= P) x -= P;
}

void Sub(int &x, int y) {
  x -= y;
  if (x < 0) x += P;
}

int qp(int a, int k) {
  int res = 1;
  for (; k; k >>= 1, a = 1ll * a * a % P) {
    if (k & 1) res = 1ll * res * a % P;
  }
  return res;
}

int inv[100010], fac[100010], ifac[100010];

int binom(int n, int m) {
  return n < m ? 0 : 1ll * fac[n] * ifac[m] % P * ifac[n - m] % P;
}

void init() {
  fac[0] = ifac[0] = 1;
  inv[1] = fac[1] = ifac[1] = 1;
  rep(i, 2, 100005) {
    inv[i] = 1ll * (P - P / i) * inv[P % i] % P;
    fac[i] = 1ll * i * fac[i - 1] % P;
    ifac[i] = 1ll * inv[i] * ifac[i - 1] % P;
  }
}

int A[2][maxn], B[2][maxn], val[maxn];

int preval[maxn], lefA[maxn], rigA[maxn], rigB[maxn];

int main() {
  int tmpA, tmpB;
  cin >> n >> m >> tmpA >> tmpB >> k;
  p = 1ll * tmpA * qp(tmpB, P - 2) % P;
  init();
  rep(i, 0, min(m, k)) val[i] = 1ll * qp(p, i) * qp(Dec(1, p), k - i) % P * binom(k, i) % P;
  rep(i, 1, m) preval[i] = Inc(preval[i - 1], val[i - 1]);
  int sel = 1;
  A[0][m] = 1;
  rep(i, 1, m - 1) B[0][i] = 1;
  rep(T, 1, n) {
    rep(i, 1, m) {
      lefA[i] = (lefA[i - 1] + 1ll * A[sel ^ 1][i - 1] * val[i - 1]) % P;
      rigA[i] = (rigA[i - 1] + 1ll * A[sel ^ 1][i] * val[m - i]) % P;
      rigB[i] = (rigB[i - 1] + 1ll * B[sel ^ 1][i] * val[m - i]) % P;
    }
    int v1 = 0, v2 = 0;
    rep(i, 1, m) {
      v1 = (v1 + 1ll * val[m - i] * (A[sel ^ 1][i] + B[sel ^ 1][i]) % P * preval[i]) % P;
      v2 = (v2 + 1ll * val[m - i] * lefA[i]) % P;
      A[sel][i] = (v1 - v2 + P) % P;
    }
    rep(i, 1, m - 1) {
      B[sel][i] = (1ll * (rigA[m] - rigA[i] + P) * preval[i] % P
                 - 1ll * preval[m - i] * lefA[i] % P + P
                 + 1ll * (rigB[m] - rigB[i] + P) * preval[i]) % P;
    }
    sel ^= 1;
  }
  cout << A[sel ^ 1][m] << endl;
  return 0;
}
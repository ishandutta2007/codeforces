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
typedef pair <int, int> pii;
const int maxn = 10010, P = 998244353;

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

int inv[maxn], fac[maxn], ifac[maxn];

int binom(int n, int m) {
  return n < m ? 0 : 1ll * fac[n] * ifac[m] % P * ifac[n - m] % P;
}

void init() {
  fac[0] = ifac[0] = 1;
  inv[1] = fac[1] = ifac[1] = 1;
  rep(i, 2, maxn - 1) {
    inv[i] = 1ll * (P - P / i) * inv[P % i] % P;
    fac[i] = 1ll * i * fac[i - 1] % P;
    ifac[i] = 1ll * inv[i] * ifac[i - 1] % P;
  }
}

int n, s, r;

int get(int n, int m) {
  if (n < 0 || m < 0) return 0;
  return binom(n + m - 1, n - 1);
}

int calc(int n, int m, int k) {
  if (n < 0 || m < 0) return 0;
  int res = 0;
  rep(i, 0, n) {
    if (m - k * i < 0) break;
    int tmp = 1ll * binom(n, i) * get(n, m - k * i) % P;
    i & 1 ? Sub(res, tmp) : Add(res, tmp);
  }
  return res;
} 

void solve() {
  init();
  cin >> n >> s >> r;
  if (n == 1) return puts("1"), void();
  int ans = 0;
  rep(i, r, s) {
    int cnt = s - i;
    int tmp = Dec(get(n - 1, cnt), calc(n - 1, cnt, i + 1));
    rep(j, 1, n - 1) {
      int t = j == n - 1 ? cnt == i * j : calc(n - j - 1, cnt - i * j, i);
      Add(tmp, 1ll * binom(n - 1, j) * t % P * (1 - qp(j + 1, P - 2) + P) % P);
    }
//    printf("#%d\n", tmp);
    Add(ans, tmp);
  }
  ans = 1ll * ans * qp(get(n, s - r), P - 2) % P;
  ans = (1 - ans + P) % P;
  cout << ans << endl;
}

signed main() {
//  int T = read();
//  while (T--) solve();
  solve();
  return 0;
}
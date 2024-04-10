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

const int maxn = 6e5 + 10, P = 998244353;

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

int n, k;

struct node {
  int l, r;
} A[maxn];

int add[maxn], del[maxn];

void solve() {
  init();
  cin >> n >> k;
  static int data[maxn];
  rep(i, 1, n) {
    A[i].l = read(), A[i].r = read();
    data[i] = A[i].l, data[n + i] = A[i].r;
  }
  sort(data + 1, data + n + n + 1);
  int m = unique(data + 1, data + n + n + 1) - data - 1;
  rep(i, 1, n) {
    int l = lower_bound(data + 1, data + m + 1, A[i].l) - data;
    int r = lower_bound(data + 1, data + m + 1, A[i].r) - data;
    add[l]++, del[r + 1]++;
  }
  int ans = 0, cur = 0;
  rep(i, 1, m) {
    cur -= del[i];
    rep(j, 1, add[i]) {
      Add(ans, binom(cur++, k - 1));
    }
  }
  cout << ans << endl;
}

signed main() {
//  int T = read();
//  while (T--) solve();
  solve();
  return 0;
}
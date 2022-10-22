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
const int maxn = 1e5 + 10;
ll dp[1 << 7];
int n, p, k, a[maxn], val[maxn][7], tid[maxn];

int main() {
  cin >> n >> p >> k;
  rep(i, 1, n) a[i] = read(), tid[i] = i;
  rep(i, 1, n) rep(j, 0, p - 1) val[i][j] = read();
  sort(tid + 1, tid + n + 1, [] (int x, int y) {
    return a[x] > a[y];
  });
  memset(dp, -0x3f, sizeof dp), dp[0] = 0;
  rep(T, 1, n) {
    int pos = tid[T];
    per(S, (1 << p) - 1, 0) {
      if (T - __builtin_popcount(S) <= k) {
        dp[S] += a[pos];
      }
      rep(i, 0, p - 1) if (S >> i & 1) {
        chkmax(dp[S], dp[S ^ 1 << i] + val[pos][i]);
      }
    }
  }
  cout << dp[(1 << p) - 1];
  return 0;
}
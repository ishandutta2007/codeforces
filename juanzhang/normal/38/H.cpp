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
int n, m, g1, g2, s1, s2;

int dis[55][55];

bool isg[55], iss[55], isb[55];
int mn[55], mx[55]; ll dp[55][55];

void solve() {
  cin >> n >> m;
  rep(i, 1, n) rep(j, 1, n) {
    dis[i][j] = i == j ? 0 : 1e9;
  }
  rep(i, 1, m) {
    int u = read(), v = read();
    dis[u][v] = dis[v][u] = read();
  }
  rep(k, 1, n) rep(i, 1, n) rep(j, 1, n) {
    chkmin(dis[i][j], dis[i][k] + dis[k][j]);
  }
  memset(mn, 0x3f, sizeof mn);
  memset(mx, -0x3f, sizeof mx);
  rep(i, 1, n) rep(j, 1, n) if (i != j) {
    dis[i][j] = dis[i][j] * 50 + i;
    chkmin(mn[i], dis[i][j]), chkmax(mx[i], dis[i][j]);
  }
  ll ans = 0;
  cin >> g1 >> g2 >> s1 >> s2;
  rep(i, 1, n) rep(j, 1, n) if (i != j && mn[i] < mx[j]) {
    rep(k, 1, n) {
      isg[k] = mn[k] < mn[i], isb[k] = mx[k] > mx[j], iss[k] = 0;
      rep(p, 1, n) if (dis[k][p] > mn[i] && dis[k][p] < mx[j]) {
        iss[k] = 1; break;
      }
    }
    isg[i] = 1, iss[i] = isb[i] = 0;
    isb[j] = 1, isg[j] = iss[j] = 0;
    memset(dp, 0, sizeof dp);
    dp[0][0] = 1;
    rep(k, 1, n) per(p, g2, 0) per(q, s2, 0) {
      if (!isb[k]) dp[p][q] = 0;
      if (isg[k] && p) dp[p][q] += dp[p - 1][q];
      if (iss[k] && q) dp[p][q] += dp[p][q - 1];
    }
    rep(p, g1, g2) rep(q, s1, s2) ans += dp[p][q];
  }
  cout << ans << endl;
}

signed main() {
//  int T = read();
//  while (T--) solve();
  solve();
  return 0;
}
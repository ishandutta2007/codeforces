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
const int maxn = 3010;
ll dp[maxn][maxn];
int n, sz[maxn][maxn], par[maxn][maxn];

vector <int> E[maxn];

int rt;

void DFS(int u, int f) {
  sz[rt][u] = 1, par[rt][u] = f;
  for (int v : E[u]) if (v != f) {
    DFS(v, u), sz[rt][u] += sz[rt][v];
  }
}

ll DP(int u, int v) {
  if (u == v) return 0;
  if (~dp[u][v]) return dp[u][v];
  return dp[u][v] = max(DP(u, par[u][v]), DP(v, par[v][u])) + sz[u][v] * sz[v][u];
}

int main() {
  cin >> n;
  rep(i, 2, n) {
    int u = read(), v = read();
    E[u].push_back(v), E[v].push_back(u);
  }
  rep(u, 1, n) {
    rt = u, DFS(u, 0);
  }
  ll res = 0;
  memset(dp, -1, sizeof dp);
  rep(u, 1, n) rep(v, 1, n) {
    chkmax(res, DP(u, v));
  }
  cout << res;
  return 0;
}
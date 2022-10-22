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

typedef double db;
typedef long long ll;
typedef vector <int> vi;
typedef pair <int, int> pii;
const int maxn = 1510, P = 998244353;

int n, A[maxn][maxn]; pii mp[maxn * maxn / 2];

vi vec[maxn];
int par[maxn], vsz[maxn], esz[maxn];

int find(int x) {
  return par[x] == x ? x : par[x] = find(par[x]);
}

vi E[maxn << 1];
int tot, sz[maxn << 1], dp[maxn << 1][maxn << 1];

void dfs(int u) {
  bool flg = 0;
  sz[u] = u <= n;
  for (int v : E[u]) {
//    printf("(%d %d)\n", u, v);
    dfs(v);
    if (flg) {
      static int data[maxn];
      memset(data, 0, sizeof data);
      per(i, sz[u], 1) rep(j, 1, sz[v]) {
        data[i + j] = (data[i + j] + 1ll * dp[u][i] * dp[v][j]) % P;
      }
      memcpy(dp[u], data, sizeof data);
    } else {
      flg = 1, memcpy(dp[u], dp[v], sizeof dp[u]);
    }
    sz[u] += sz[v];
  }
  dp[u][1] = 1;
//  printf("#%d : ", u);
//  rep(i, 1, sz[u]) printf("%d ", dp[u][i]);
//  puts("");
}

void solve() {
  cin >> n;
  rep(i, 1, n) rep(j, 1, n) {
    A[i][j] = read();
    if (i < j) mp[A[i][j]] = {i, j};
  }
  tot = n;
  rep(i, 1, n) par[i] = i, vsz[i] = 1, vec[i].push_back(i);
  rep(i, 0, maxn * maxn / 2 - 1) {
    int u = mp[i].first, v = mp[i].second;
    if (u && v) {
      u = find(u), v = find(v);
      if (u != v) {
        if (vec[u].size() < vec[v].size()) swap(u, v);
        par[v] = u, vsz[u] += vsz[v], esz[u] += esz[v];
        for (int x : vec[v]) vec[u].push_back(x);
        vec[v].clear();
      }
      if (++esz[u] == vsz[u] * (vsz[u] - 1) / 2) {
        tot++;
        for (int x : vec[u]) E[tot].push_back(x);
        vec[u].clear(), vec[u].push_back(tot);
      }
    }
  }
  tot++;
  rep(i, 1, n) if (find(i) == i) {
    for (int x : vec[i]) E[tot].push_back(x);
  }
  dfs(tot);
  rep(i, 1, n) printf("%d ", dp[tot][i]);
}

signed main() {
//  int T = read();
//  while (T--) solve();
  solve();
  return 0;
}
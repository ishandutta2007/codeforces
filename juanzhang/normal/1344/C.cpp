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
const int maxn = 2e5 + 10;
int n, m;
char ans[maxn];

int vis[maxn];
bool vis1[maxn], vis2[maxn];

vector <int> G[maxn], revG[maxn];

bool dfs(int u) {
  vis[u] = 2;
  for (int v : G[u]) {
    if (vis[v] == 2 || (!vis[v] && !dfs(v))) return 0;
  }
  return vis[u] = 1, 1;
}

void dfs1(int u) {
  vis1[u] = 1;
  for (int v : G[u]) if (!vis1[v]) {
    dfs1(v);
  }
}

void dfs2(int u) {
  vis2[u] = 1;
  for (int v : revG[u]) if (!vis2[v]) {
    dfs2(v);
  }
}

void solve() {
  cin >> n >> m;
  rep(i, 1, m) {
    int u = read(), v = read();
    G[u].push_back(v), revG[v].push_back(u);
  }
  rep(i, 1, n) if (!vis[i] && !dfs(i)) {
    puts("-1"); return;
  }
  int res = 0;
  rep(i, 1, n) {
    if (vis1[i] || vis2[i]) {
      ans[i] = 'E';
    } else {
      res++, ans[i] = 'A';
    }
    dfs1(i), dfs2(i);
  }
  cout << res << endl;
  rep(i, 1, n) putchar(ans[i]);
}

int main() {
//  int T = read();
//  while (T--) solve();
  solve();
  return 0;
}
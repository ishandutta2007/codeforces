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
const int maxn = 3e5 + 10;
int n, deg[maxn];

vector <int> E[maxn];

int dis[maxn];

int bfs(int S) {
  static int Q[maxn];
  int l = 1, r = 1;
  rep(i, 1, n) dis[i] = -1;
  Q[1] = S, dis[S] = deg[S] - 1;
  while (l <= r) {
    int u = Q[l++];
    for (int v : E[u]) if (dis[v] == -1) {
      dis[v] = dis[u] + deg[v] - 1, Q[++r] = v;
    }
  }
  int pos = 1;
  rep(i, 1, n) if (deg[i] == 1 && dis[pos] < dis[i]) {
    pos = i;
  }
  return pos;
}

void solve() {
  cin >> n;
  rep(i, 2, n) {
    int u = read(), v = read();
    E[u].push_back(v), deg[u]++;
    E[v].push_back(u), deg[v]++;
  }
  int S = bfs(1);
  int T = bfs(S);
  printf("%d\n", dis[T] + 2);
  rep(i, 1, n) E[i].clear(), deg[i] = 0;
}

signed main() {
  int T = read();
  while (T--) solve();
//  solve();
  return 0;
}
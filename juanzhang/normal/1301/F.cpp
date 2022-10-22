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

const int dx[] = {-1, 0, 1, 0};
const int dy[] = {0, 1, 0, -1};
const int maxn = 1010;
int n, m, k, q, a[maxn][maxn], dis[41][maxn][maxn];

struct point {
  int x, y;
};

vector <point> pos[41];

void bfs(int col) {
  static bool vis[maxn * maxn + 101];
  static int Q[maxn * maxn + 101], val[maxn * maxn + 101];
  memset(vis, 0, sizeof vis);
  memset(val, 0x3f, sizeof val);
  int l = 45, r = l;
  Q[l] = n * m + col, val[n * m + col] = 0;
  while (l <= r) {
    int u = Q[l++];
    if (vis[u]) continue;
    vis[u] = 1;
    if (u > n * m) {
      for (point p : pos[u - n * m]) {
        int &v = val[(p.x - 1) * m + p.y];
        if (v > val[u] + 1) {
          v = val[u] + 1, Q[++r] = (p.x - 1) * m + p.y;
        }
      }
    } else {
      int x = (u - 1) / m + 1, y = (u - 1) % m + 1;
      rep(i, 0, 3) {
        int tx = x + dx[i], ty = y + dy[i];
        if (tx < 1 || ty < 1 || tx > n || ty > m) {
          continue;
        }
        int &v = val[(tx - 1) * m + ty];
        if (v > val[u] + 1) {
          v = val[u] + 1, Q[++r] = (tx - 1) * m + ty;
        }
      }
      int &v = val[n * m + a[x][y]];
      if (v > val[u]) {
        v = val[u], Q[--l] = n * m + a[x][y];
      }
    }
  }
  rep(i, 1, n) rep(j, 1, m) {
    dis[col][i][j] = val[(i - 1) * m + j];
  }
}

int main() {
  scanf("%d %d %d", &n, &m, &k);
  rep(i, 1, n) rep(j, 1, m) {
    a[i][j] = read(), pos[a[i][j]].push_back({i, j});
  }
  rep(i, 1, k) {
    bfs(i);
  }
  scanf("%d", &q);
  while (q--) {
    int x1 = read(), y1 = read();
    int x2 = read(), y2 = read();
    int ans = abs(x1 - x2) + abs(y1 - y2);
    rep(i, 1, k) chkmin(ans, dis[i][x1][y1] + dis[i][x2][y2] - 1);
    printf("%d\n", ans);
  }
  return 0;
}
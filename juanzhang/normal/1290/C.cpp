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

const int maxn = 3e5 + 10;
char str[maxn];
int n, k, ans, data[maxn][2], par[maxn << 1], sz[maxn << 1][2];

int find(int x) {
  return par[x] == x ? x : par[x] = find(par[x]);
}

void unite(int x, int y) {
  if ((x = find(x)) != (y = find(y))) {
    par[y] = x;
    ans -= min(sz[x][0], sz[x][1]);
    ans -= min(sz[y][0], sz[y][1]);
    sz[x][0] += sz[y][0], sz[x][1] += sz[y][1];
    ans += min(sz[x][0], sz[x][1]);
  }
}

int main() {
  scanf("%d %d %s", &n, &k, str + 1);
  rep(i, 1, k) {
    int x = read();
    while (x--) {
      int p = read();
      data[p][(bool) data[p][0]] = i;
    }
  }
  rep(i, 1, k * 2 + 1) {
    par[i] = i, sz[i][i > k] = 1;
  }
  rep(i, 1, n) {
    int tmp = data[i][1] + (data[i][1] ? k : k * 2 + 1);
    if (str[i] == '1') {
      unite(data[i][0], data[i][1]);
      unite(data[i][0] + k, tmp);
    } else {
      unite(data[i][0], tmp);
      unite(data[i][0] + k, data[i][1]);
    }
    int u = find(0);
    printf("%d\n", ans / 2 - (sz[u][0] < sz[u][1] ? sz[u][0] - sz[u][1] : 0));
  }
  return 0;
}
#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 2e5 + 50;

struct edge {
  int nxt, to;
} e[N << 1];
int fir[N], cnt = 1;
long long sum[N][2], sz[N][2];

inline void addedge(int x, int y) {
  e[++ cnt] = (edge) { fir[x], y }; fir[x] = cnt;
}

long long ans = 0;
int n;

inline void Dfs(int x, int f) {
  sz[x][0] = 1;
  for (int i = fir[x]; i; i = e[i].nxt)
    if (e[i].to != f) {
      int y = e[i].to;
      Dfs(y, x);
      swap(sum[y][0], sum[y][1]);
      swap(sz[y][0], sz[y][1]);
      sum[y][0] += sz[y][0];
      sum[y][1] += sz[y][1];
      for (int a = 0; a < 2; a ++)
        for (int b = 0; b < 2; b ++)
          if ((a + b) & 1) ans += (sum[x][a] * sz[y][b] + sum[y][b] * sz[x][a] + sz[x][a] * sz[y][b]) >> 1;
          else ans += (sum[x][a] * sz[y][b] + sum[y][b] * sz[x][a]) >> 1;
      sz[x][0] += sz[y][0];
      sz[x][1] += sz[y][1];
      sum[x][0] += sum[y][0];
      sum[x][1] += sum[y][1];
    }
}

int main() {
  scanf("%d", &n);
  for (int i = 1, x, y; i < n; i ++) {
    scanf("%d%d", &x, &y);
    addedge(x, y); addedge(y, x);
  }
  Dfs(1, 0);
  printf("%lld\n", ans);
  return 0;
}
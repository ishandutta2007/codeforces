#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
bool vis[2][2];
int x[3], y[3];
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    memset(vis, false, sizeof(vis));
    int x0 = -1, y0 = -1;
    for (int i = 0; i < 3; i++) {
      scanf("%d%d", &x[i], &y[i]);
      vis[x[i] & 1][y[i] & 1] = true;
      if ((x[i] == 1 || x[i] == n) && (y[i] == 1 || y[i] == n)) {
        x0 = x[i];
        y0 = y[i];
      }
    }
    bool flg = ~x0;
    for (int i = 0; i < 3; i++)
      if (x0 != x[i] && y0 != y[i]) flg = false;
    int xx, yy;
    scanf("%d%d", &xx, &yy);
    if (flg)
      puts(xx == x0 || yy == y0 ? "YES" : "NO");
    else
      puts(vis[xx & 1][yy & 1] ? "YES" : "NO");
  }
  return 0;
}
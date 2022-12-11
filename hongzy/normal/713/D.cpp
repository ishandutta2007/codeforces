#include <algorithm>
#include <cstdio>
using namespace std;
const int N = 1003;
int n, m, lg[N], a[N][N][10][10];
short b[N][N];
int query(int x1, int y1, int x2, int y2) {
  int k1 = lg[x2 - x1 + 1], k2 = lg[y2 - y1 + 1];
  return max(max(a[x1][y1][k1][k2], a[x2 - (1 << k1) + 1][y1][k1][k2]), 
    max(a[x1][y2 - (1 << k2) + 1][k1][k2], a[x2 - (1 << k1) + 1][y2 - (1 << k2) + 1][k1][k2]));
}
int main() {
  scanf("%d%d", &n, &m);
  for(int i = 1; i <= n; i ++) {
    for(int j = 1; j <= m; j ++) {
      scanf("%hd", &b[i][j]);
      if(b[i][j]) a[i][j][0][0] = min(a[i - 1][j][0][0], min(a[i][j - 1][0][0], a[i - 1][j - 1][0][0])) + 1;
    }
  }
  for(int i = 2; i <= max(n, m); i ++) lg[i] = lg[i >> 1] + 1;
  for(int i = 1; i <= lg[m]; i ++) {
    for(int x = 1; x <= n; x ++) {
      for(int y = 1; y + (1 << i) - 1 <= m; y ++) {
        a[x][y][0][i] = max(a[x][y][0][i - 1], a[x][y + (1 << (i - 1))][0][i - 1]);
      }
    }
  }
  for(int i = 1; i <= lg[n]; i ++) {
    for(int j = 0; j <= lg[m]; j ++) {
      for(int x = 1; x + (1 << i) - 1 <= n; x ++) {
        for(int y = 1; y + (1 << j) - 1 <= m; y ++) {
          a[x][y][i][j] = max(a[x][y][i - 1][j], a[x + (1 << (i - 1))][y][i - 1][j]);
        }
      }
    }
  }
  int t; scanf("%d", &t);
  while(t --) {
    int x1, y1, x2, y2;
    scanf("%d%d%d%d", &x1, &y1, &x2, &y2);
    int l = 1, r = min(x2 - x1 + 1, y2 - y1 + 1), ans = 0;
    while(l <= r) {
      int mid = (l + r) >> 1;
      if(query(x1 + mid - 1, y1 + mid - 1, x2, y2) >= mid) l = (ans = mid) + 1;
      else r = mid - 1;
    }
    printf("%d\n", ans);
  }
  return 0;
}
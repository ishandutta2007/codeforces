#include <bits/stdc++.h>
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;
typedef double db;
const int N = 2048;
int n, m;
bool a[N], b[N];
db f[N][N];
int main() {
  scanf("%d%d", &n, &m);
  rep(i, 1, m) {
    int x, y;
    scanf("%d%d", &x, &y);
    a[x] = b[y] = 1;
  }
  int h = 0, c = 0;
  rep(i, 1, n) h += a[i], c += b[i];
  f[n][n] = 0;
  per(i, n, 0) per(j, (i == n ? n - 1 : n), 0) {
    f[i][j] = 1;
    f[i][j] += 1.0 * (n - i) / n * j / n * f[i + 1][j];
    f[i][j] += 1.0 * i / n * (n - j) / n * f[i][j + 1];
    f[i][j] += 1.0 * (n - i) / n * (n - j) / n * f[i + 1][j + 1];
    f[i][j] /= 1.0 - 1.0 * i / n * j / n;
  }
  printf("%.10f\n", f[h][c]);
  return 0;
}
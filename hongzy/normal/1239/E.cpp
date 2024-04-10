#include <bits/stdc++.h>
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;
const int N = 52;
const int M = 1250000 + 5;
int n, s, a[N], res[2][N], pre[N][M];
bool f[N][M], vis[N];
int main() {
  scanf("%d", &n);
  rep(i, 1, 2 * n) scanf("%d", a + i);
  sort(a + 1, a + 2 * n + 1);
  res[0][1] = a[1]; res[1][n] = a[2];
  f[0][0] = 1;
  rep(t, 3, 2 * n) {
    s += a[t];
    per(i, min(t - 2, n - 1), 1) {
      rep(j, a[t], s)
        if(!f[i][j] && f[i - 1][j - a[t]])
          f[i][j] = 1, pre[i][j] = t;
    }
  }
  s /= 2;
  per(i, s, 0) if(f[n - 1][i]) {
    int sz = i;
    per(j, n - 1, 1) {
      int z = pre[j][sz];
      vis[z] = 1;
      sz -= a[z];
    }
    break ;
  }
  int p1 = 2, p2 = n - 1;
  rep(i, 3, 2 * n)
    if(vis[i]) res[0][p1++] = a[i];
    else res[1][p2--] = a[i];
  rep(i, 0, 1) rep(j, 1, n) printf("%d%c", res[i][j], " \n"[j == n]);
  return 0;
}
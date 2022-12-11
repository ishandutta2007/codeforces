#include <bits/stdc++.h>
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;
typedef double db;
const int N = 1005;
int n, m, a[N];
db f[N][N], g[N][N];
int main() {
   scanf("%d%d", &n, &m);
   rep(i, 1, n) scanf("%d", a + i);
   rep(i, 1, n) rep(j, 1, n) f[i][j] = a[i] > a[j];
   int a, b;
   rep(i, 1, m) {
      scanf("%d%d", &a, &b);
      f[a][b] = f[b][a] = 0.5;
      rep(u, 1, n) g[a][u] = f[a][u], g[u][a] = f[u][a], g[b][u] = f[b][u], g[u][b] = f[u][b];
      rep(u, 1, n) {
         if(u != a && u != b) {
            f[u][b] = (g[u][b] + g[u][a]) * 0.5;
            f[b][u] = (g[b][u] + g[a][u]) * 0.5;
         }
         if(u != b && u != a) {
            f[u][a] = (g[u][a] + g[u][b]) * 0.5;
            f[a][u] = (g[a][u] + g[b][u]) * 0.5;
         }
      }
   }
   db ans = 0;
   rep(i, 1, n) rep(j, i + 1, n) ans += f[i][j];
   printf("%.9f\n", ans);
   return 0;
}
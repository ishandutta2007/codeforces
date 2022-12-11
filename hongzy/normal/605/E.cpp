#include <bits/stdc++.h>
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;
typedef double db;
const int N = 1005;
int n, x;
db p[N][N], E[N], pd[N];
bool vis[N];
int main() {
   scanf("%d", &n);
   rep(i, 1, n) rep(j, 1, n) scanf("%d", &x), p[i][j] = x / 100.0;
   if(n == 1) puts("0"), exit(0);
   vis[n] = 1; E[n] = 0;
   rep(i, 1, n - 1) E[i] = 1, pd[i] = 1 - p[i][n];
   rep(i, 2, n) {
      x = 0; db mn = 1e18;
      rep(j, 1, n) if(!vis[j] && (!x || E[j] / (1 - pd[j]) < mn)) mn = E[x = j] / (1 - pd[j]);
      if(x == 1) printf("%.10f\n", mn), exit(0);
      vis[x] = 1;
      rep(j, 1, n) if(!vis[j]) E[j] += mn * p[j][x] * pd[j], pd[j] *= 1 - p[j][x];
   }
   return 0;
}
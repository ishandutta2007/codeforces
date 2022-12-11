#include <bits/stdc++.h>
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;
const int N = 1029;
int n, m, a[N][N], p[N][N], q[N][N];
int main() {
  int test;
  scanf("%d", &test);
  rep(T, 1, test) {
    scanf("%d%d", &n, &m);
    rep(i, 1, n) rep(j, 1, m) scanf("%d", a[i] + j);
    if((n + m) % 2 == 0) {
      puts("NO");
      continue ;
    }
    per(i, n, 1) per(j, m, 1) {
      if(i == n && j == m) {
        p[n][m] = q[n][m] = a[n][m];
        continue ;
      }
      if(i == n) {
        p[n][j] = p[n][j + 1] + a[i][j];
        q[n][j] = q[n][j + 1] + a[i][j];
      } else if(j == m) {
        p[i][m] = p[i + 1][m] + a[i][j];
        q[i][m] = q[i + 1][m] + a[i][j];
      } else {
        p[i][j] = min(p[i + 1][j], p[i][j + 1]) + a[i][j];
        q[i][j] = max(q[i + 1][j], q[i][j + 1]) + a[i][j];
      }
    }
    puts(p[1][1] <= 0 && 0 <= q[1][1] ? "YES" : "NO");
  }
  return 0;
}
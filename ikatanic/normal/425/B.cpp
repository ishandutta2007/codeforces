#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>

using namespace std;

#define TRACE(x) cout << #x << " = " << x << endl
#define REP(i, n) for (int i = 0; i < (n); ++i)

typedef long long llint;

const int inf = 1e9;

int a[110][110];
int b[110][110];

int main(void) {
  int n, m, k;
  scanf("%d %d %d", &n, &m, &k);
  REP(i, n) REP(j, m) scanf("%d", &a[i][j]);

  if (n < m) {
    REP(i, n) REP(j, m) b[i][j] = a[i][j];
    REP(i, n) REP(j, m) a[j][i] = b[i][j];
    swap(n, m);
  }

  if (m <= k) {
    static int f[110][1<<10];
    memset(f, 63, sizeof(f));
    
    REP(i, 1<<m) f[0][i] = 0;
    REP(i, n) REP(s, 1<<m) {
      int c1 = 0, c2 = 0;
      REP(j, m)
        if (((s>>j)&1) == a[i][j]) c2++; else
          c1++;
      int t = s^((1<<m)-1);
      f[i+1][s] = min(f[i+1][s], f[i][s] + c1);
      f[i+1][t] = min(f[i+1][t], f[i][s] + c2);
    }

    int ans = inf;
    REP(s, 1<<m)
      ans = min(ans, f[n][s]);
    if (ans > k) ans = -1;
    printf("%d\n", ans);
    return 0;
  }

  int ans = inf;
  REP(i, n) {
    int cost = 0;
    REP(j, n) {
      int c1 = 0, c2 = 0;
      REP(k, m)
        if (a[j][k] == a[i][k]) c1++; else
          c2++;
      cost += min(c1, c2);
    }
    ans = min(ans, cost);
  }

  if (ans > k) ans = -1;
  printf("%d\n", ans);
  return 0;
}
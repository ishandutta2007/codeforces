#include <bits/stdc++.h>
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;
const int N = 1024, INF = 1e9;
int n, m, aa[N][N], ab[N][N], ba[N][N], bb[N][N], ans[N][N];
char s[N][N];
int main() {
  int test;
  scanf("%d", &test);
  while(test --) {
    scanf("%d%d", &n, &m);
    rep(i, 1, n) scanf("%s", s[i] + 1);

    rep(j, 1, m) aa[0][j] = aa[n + 1][j] = -INF;
    rep(i, 1, n) aa[i][0] = aa[i][m + 1] = -INF;
    rep(i, 1, n) rep(j, 1, m) {
      aa[i][j] = max(aa[i - 1][j], aa[i][j - 1]) + 1;
      if(s[i][j] == 'B' && aa[i][j] < 0) aa[i][j] = 0;
    }

    rep(j, 1, m) ab[0][j] = ab[n + 1][j] = -INF;
    rep(i, 1, n) ab[i][0] = ab[i][m + 1] = -INF;
    rep(i, 1, n) per(j, m, 1) {
      ab[i][j] = max(ab[i - 1][j], ab[i][j + 1]) + 1;
      if(s[i][j] == 'B' && ab[i][j] < 0) ab[i][j] = 0;
    }

    rep(j, 1, m) ba[0][j] = ba[n + 1][j] = -INF;
    rep(i, 1, n) ba[i][0] = ba[i][m + 1] = -INF;
    per(i, n, 1) rep(j, 1, m) {
      ba[i][j] = max(ba[i + 1][j], ba[i][j - 1]) + 1;
      if(s[i][j] == 'B' && ba[i][j] < 0) ba[i][j] = 0;
    }

    rep(j, 1, m) bb[0][j] = bb[n + 1][j] = -INF;
    rep(i, 1, n) bb[i][0] = bb[i][m + 1] = -INF;
    per(i, n, 1) per(j, m, 1) {
      bb[i][j] = max(bb[i + 1][j], bb[i][j + 1]) + 1;
      if(s[i][j] == 'B' && bb[i][j] < 0) bb[i][j] = 0;
    }

    int res = INF, x = 0, y = 0;
    rep(i, 1, n) rep(j, 1, m) {
      res = min(res, ans[i][j] = max(aa[i][j], max(ab[i][j], max(ba[i][j], bb[i][j]))));
    }
    rep(i, 1, n) rep(j, 1, m) {
      // printf("ans %d %d = %d\n", i, j, ans[i][j]);
      if(res == ans[i][j]) {
        x = i; y = j;
      }
    }
    printf("%d %d\n", x, y);
  }
  return 0;
}
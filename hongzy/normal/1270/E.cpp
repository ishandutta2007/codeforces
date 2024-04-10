#include <bits/stdc++.h>
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
using namespace std;
const int N = 1024;
int x[N], y[N], n;
int main() {
  scanf("%d", &n);
  rep(i, 1, n) {
    scanf("%d%d", x + i, y + i);
    x[i] += 1e6; y[i] += 1e6;
  }
  while(1) {
    int cnt[2][2] = {0};
    rep(i, 1, n) cnt[x[i] & 1][y[i] & 1] ++;
    if(cnt[0][0] + cnt[1][1] > 0 && cnt[0][0] + cnt[1][1] < n) {
      int ans = 0;
      rep(i, 1, n) if((x[i] & 1) == (y[i] & 1)) ans ++;
      printf("%d\n", ans);
      rep(i, 1, n) if((x[i] & 1) == (y[i] & 1)) {
        printf("%d ", i);
      }
      putchar('\n');
      break ;
    }
    if((cnt[0][0] > 0) + (cnt[1][1] > 0) + (cnt[1][0] > 0) + (cnt[0][1] > 0) == 1) {
      rep(i, 1, n) x[i] >>= 1, y[i] >>= 1;
    } else {
      cnt[x[1] & 1][y[1] & 1] = -1;
      int ans = 0;
      rep(i, 1, n) if(-1 == cnt[x[i] & 1][y[i] & 1]) ans ++;
      printf("%d\n", ans);
      rep(i, 1, n) if(-1 == cnt[x[i] & 1][y[i] & 1]) {
        printf("%d ", i);
      }
      putchar('\n');
      break ;
    }
  }
  return 0;
}
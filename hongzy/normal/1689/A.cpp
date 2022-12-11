#include <bits/stdc++.h>
#define pb push_back
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;
const int N = 3e5 + 10;
int n, m, k;
char a[N], b[N];
int main() {
  int test;
  scanf("%d", &test);
  while(test --) {
    scanf("%d%d%d%s%s", &n, &m, &k, a + 1, b + 1);
    sort(a + 1, a + n + 1);
    sort(b + 1, b + m + 1);
    int la = -1, cnt = 0, x = 1, y = 1;
    rep(i, 1, n + m) {
      if(x > n || y > m) break ;
      int cur = 0;
      if(cnt == k) cur = la ^ 1;
      else cur = a[x] < b[y] ? 0 : 1;
      if(la != cur) cnt = 0;
      ++ cnt;
      // printf("cur = %d, cnt = %d\n", cur, cnt);
      putchar(cur ? b[y ++] : a[x ++]);
      la = cur;
    }
    putchar('\n');
  }
  return 0;
}
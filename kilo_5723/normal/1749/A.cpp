#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn = 10;
int cnt1[maxn], cnt2[maxn];
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n, m;
    scanf("%d%d", &n, &m);
    int flg = 0;
    memset(cnt1, 0, sizeof(cnt1));
    memset(cnt2, 0, sizeof(cnt2));
    for (int i = 0; i < m; i++) {
      int x, y;
      scanf("%d%d", &x, &y);
      flg += cnt1[x]++ + cnt2[y]++;
    }
    if (m > n) {
      puts("NO");
      continue;
    }
    if (m == n) {
      puts(flg == 1 ? "YES" : "NO");
      continue;
    }
    puts(flg > 1 ? "NO" : "YES");
  }
  return 0;
}
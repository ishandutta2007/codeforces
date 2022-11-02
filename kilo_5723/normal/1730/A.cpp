#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
const int maxn = 105;
int cnt[maxn];
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n, c;
    scanf("%d%d", &n, &c);
    memset(cnt, 0, sizeof(cnt));
    for (int i = 0; i < n; i++) {
      int t;
      scanf("%d", &t);
      cnt[t]++;
    }
    int ans = 0;
    for (int i = 0; i < maxn; i++) ans += min(cnt[i], c);
    printf("%d\n", ans);
  }
  return 0;
}
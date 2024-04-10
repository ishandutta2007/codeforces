#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
const int maxn = 55;
bool vis[maxn];
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n;
    scanf("%d", &n);
    fill(vis, vis + n + 1, false);
    bool flg = true;
    for (int i = 0; i < n; i++) {
      int t;
      scanf("%d", &t);
      // printf("%d -> ", t);
      // printf("here %d\n", t);
      while ((t > n) || vis[t]) t >>= 1;
      if (!t)
        flg = false;
      else
        vis[t] = true;
      // printf("%d\n", t);
    }
    puts(flg ? "YES" : "NO");
  }
  return 0;
}
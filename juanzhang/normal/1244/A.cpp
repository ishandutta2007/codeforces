#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a), i##end = (b); i <= i##end; ++i)
#define per(i, a, b) for (int i = (a), i##end = (b); i >= i##end; --i)

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

int main() {
  int T;
  scanf("%d", &T);
  while (T--) {
    int a, b, c, d, k;
    scanf("%d %d %d %d %d", &a, &b, &c, &d, &k);
    bool flg = 0;
    for (int i = 0; i <= 100 && !flg; i++) {
      for (int j = 0; j <= 100 && !flg; j++) {
        if (i * c >= a && j * d >= b && i + j <= k) {
          printf("%d %d\n", i, j), flg = 1;
        }
      }
    }
    if (!flg) puts("-1");
  }
  return 0;
}
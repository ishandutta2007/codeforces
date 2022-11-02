#include <algorithm>
#include <cstdio>
#include <iostream>
using namespace std;
const int maxn = 1e5 + 5, maxm = 32;
int a[maxn], pl[maxn], pr[maxn], po[maxn], s[maxn], l[maxn][maxm],
    r[maxn][maxm];
int main() {
  int tt;
  scanf("%d", &tt);
  while (tt--) {
    int n, m;
    scanf("%d%d", &n, &m);
    int k = 0;
    for (int i = 0; i < n; i++) {
      int t;
      scanf("%d", &t);
      if (t) {
        pl[i] = pr[i] = k;
        po[k] = i + 1;
        a[k++] = t;
      } else {
        pl[i] = k - 1;
        pr[i] = k;
      }
    }
    n = k;
    for (int i = 0; i < n; i++) s[i + 1] = s[i] ^ a[i];
    fill(l[0], l[n + 1], -1);
    fill(r[0], r[n + 1], -1);
    for (int i = 0; i < n; i++) {
      l[i][0] = r[i][0] = 0;
      for (int j = 1; j < maxm; j++) {
        int k = i - j + 1;
        if (k < 0 || (a[k] & l[i][j - 1])) break;
        l[i][j] = (a[k] | l[i][j - 1]);
      }
      for (int j = 1; j < maxm; j++) {
        int k = i + j - 1;
        if (k < 0 || (a[k] & r[i][j - 1])) break;
        r[i][j] = (a[k] | r[i][j - 1]);
      }
    }
    while (m--) {
      int p, q;
      scanf("%d%d", &p, &q);
      if (pr[p - 1] > pl[q - 1]) {
        printf("%d %d\n", p, p);
        continue;
      }
      p = pr[p - 1];
      q = pl[q - 1];
      int x = 0, y = 0, xr = s[q + 1] ^ s[p];
      // printf("%d: ", xr);
      for (int i = 0; i < maxm && ~r[p][i]; i++)
        if ((xr & r[p][i]) == r[p][i])
          for (int j = 0; j < maxm && ~l[q][j]; j++)
            if ((xr & l[q][j]) == l[q][j])
              if (p + i <= q - j && !(r[p][i] & l[q][j]) &&
                  po[q - j] - po[p + i] < po[q - y] - po[p + x]) {
                x = i;
                y = j;
              }
      printf("%d %d\n", po[p + x], po[q - y]);
    }
    // puts("");
  }
  return 0;
}
/*
1 1

1 1
2 2

1 1
1 1
2 2

2 3
2 3
2 3
2 3

2 3
2 3
2 3
2 3
3 4

2 4
4 6
2 4
2 4
4 6
2 4
2 4

*/
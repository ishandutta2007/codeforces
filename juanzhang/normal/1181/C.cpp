#include <bits/stdc++.h>
using namespace std;

const int maxn = 1010;
char a[maxn][maxn];
int n, m, lg[maxn], r[maxn][maxn], c[maxn][maxn];

struct RMQ {
  int val[11][maxn];

  inline void build(int *a) {
    for (int i = 1; i <= n; i++) {
      val[0][i] = a[i];
    }
    for (int i = 1; i < 11; i++) {
      for (int j = 1; j + (1 << i) - 1 <= n; j++) {
        val[i][j] = min(val[i - 1][j], val[i - 1][j + (1 << (i - 1))]);
      }
    }
  }

  inline int query(int l, int r) {
    int k = lg[r - l + 1];
    return min(val[k][l], val[k][r - (1 << k) + 1]);
  }
} ST[maxn];

int main() {
  for (int i = 2; i < 1001; i++) {
    lg[i] = lg[i >> 1] + 1;
  }
  scanf("%d %d", &n, &m);
  for (int i = 1; i <= n; i++) {
    scanf("%s", a[i] + 1);
  }
  for (int i = n; i; i--) {
    for (int j = m; j; j--) {
      r[j][i] = (a[i][j] == a[i][j + 1] ? r[j + 1][i] : 0) + 1;
      c[i][j] = (a[i][j] == a[i + 1][j] ? c[i + 1][j] : 0) + 1;
    }
  }
  for (int i = 1; i <= m; i++) {
    ST[i].build(r[i]);
  }
  long long ans = 0;
  for (int i = 1; i <= n; i++) {
    for (int j = 1; j <= m; j++) {
      int x = i + c[i][j];
      if (x > n || c[i][j] != c[x][j]) continue;
      int y = x + c[i][j];
      if (y > n || c[i][j] > c[y][j]) continue;
      ans += ST[j].query(i, y + c[i][j] - 1);
    }
  }
  printf("%I64d", ans);
  return 0;
}
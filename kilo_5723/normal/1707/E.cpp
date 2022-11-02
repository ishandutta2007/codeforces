#include <cstdio>
#include <iostream>
#include <set>
#include <vector>
using namespace std;
const int maxn = 1e5 + 5, maxm = 20;
int a[maxn];
struct seg {
  int l, r;
};
seg operator+(const seg &a, const seg &b) {
  return {min(a.l, b.l), max(a.r, b.r)};
}
seg st[maxm][maxn][maxm];
int log[maxn];
seg query(int i, int l, int r) {
  int k = log[r - l];
  // cout << i << ' ' << l << ' ' << r << ' ' << k << ": ";
  // cout << st[i][l][k].l << ' ' << st[i][l][k].r << ' '
  //      << st[i][r - (1 << k)][k].l << ' ' << st[i][r - (1 << k)][k].r <<
  //      endl;
  return st[i][l][k] + st[i][r - (1 << k)][k];
}
int main() {
  log[1] = 0;
  for (int i = 2; i < maxn; i++) log[i] = log[i >> 1] + 1;
  int n, q;
  scanf("%d%d", &n, &q);
  for (int i = 0; i < n; i++) scanf("%d", &a[i]);
  for (int i = 0; i < maxm; i++)
    for (int j = n - 1; j; j--) {
      if (i) {
        auto t = query(i - 1, j, j + 1);
        // cout << i << ' ' << j << ' ' << t.l << ' ' << t.r << ',';
        st[i][j][0] = query(i - 1, t.l, t.r);
        // cout << st[i][j][0].l << ' ' << st[i][j][0].r << endl;

      } else {
        st[i][j][0] = {min(a[j - 1], a[j]), max(a[j - 1], a[j])};
      }
      for (int k = 1; j + (1 << k) <= n; k++)
        st[i][j][k] = st[i][j][k - 1] + st[i][j + (1 << (k - 1))][k - 1];
    }
  // for (int k = 0; k < 3; k++) {
  //   for (int i = 1; i + (1 << 0) <= n; i++)
  //     cout << st[k][i][0].l << ',' << st[k][i][0].r << " ; ";
  //   cout << endl;
  //   for (int i = 1; i + (1 << 1) <= n; i++)
  //     cout << st[k][i][1].l << ',' << st[k][i][1].r << " ; ";
  //   cout << endl;
  //   for (int i = 1; i + (1 << 2) <= n; i++)
  //     cout << st[k][i][2].l << ',' << st[k][i][2].r << " ; ";
  //   cout << endl;
  // }
  while (q--) {
    int l, r;
    scanf("%d%d", &l, &r);
    if (l == 1 && r == n) {
      puts("0");
      continue;
    }
    if (l == r) {
      puts("-1");
      continue;
    }
    int ans = 0;
    for (int i = maxm - 1; i >= 0; i--) {
      auto pr = query(i, l, r);
      if (pr.l != 1 || pr.r != n) {
        ans += 1 << i;
        l = pr.l;
        r = pr.r;
      }
    }
    printf("%d\n", ans > 1e6 ? -1 : ans + 1);
  }
  return 0;
}
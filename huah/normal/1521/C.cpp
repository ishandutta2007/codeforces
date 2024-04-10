#include <bits/stdc++.h>

#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <exception>
#include <map>
#include <memory>
#include <ostream>
#include <queue>
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
#define mp(x, y) make_pair(x, y)
const int N = 1e5 + 5, bs = 320, mod = 1e9 + 7;
int n, a[N], b[N], c[N], d[N];
int query(int op, int x, int i, int j) {
  i = d[i];
  j = d[j];
  // if (op == 1)
  //   return max(min(x, b[i]), min(x + 1, b[j]));
  // else
  //   return min(max(x, b[i]), max(x + 1, b[j]));
  printf("? %d %d %d %d\n", op, i, j, x);
  fflush(stdout);
  int ans;
  scanf("%d", &ans);
  return ans;
}
int p, q;
void sol(int l, int r) {
  if (l > r) return;
  if (l == r) {
    a[d[l]] = query(2, 1, l, q);
    return;
  }
  if (l == r + 1) {
    int g = query(2, 1, l, q);
    if (g == c[l]) {
      a[d[l]] = g;
      a[d[r]] = query(2, 1, r, q);
    } else
      a[d[l]] = g, a[d[r]] = c[l];
    return;
  }
  int m = (l + r) >> 1;
  int g = query(2, 1, m, q);
  if (g == c[m]) {
    for (int i = l; i <= m; i++) a[d[i]] = c[i];
    sol(m + 1, r);
  } else {
    for (int i = m + 1; i <= r; i++) a[d[i]] = c[i - 1];
    a[d[m]] = g;
    sol(l, m - 1);
  }
}
int main() {
  srand(time(0));
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    for (int i = 1; i <= n; i++) d[i] = i;
    // for (int i = 1; i <= n; i++) b[i] = i;
    // random_shuffle(b + 1, b + 1 + n);
    if (n == 3) {
      a[1] = a[2] = a[3] = 0;
      for (int i = 1; i <= 3; i++)
        for (int j = 1; j <= 3; j++)
          if (i != j && query(1, n - 1, i, j) == n) {
            a[d[j]] = n;
            break;
          }
      for (int i = 1; i <= 3; i++)
        for (int j = 1; j <= 3; j++)
          if (i != j && query(2, 1, i, j) == 1) {
            a[d[i]] = 1;
            break;
          }
      for (int i = 1; i <= 3; i++)
        if (!a[d[i]]) a[d[i]] = 2;
      printf("! %d %d %d\n", a[1], a[2], a[3]);
      fflush(stdout);
      continue;
    }
    for (int i = 1; i <= n; i++) c[i] = a[i] = 0;
    random_shuffle(d + 1, d + 1 + n);
    p = -1, q = -1;
    for (int i = 1; i < n; i++) {
      int g = query(1, n - 1, i, i + 1);
      if (g >= n - 1) {
        int sum = 0;
        for (int j = 1; j <= n; j++)
          if (j != i && j != i + 1) {
            int h = query(1, n - 1, i, j);
            sum += h >= n - 1;
            if (h < n - 1 || sum == 2) break;
          }
        if (sum == 2) {
          if (p == -1)
            p = i;
          else
            q = i;
        } else {
          if (p == -1)
            p = i + 1;
          else
            q = i + 1;
          i++;
        }
      } else
        c[i] = g;
    }
    if (q == -1) q = n;
    if (query(1, n - 1, p, q) != n) swap(p, q);
    a[d[p]] = n - 1;
    a[d[q]] = n;
    // cout << "P: " << p << ' ' << q << endl;
    // assert(b[p] == n - 1 && b[q] == n);
    for (int i = 1; i < n; i++)
      if (c[i] == c[i + 1] && c[i] && !a[d[i + 1]]) a[d[i + 1]] = c[i];
    for (int i = 1; i <= n; i++)
      if (!a[d[i]]) {
        int r = i;
        while (r + 1 <= n && !a[d[r + 1]]) r++;
        sol(i, r);
        i = r;
      }
    printf("! ");
    for (int i = 1; i <= n; i++) printf(i == n ? "%d\n" : "%d ", a[i]);
    // for (int i = 1; i <= n; i++) printf(i == n ? "%d\n" : "%d ", b[i]);
    // for (int i = 1; i <= n; i++) assert(a[i] == b[i]);
    fflush(stdout);
  }
  return 0;
}
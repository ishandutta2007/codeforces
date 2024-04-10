#include <bits/stdc++.h>
using namespace std;

const int maxn = 4010;
int n, m, f[maxn][maxn], vis[maxn][maxn], pos[maxn][maxn];

struct node {
  int l, r;
} a[maxn];

vector <int> vec[maxn];

void discretize() {
  #define get_val(x) (x = lower_bound(data + 1, data + m + 1, x) - data)
  static int data[maxn];
  for (int i = 1; i <= n; i++) {
    data[++m] = a[i].l;
    data[++m] = a[i].r;
  }
  sort(data + 1, data + m + 1);
  m = unique(data + 1, data + m + 1) - data - 1;
  for (int i = 1; i <= n; i++) {
    get_val(a[i].l);
    get_val(a[i].r);
    vis[a[i].l][a[i].r] = i;
    vec[a[i].l].push_back(a[i].r);
  }
  #undef get_val
}

void print(int l, int r) {
  if (l > r) return;
  if (vis[l][r]) {
    printf("%d ", vis[l][r]);
  }
  if (l < r) {
    int x = pos[l][r];
    print(l, x - (x == r));
    print(x + (x == l), r);
  }
}

int main() {
  scanf("%d", &n);
  for (int i = 1; i <= n; i++) {
    int x, y;
    scanf("%d %d", &x, &y);
    a[i] = node{x - y, x + y};
  }
  discretize();
//  for (int i = 1; i <= n; i++) {
//    printf("#%d %d\n", a[i].l, a[i].r);
//  }
  for (int i = 1; i <= m; i++) {
    sort(vec[i].begin(), vec[i].end());
  }
  for (int i = 1; i < m; i++) {
    pos[i][i + 1] = i;
    f[i][i + 1] = (bool) vis[i][i + 1];
  }
  for (int i = 3; i <= m; i++) {
    for (int j = 1; i + j - 1 <= m; j++) {
      int l = j, r = i + j - 1, sz = (bool) vis[l][r];
      if (f[l + 1][r] < f[l][r - 1]) {
        f[l][r] = f[l][r - 1] + sz, pos[l][r] = r - 1;
      } else {
        f[l][r] = f[l + 1][r] + sz, pos[l][r] = l;
      }
      for (int k : vec[l]) {
        if (k >= r) break;
        int v = f[l][k] + f[k][r] + sz;
        if (f[l][r] < v) f[l][r] = v, pos[l][r] = k;
      }
    }
  }
//  for (int i = 1; i <= m; i++) {
//    for (int j = i; j <= m; j++) {
//      printf("(%d %d) %d %d\n", i, j, f[i][j], pos[i][j]);
//    }
//  }
  printf("%d\n", f[1][m]);
  print(1, m);
  return 0;
}
#include <bits/stdc++.h>
using namespace std;

const int maxn = 4e5 + 10;
int n, m, q, ans, par[maxn];

int find(int x) {
  return par[x] == x ? x : par[x] = find(par[x]);
}

void unite(int x, int y) {
  if ((x = find(x)) != (y = find(y))) {
    par[x] = y, ans++;
  }
}

int main() {
  scanf("%d %d %d", &n, &m, &q);
  for (int i = 1; i <= n + m; i++) {
    par[i] = i;
  }
  while (q--) {
    int x, y;
    scanf("%d %d", &x, &y);
    unite(x, n + y);
  }
  printf("%d", n + m - ans - 1);
  return 0;
}
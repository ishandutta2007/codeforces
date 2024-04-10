#include <bits/stdc++.h>
using namespace std;

const int N = 2e5 + 50;

int a[N];
int n, m, p, tab[105][55];

int main() {
  scanf("%d%d%d", &n, &m, &p);
  for (int i = 1; i <= n; i ++) scanf("%d", &a[i]);
  memset(tab, - 0x3f, sizeof tab);
  tab[0][0] = 0;
  int cur = 0;
  for (int i = 1; i <= n; i ++) {
    cur = (cur + a[i]) % p;
    for (int j = 1; j <= m; j ++) {
      int val = 0;
      for (int k = 0; k < p; k ++)
        val = max(val, tab[k][j - 1] + (cur + p - k) % p);
      tab[cur][j] = max(tab[cur][j], val);
    }
  }
  printf("%d\n", tab[cur][m]);
  return 0;
}
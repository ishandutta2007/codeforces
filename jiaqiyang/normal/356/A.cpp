#include <stdio.h>

const int N = 300000 + 10;

int anc[N];

int find(int x) { return anc[x] == x ? x : (anc[x] = find(anc[x])); }

int n, m;

int ans[N];

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n + 1; ++i) anc[i] = i;
  while (m--) {
    int l, r, x;
    scanf("%d%d%d", &l, &r, &x);
    for (int i = find(l); i < x; i = find(i + 1)) ans[i] = anc[i] = x;
    for (int i = find(x + 1); i <= r; i = find(i + 1)) ans[i] = x, anc[i] = find(r + 1);
  }
  for (int i = 1; i <= n; ++i) printf("%d ", ans[i]);
  return 0;
}
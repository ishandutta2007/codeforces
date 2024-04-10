#include <cstdio>
#include <cstring>
#include <numeric>
#include <algorithm>

const int N = 2000000 + 10;

int anc[N];

int find(int x) { return anc[x] == x ? x : (anc[x] = find(anc[x])); }

int len = 0;
char ans[N];

void modify(int p, int m, char t[]) {
  len = std::max(len, p + m);
  for (int i = p; i < p + m; i = find(i + 1)) ans[i] = t[i - p], anc[find(i)] = find(i + 1);
}

int main() {
  std::iota(anc, anc + N, 0);
  int tcase;
  for (scanf("%d", &tcase); tcase--;) {
    int k;
    static char t[N];
    scanf(" %s%d", t, &k);
    int m = strlen(t);
    while (k--) {
      int x;
      scanf("%d", &x);
      modify(x - 1, m, t);
    }
  }
  for (int i = 0; i < len; ++i) if (!ans[i]) ans[i] = 'a';
  puts(ans);
  return 0;
}
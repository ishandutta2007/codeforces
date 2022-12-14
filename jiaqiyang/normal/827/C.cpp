#include <cstdio>
#include <cstring>

const int N = 100000 + 10;

int n;
char s[N];

class {
  int sum[N];
  int query(int p) {
    int res = 0;
    for (; p; p ^= p & -p) res += sum[p];
    return res;
  }
 public:
  void add(int p, int v) {
    for (; p <= n; p += p & -p) sum[p] += v;
  }
  inline int query(int l, int r) { return query(r) - query(l - 1); }
} bit[4][10][10];

int dispatch(char c) {
  switch (c) {
    case 'A': return 0;
    case 'T': return 1;
    case 'G': return 2;
    case 'C': return 3;
  }
}

int init() {
  int q;
  scanf(" %s%d", s + 1, &q);
  n = strlen(s + 1);
  for (int i = 1; i <= n; ++i) {
    int c = dispatch(s[i]);
    for (int j = 0; j < 10; ++j) bit[c][j][i % (j + 1)].add(i, 1);
  }
  return q;
}

int main() {
  for (int tcase = init(); tcase--;) {
    int op;
    scanf("%d", &op);
    if (op == 1) {
      int x;
      char c;
      scanf("%d %c", &x, &c);
      int d = dispatch(s[x]);
      for (int i = 0; i < 10; ++i) bit[d][i][x % (i + 1)].add(x, -1);
      d = dispatch(s[x] = c);
      for (int i = 0; i < 10; ++i) bit[d][i][x % (i + 1)].add(x, 1);
    } else {
      int l, r, ans = 0;
      static char e[20];
      scanf("%d%d %s", &l, &r, e);
      int t = strlen(e);
      for (int i = 0; i < t; ++i) ans += bit[dispatch(e[i])][t - 1][(l + i) % t].query(l, r);
      printf("%d\n", ans);
    }
  }
  return 0;
}
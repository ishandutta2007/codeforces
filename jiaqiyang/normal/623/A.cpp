#include <cstdio>
#include <bitset>

const int N = 500 + 10;

int n, m;

int col[N], anc[N];

int find(int x) {
  if (anc[x] == x) {
    return x;
  } else {
    int y = find(anc[x]);
    col[x] ^= col[anc[x]];
    return anc[x] = y;
  }
}

inline bool meld(int x, int y, bool z) {
  int u = find(x), v = find(y);
  if (u == v) return z ^ (col[x] != col[y]);
  anc[u] = v;
  col[u] ^= (z ^ (col[x] == col[y]));
  return true;
}

std::bitset<N> flag[N];

int main() {
  scanf("%d%d", &n, &m);
  while (m--) {
    int a, b;
    scanf("%d%d", &a, &b);
    flag[a][b] = flag[b][a] = 1;
  }
  static char ans[N];
  for (int i = 1; i <= n; ++i) if (flag[i].count() == n - 1) ans[i] = 'b';
  for (int i = 1; i <= n; ++i) anc[i] = i;
  for (int i = 1; i <= n; ++i)
    if (ans[i] != 'b')
      for (int j = 1; j <= n; ++j)
        if (ans[j] != 'b' && i != j && !meld(i, j, flag[i][j])) return puts("No"), 0;
  puts("Yes");
  for (int i = 1; i <= n; ++i) if (!ans[i]) find(i), ans[i] = (col[i] == 0 ? 'a' : 'c');
  puts(ans + 1);
  return 0;
}
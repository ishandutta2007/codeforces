#include <cctype>
#include <stdio.h>
#include <bitset>
#include <vector>
#include <algorithm>

const int N = 500000 + 10, S = 26;

inline void check(int &lhs, int rhs) { if (rhs > lhs) lhs = rhs; }

int nextInt() {
  char ch;
  while (!isdigit(ch = getchar())) {}
  int res = ch - '0';
  while (isdigit(ch = getchar())) res = 10 * res + ch - '0';
  return res;
}

char nextChar() {
  char ch;
  while (!islower(ch = getchar())) {}
  return ch;
}

int n, p[N], c[N];

std::vector<int> adj[N];
std::bitset<(1 << S)> flag;

int dep[N], dist[N], size[N], son[N], left[N], right[N], dfn[N];

int pos[N][S + 1];

int ans[N], max[N];

void dfs(int a, bool flag) {
  static int tot = 0;
  dfn[left[a] = ++tot] = a;
  for (int i = 0; i < adj[a].size(); ++i) {
    int b = adj[a][i];
    if (b != son[a]) dfs(b, false), check(ans[a], ans[b]);
  }
  if (son[a]) dfs(son[a], true), check(ans[a], ans[son[a]]);
  right[a] = tot;
  for (int i = 0; i < adj[a].size(); ++i) {
    int b = adj[a][i];
    if (b == son[a]) continue;
    for (int j = left[b]; j <= right[b]; ++j) {
      int c = dfn[j], temp = dep[c] - 2 * dep[a];
      for (int k = 0; k <= S; ++k) check(ans[a], max[pos[c][k]] + temp);
    }
    for (int j = left[b]; j <= right[b]; ++j) check(max[pos[dfn[j]][S]], dep[dfn[j]]);
  }
  check(max[pos[a][S]], dep[a]);
  for (int k = 0; k <= S; ++k) if (max[pos[a][k]]) check(ans[a], max[pos[a][k]] - dep[a]);
  if (!flag) for (int i = left[a]; i <= right[a]; ++i) max[pos[dfn[i]][S]] = -N;
}

int main() {
  scanf("%d", &n);
  for (int i = 2; i <= n; ++i) adj[p[i] = nextInt()].push_back(i), c[i] = nextChar() - 'a';
  dep[1] = 1;
  for (int i = 2; i <= n; ++i) dist[i] = dist[p[i]] ^ (1 << c[i]), dep[i] = dep[p[i]] + 1;
  static int pool[N];
  for (int i = 1; i <= n; ++i) flag.set(pool[i] = dist[i]);
  std::sort(pool + 1, pool + n + 1);
  int m = std::unique(pool + 1, pool + n + 1) - pool - 1;
  for (int i = 0; i <= m; ++i) max[i] = -N;
  for (int i = 1; i <= n; ++i) size[i] = 1;
  for (int i = n; i > 1; --i) size[p[i]] += size[i];
  for (int i = 2; i <= n; ++i) if (size[i] > size[son[p[i]]]) son[p[i]] = i;
  for (int i = 1; i <= n; ++i) {
    for (int j = 0; j <= S; ++j) {
      int k = dist[i] ^ (j == S ? 0 : (1 << j));
      if (!flag[k]) continue;
      int p = std::lower_bound(pool + 1, pool + m + 1, k) - pool;
      pos[i][j] = (pool[p] == k ? p : 0);
    }
  }
  dfs(1, true);
  for (int i = 1; i <= n; ++i) printf("%d ", ans[i]);
  return 0;
}
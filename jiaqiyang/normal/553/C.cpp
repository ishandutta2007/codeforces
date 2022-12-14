#include <cstdio>
#include <cstdlib>
#include <vector>

const int N = 100000 + 10, MOD = 1000000007;

int n, m, a[N], b[N], c[N];

int anc[N];

int find(int x) { return anc[x] == x ? x : (anc[x] = find(anc[x])); }

int col[N];

std::vector<int> adj[N];

void dfs(int a) {
  for (int i = 0; i < adj[a].size(); ++i) {
    int b = adj[a][i];
    if (col[b] == -1) {
      col[b] = !col[a];
      dfs(b);
    } else if (col[b] == col[a]) {
      puts("0");
      exit(0);
    }
  }
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; ++i) scanf("%d%d%d", &a[i], &b[i], &c[i]);
  for (int i = 1; i <= n; ++i) anc[i] = i;
  for (int i = 1; i <= m; ++i) if (c[i]) anc[find(a[i])] = find(b[i]);
  for (int i = 1; i <= n; ++i) if (find(i) == i) col[i] = -1;
  for (int i = 1; i <= m; ++i) {
    if (c[i]) continue;
    int x = find(a[i]), y = find(b[i]);
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  int ans = (MOD + 1) / 2;
  for (int i = 1; i <= n; ++i) if (find(i) == i && col[i] == -1) dfs(i), ans = 2LL * ans % MOD;
  printf("%d\n", ans);
  return 0;
}
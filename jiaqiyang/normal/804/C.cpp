#include <cstdio>
#include <vector>

const int N = 300000 + 10;

int n, m, tot;
std::vector<int> s[N], adj[N];

int col[N];

void dfs(int a, int fa = 0) {
  static int tag[N], tot = 0;
  ++tot;
  for (auto x : s[a]) tag[col[x]] = tot;
  int i = 1;
  for (auto x : s[a]) {
    if (col[x]) continue;
    while (tag[i] == tot) ++i;
    tag[col[x] = i] = tot;
  }
  for (auto b : adj[a]) if (b != fa) dfs(b, a);
}

int main() {
  scanf("%d%d", &n, &m);
  tot = 1;
  for (int i = 1; i <= n; ++i) {
    int k;
    scanf("%d", &k);
    tot = std::max(tot, k);
    while (k--) {
      int x;
      scanf("%d", &x);
      s[i].push_back(x);
    }
  }
  for (int i = n - 1; i--;) {
    int a, b;
    scanf("%d%d", &a, &b);
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  dfs(1);
  printf("%d\n", tot);
  for (int i = 1; i <= m; ++i) printf("%d ", col[i] ? col[i] : 1);
  return 0;
}
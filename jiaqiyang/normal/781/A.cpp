#include <cstdio>
#include <vector>

const int N = 200000 + 10;

int n, m;
std::vector<int> adj[N];

int col[N];

void dfs(int a, int fa = 0) {
  static int tag[N], tot;
  tag[col[a]] = tag[col[fa]] = ++tot;
  int c = 1;
  for (auto b : adj[a]) {
    if (b == fa) continue;
    while (tag[c] == tot) ++c;
    tag[col[b] = c] = tot;
  }
  for (auto b : adj[a]) if (b != fa) dfs(b, a);
}

int main() {
  scanf("%d", &n);
  for (int i = n - 1; i--;) {
    int x, y;
    scanf("%d%d", &x, &y);
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  int m = 0;
  for (int i = 1; i <= n; ++i) m = std::max<int>(m, adj[i].size());
  ++m;
  col[1] = 1;
  dfs(1);
  printf("%d\n", m);
  for (int i = 1; i <= n; ++i) printf("%d ", col[i]);
  return 0;
}
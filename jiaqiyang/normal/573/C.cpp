#include <cstdio>
#include <vector>

const int N = 100000 + 10;

int n;
std::vector<int> adj[N];

bool flag[N];

void dfs(int a, int fa = -1) {
  if (adj[a].size() > 2) return;
  flag[a] = true;
  for (int i = 0; i < adj[a].size(); ++i) {
    int b = adj[a][i];
    if (b != fa) dfs(b, a);
  }
}

int main() {
  scanf("%d", &n);
  for (int i = n - 1; i--;) {
    int a, b;
    scanf("%d%d", &a, &b);
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  for (int i = 1; i <= n; ++i) if (adj[i].size() == 1) dfs(i);
  static int cnt[N];
  for (int i = 1; i <= n; ++i)
    for (int j = 0; j < adj[i].size(); ++j)
      cnt[i] += flag[adj[i][j]];
  for (int i = 1; i <= n; ++i) {
    if (flag[i]) continue;
    int cur = 0;
    for (int j = 0; j < adj[i].size(); ++j) {
      int t = adj[i][j];
      if (!flag[t] && adj[t].size() - std::min(cnt[t], 2) > 1) ++cur;
    }
    if (cur > 2) return puts("No"), 0;
  }
  puts("Yes");
  return 0;
}
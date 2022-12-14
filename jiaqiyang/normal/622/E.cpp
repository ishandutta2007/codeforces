#include <cstdio>
#include <vector>
#include <algorithm>

const int N = 500000 + 10;

int n;
std::vector<int> adj[N];

int dep[N];

std::vector<int> cur;

void dfs(int a, int fa = 1) {
  bool flag = false;
  for (int i = 0; i < adj[a].size(); ++i) {
    int b = adj[a][i];
    if (b != fa) dep[b] = dep[a] + 1, flag = true, dfs(b, a);
  }
  if (!flag) cur.push_back(dep[a]);
}

int solve(int s) {
  cur.clear();
  dfs(s);
  std::sort(cur.begin(), cur.end());
  for (int i = 1; i < cur.size(); ++i) cur[i] = std::max(cur[i - 1] + 1, cur[i]);
  return cur.back();
}

int main() {
  scanf("%d", &n);
  for (int i = n - 1; i--;) {
    int x, y;
    scanf("%d%d", &x, &y);
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  int ans = 0;
  for (int i = 0; i < adj[1].size(); ++i) ans = std::max(ans, solve(adj[1][i]) + 1);
  printf("%d\n", ans);
  return 0;
}
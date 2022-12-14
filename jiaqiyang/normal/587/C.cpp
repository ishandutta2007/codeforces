#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>

const int N = 100000 + 10, L = 20, S = 20 * N;

int n, m, q;
std::vector<int> adj[N];

int anc[L][N], dep[N];
std::vector<int> cur[L][N];

void dfs(int a) {
  for (int i = 0; i < adj[a].size(); ++i) {
    int b = adj[a][i];
    if (b != anc[0][a]) {
      anc[0][b] = a;
      dep[b] = dep[a] + 1;
      dfs(b);
    }
  }
}

void merge(std::vector<int> &lhs, const std::vector<int> &rhs) {
  std::vector<int> res;
  std::merge(lhs.begin(), lhs.end(), rhs.begin(), rhs.end(), std::back_inserter(res));
  res.erase(std::unique(res.begin(), res.end()), res.end());
  while (res.size() > 10) res.pop_back();
  lhs = res;
}

std::vector<int> query(int x, int y) {
  std::vector<int> res;
  if (dep[x] < dep[y]) std::swap(x, y);
  for (int i = L - 1; i >= 0; --i) if (dep[anc[i][x]] >= dep[y]) merge(res, cur[i][x]), x = anc[i][x];
  for (int i = L - 1; i >= 0; --i)
    if (anc[i][x] != anc[i][y]) merge(res, cur[i][x]), merge(res, cur[i][y]), x = anc[i][x], y = anc[i][y];
  merge(res, cur[0][x]);
  if (x != y) merge(res, cur[1][y]);
  return res;
}

int main() {
  std::cin >> n >> m >> q;
  for (int i = n - 1; i--;) {
    int a, b;
    scanf("%d%d", &a, &b);
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  for (int i = 1; i <= m; ++i) {
    int x;
    scanf("%d", &x);
    if (cur[0][x].size() < 10) cur[0][x].push_back(i);
  }
  dep[1] = 1;
  dfs(1);
  for (int i = 1; i < L; ++i)
    for (int j = 1; j <= n; ++j)
      anc[i][j] = anc[i - 1][anc[i - 1][j]], merge(cur[i][j] = cur[i - 1][j], cur[i - 1][anc[i - 1][j]]);
  while (q--) {
    int v, u, a;
    scanf("%d%d%d", &v, &u, &a);
    std::vector<int> ans = query(u, v);
    if (a < ans.size()) ans.resize(a);
    printf("%d", ans.size());
    for (int i = 0; i < ans.size(); ++i) printf(" %d", ans[i]);
    putchar('\n');
  }
  return 0;
}
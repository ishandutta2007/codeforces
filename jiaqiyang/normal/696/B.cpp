#include <cstdio>
#include <vector>

const int N = 100000 + 10;

int n, fa[N];

std::vector<int> adj[N];

int size[N];
double f[N];

void dfs(int a) {
  for (int i = 0; i < adj[a].size(); ++i) {
    int b = adj[a][i];
    f[b] = f[a] + (size[a] - size[b] - 1) / 2. + 1.;
    dfs(b);
  }
}

int main() {
  scanf("%d", &n);
  for (int i = 2; i <= n; ++i) scanf("%d", &fa[i]);
  for (int i = 1; i <= n; ++i) size[i] = 1;
  for (int i = n; i > 1; --i) size[fa[i]] += size[i];
  for (int i = 2; i <= n; ++i) adj[fa[i]].push_back(i);
  f[1] = 1.;
  dfs(1);
  for (int i = 1; i <= n; ++i) printf("%.3f ", f[i]);
  return 0;
}
#include <cstdio>
#include <vector>
#include <algorithm>

const int N = 200000 + 10;

int n, m;
std::vector<int> adj[N];

bool flag[N];

std::vector<int> res;

void dfs(int a) {
  flag[a] = true;
  res.push_back(a);
  for (auto b : adj[a]) {
    if (flag[b]) continue;
    flag[b] = true;
    dfs(b);
    res.push_back(a);
  }
}

void init() {
  int x;
  scanf("%d%d%d", &n, &x, &m);
  while (x--) {
    int a, b;
    scanf("%d%d", &a, &b);
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
}

int main() {
  init();
  dfs(1);
  int size = (2 * n + m - 1) / m;
  for (int i = 0; i < m; ++i) {
    int l = i * size, r = std::min<int>(l + size, res.size());
    if (l >= r) {
      puts("1 1");
      continue;
    }
    printf("%d", r - l);
    for (int j = l; j < r; ++j) printf(" %d", res[j]);
    putchar('\n');
  }
  return 0;
}
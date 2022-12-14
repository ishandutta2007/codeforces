#include <cstdio>
#include <vector>
#include <numeric>
#include <algorithm>

const int N = 1000 + 10;

int n;

std::vector<int> adj[N];

int anc[N], col[N];

int find(int x) {
  if (anc[x] == x) return x;
  int y = find(anc[x]);
  col[x] ^= col[anc[x]];
  return anc[x] = y;
}

bool meld(int x, int y) {
  int a = find(x), b = find(y);
  if (a == b) return col[x] != col[y];
  anc[a] = b;
  col[a] ^= (col[x] == col[y]);
  return true;
}

int bfs(int s) {
  static int q[N], tag[N], cnt = 0, dep[N];
  tag[q[1] = s] = ++cnt;
  dep[s] = 0;
  int res = 0;
  for (int f = 1, r = 1; f <= r; ++f) {
    int a = q[f];
    for (int i = 0; i < adj[a].size(); ++i) {
      int b = adj[a][i];
      if (tag[b] != cnt) tag[q[++r] = b] = cnt, res = std::max(res, dep[b] = dep[a] + 1);
    }
  }
  return res;
}

int main() {
  int m;
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) col[anc[i] = i] = 0;
  while (m--) {
    int x, y;
    scanf("%d%d", &x, &y);
    if (!meld(x, y)) return puts("-1"), 0;
    adj[x].push_back(y);
    adj[y].push_back(x);
  }
  static std::vector<int> block[N];
  for (int i = 1; i <= n; ++i) block[find(i)].push_back(i);
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    int cur = 0;
    for (int j = 0; j < block[i].size(); ++j) cur = std::max(cur, bfs(block[i][j]));
    ans += cur;
  }
  printf("%d\n", ans);
  return 0;
}
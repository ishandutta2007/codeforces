#include <cstdio>
#include <cstdlib>
#include <list>
#include <vector>
#include <algorithm>

const int N = 300000 + 10;

int n, m, k;

std::vector<int> adj[N];

inline void fail() {
  puts("impossible");
  exit(0);
}

std::list<int> cur;

void bfs() {
  static int q[N];
  q[1] = cur.front();
  cur.pop_front();
  for (int f = 1, r = 1; f <= r; ++f) {
    int a = q[f];
    int j = 0;
    for (std::list<int>::iterator it = cur.begin(); it != cur.end();) {
      while (j < adj[a].size() && adj[a][j] < *it) ++j;
      if (j == adj[a].size() || adj[a][j] > *it) {
        q[++r] = *it;
        cur.erase(it++);
      } else {
        ++it;
      }
    }
  }
}

int main() {
  scanf("%d%d%d", &n, &m, &k);
  for (int i = 1; i <= m; ++i) {
    int a, b;
    scanf("%d%d", &a, &b);
    adj[a].push_back(b);
    adj[b].push_back(a);
  }
  for (int i = 1; i <= n; ++i) std::sort(adj[i].begin(), adj[i].end());
  if (n - 1 - adj[1].size() < k) fail();
  for (int i = 1; i <= n; ++i) cur.push_back(i);
  bfs();
  if (!cur.empty()) fail();
  cur.clear();
  for (int i = 2; i <= n; ++i) cur.push_back(i);
  int cnt = 0;
  for (; !cur.empty(); ++cnt) bfs();
  if (cnt > k) fail();
  puts("possible");
  return 0;
}
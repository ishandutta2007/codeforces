#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

const int N = 200000 + 10, E = N * 10 + 10;

int n, l[N], r[N];

int adj[N];
int to[E], next[E], cnt = 2;

inline void Link(int a, int b) {
  to[cnt] = b;
  next[cnt] = adj[a];
  adj[a] = cnt++;
}

int ans[N], deg[N];

void DFS(int a, int pre = -1) {
  --deg[a];
  for (int it = adj[a]; it; it = next[it]) {
    if ((it ^ 1) == pre) continue;
    int b = to[it];
    if (ans[it / 2] == -1) {
      ans[it / 2] = (b > a);
      DFS(b, it);
    }
  }
}

int main() {
  scanf("%d", &n);
  static std::vector<int> sorted;
  for (int i = 1; i <= n; ++i) {
    scanf("%d%d", l + i, r + i);
    sorted.push_back(l[i]);
    sorted.push_back(++r[i]);
  }
  std::sort(sorted.begin(), sorted.end());
  sorted.erase(std::unique(sorted.begin(), sorted.end()), sorted.end());
  for (int i = 1; i <= n; ++i) {
    l[i] = std::lower_bound(sorted.begin(), sorted.end(), l[i]) - sorted.begin();
    r[i] = std::lower_bound(sorted.begin(), sorted.end(), r[i]) - sorted.begin();
    Link(l[i], r[i]);
    Link(r[i], l[i]);
    ++deg[l[i]], ++deg[r[i]];
  }
  for (int i = 0, j = -1; i < sorted.size(); ++i) {
    if (deg[i] & 1) {
      if (~j) {
        Link(j, i);
        Link(i, j);
        ++deg[i], ++deg[j];
        j = -1;
      } else {
        j = i;
      }
    }
  }
  memset(ans, -1, sizeof ans);
  for (int i = 0; i < sorted.size(); ++i) if (deg[i]) DFS(i);
  for (int i = 1; i <= n; ++i) printf("%d%c", ans[i], i == n ? '\n' : ' ');
  return 0;
}
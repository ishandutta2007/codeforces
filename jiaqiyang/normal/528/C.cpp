#include <cstdio>
#include <vector>

const int N = 500000 + 10;

int n, m, a[N], b[N];

int deg[N];

int adj[N], to[2 * N], next[2 * N];

void link(int a, int b) {
  static int cnt = 2;
  to[cnt] = b;
  next[cnt] = adj[a];
  adj[a] = cnt++;
}

bool flag[N];

std::vector<int> p, q;

void dfs(int a) {
  for (int &i = adj[a]; i; i = next[i]) {
    if (flag[i / 2]) continue;
    int b = to[i];
    flag[i / 2] = true;
    dfs(b);
    p.push_back(b);
    q.push_back(a);
  }
}

int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= m; ++i) {
    scanf("%d%d", &a[i], &b[i]);
    ++deg[a[i]], ++deg[b[i]];
    link(a[i], b[i]);
    link(b[i], a[i]);
  }
  int j = 0;
  for (int i = 1; i <= n; ++i) {
    if (deg[i] & 1) {
      if (!j) {
        j = i;
      } else {
        link(i, j);
        link(j, i);
        ++m;
        j = 0;
      }
    }
  }
  if (m & 1) link(1, 1), link(1, 1);
  dfs(1);
  printf("%d\n", p.size());
  for (int i = 0; i < p.size(); ++i) if (i & 1) printf("%d %d\n", p[i], q[i]); else printf("%d %d\n", q[i], p[i]);
  return 0;
}
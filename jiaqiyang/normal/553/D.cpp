#include <cstdio>
#include <set>
#include <queue>
#include <vector>
#include <algorithm>

typedef std::pair<double, int> Info;

const int N = 100000 + 10;

int n, m, a[N], b[N];
std::vector<int> adj[N];

bool flag[N];

int cur[N];

int main() {
  int k;
  scanf("%d%d%d", &n, &m, &k);
  while (k--) {
    int x;
    scanf("%d", &x);
    flag[x] = true;
  }
  for (int i = 1; i <= m; ++i) {
    int a, b;
    scanf("%d%d", &a, &b);
    adj[a].push_back(b);
    adj[b].push_back(a);
    if (!flag[a]) ++cur[b];
    if (!flag[b]) ++cur[a];
  }
  std::set<Info> pool;
  for (int i = 1; i <= n; ++i) if (!flag[i]) pool.insert(Info((double)cur[i] / adj[i].size(), i));
  static int tag[N];
  double best = 0.;
  int t = 0;
  while (!pool.empty()) {
    static int tot = 0;
    if (pool.begin()->first > best) {
      best = pool.begin()->first;
      t = tot;
    }
    int a = pool.begin()->second;
    tag[a] = ++tot;
    pool.erase(pool.begin());
    for (int i = 0; i < adj[a].size(); ++i) {
      int b = adj[a][i];
      if (flag[b] || tag[b]) continue;
      double t = (double)cur[b] / adj[b].size();
      pool.erase(Info(t, b));
      t = (double)--cur[b] / adj[b].size();
      pool.insert(Info(t, b));
    }
  }
  int cnt = 0;
  for (int i = 1; i <= n; ++i) if (tag[i] > t) ++cnt;
  printf("%d\n", cnt);
  for (int i = 1; i <= n; ++i) if (tag[i] > t) printf("%d ", i);
  return 0;
}
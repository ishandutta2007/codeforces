#include <cstdio>
#include <cstring>
#include <vector>
#include <algorithm>

const int N = 500 + 10;

int h, n;

std::vector<int> adj[N];

int ans;

void query(int x) {
  if (!adj[x].empty() || ans) return;
  printf("? %d\n", x);
  fflush(stdout);
  int k;
  scanf("%d", &k);
  if (k == 2) ans = x;
  adj[x].resize(k);
  for (int i = 0; i < k; ++i) scanf("%d", &adj[x][i]);
}

void print(int x) {
  printf("! %d\n", x);
  fflush(stdout);
}

int dist[N], tag[N], fa[N];
bool flag[N];

int solve1() {
  query(1);
  if (adj[1].size() == 1) return adj[1][0];
  static int q[N];
  q[1] = 1;
  int tot = 0;
  for (int i = 1, r = 1; i <= r; ++i) {
    int a = q[i];
    if (flag[tag[a]]) continue;
    query(a);
    for (int i = 0; i < adj[a].size(); ++i) {
      int b = adj[a][i];
      if (b == fa[a]) continue;
      fa[b] = a;
      dist[b] = dist[a] + 1;
      tag[b] = (a == 1 ? b : tag[a]);
      if (!flag[tag[b]]) {
        query(b);
        if (adj[b].size() == 1) flag[tag[b]] = true, ++tot;
        if (dist[b] < 3) q[++r] = b;
      }
    }
    if (tot == 2) break;
  }
  for (int i = 0; i < adj[1].size(); ++i) if (!flag[adj[1][i]]) return adj[1][i];
  return 0;
}

bool go(int x, int y, int z) {
  query(x);
  if (adj[x].size() == 1) return true;
  if (z == 0) return false;
  for (int i = 0; i < adj[x].size(); ++i) {
    int t = adj[x][i];
    if (t == y) continue;
    return go(t, x, z - 1);
  }
}

std::vector<int> pool;

void solve3(int x, int fa, int cnt = 2) {
  if (!cnt) {
    pool.push_back(x);
    return;
  }
  query(x);
  for (int i = 0; i < adj[x].size(); ++i) {
    int b = adj[x][i];
    if (b != fa) solve3(b, x, cnt - 1);
  }
}

int main() {
  int tcase;
  for (scanf("%d", &tcase); tcase--;) {
    scanf("%d", &h);
    n = 1 << h;
    ans = 0;
    for (int i = 1; i <= n; ++i) adj[i].clear();
    memset(dist, 0, sizeof dist);
    memset(fa, 0, sizeof fa);
    memset(flag, 0, sizeof flag);
    memset(tag, 0, sizeof tag);
    int fa1 = solve1();
    if (ans) {
      print(ans);
      continue;
    }
    int mx = 0;
    for (int i = 1; i <= n; ++i) if (flag[tag[i]]) mx = std::max(mx, dist[i]);
    int dep = h - mx;
    int cur = 1, ban = 1;
    if (dep > 3) {
      cur = fa1;
      while (--dep > 3) {
        query(cur);
        std::vector<int> temp = adj[cur];
        temp.erase(std::find(temp.begin(), temp.end(), ban));
        int t = temp[0];
        if (go(t, cur, h - dep - 1)) t = temp[1];
        ban = cur;
        cur = t;
      }
    }
    pool.clear();
    solve3(cur, ban);
    for (int i = 1; i < pool.size(); ++i) query(pool[i]);
    if (!ans) ans = pool[0];
    print(ans);
  }
  return 0;
}
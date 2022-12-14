#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <vector>

typedef long long i64;

const int N = 200000 + 10, MOD = 1000000007;

inline int sgn(int x) { return x > 0 ? 1 : -1; }

int n, m;
std::vector<int> adj[N];

int tag[N], tot;
int e[N];

int res[2];

int q[N], r;

void dfs(int a) {
  tag[q[++r] = a] = tot;
  for (int i = 0; i < adj[a].size(); ++i) {
    int b = abs(adj[a][i]), c = sgn(adj[a][i]);
    if (!tag[b]) e[b] = c * a, dfs(b);
  }
}

void solve(int s) {
  ++tot;
  r = 0;
  dfs(s);
  if (adj[s].size() > 1) {
    for (int i = 0; i < adj[s].size(); ++i) {
      int b = abs(adj[s][i]), c = sgn(adj[s][i]);
      if (b == q[r] && c * s != e[b]) {
        e[q[++r] = s] = sgn(adj[s][i]);
        break;
      }
    }
  }
  static int f[N][2][2][2];
  int u = 1, v = r;
  if (q[u] <= n) ++u;
  if (q[v] <= n) --v;
  memset(f[u], 0, sizeof f[u]);
  f[u][0][0][0] = f[u][1][1][0] = 1;
  for (int i = u; i < v; i += 2) {
    memset(f[i + 2], 0, sizeof f[i + 2]);
    for (int a = 0; a < 2; ++a) {
      for (int b = 0; b < 2; ++b) {
        for (int c = 0; c < 2; ++c) {
          int cur = f[i][a][b][c];
          if (!cur) continue;
          for (int t = 0; t < 2; ++t) {
            int x = (e[q[i + 1]] < 0) ^ b, y = (e[q[i + 2]] < 0) ^ t;
            (f[i + 2][a][t][c ^ (x | y)] += cur) %= MOD;
          }
        }
      }
    }
  }
  res[0] = res[1] = 0;
  for (int a = 0; a < 2; ++a)
    for (int b = 0; b < 2; ++b)
      for (int c = 0; c < 2; ++c)
        if (!(v > u && q[r] == s && a != b))
          (res[c ^ (u == 1 ? 0 : (a ^ (e[q[u]] < 0))) ^ (v == r ? 0 : (b ^ (e[q[r]] < 0)))] += f[v][a][b][c]) %= MOD;
}


int main() {
  scanf("%d%d", &n, &m);
  for (int i = 1; i <= n; ++i) {
    int k;
    for (scanf("%d", &k); k--;) {
      int j;
      scanf("%d", &j);
      int sig = sgn(j);
      j = abs(j);
      adj[i].push_back(sig * (j + n));
      adj[j + n].push_back(sig * (i));
    }
  }
  int ans[2] = {1, 0};
  for (int i = 1; i <= n + m; ++i) {
    if (adj[i].size() == 1 && !tag[i]) {
      solve(i);
      int temp[2];
      temp[0] = ((i64)ans[0] * res[0] + (i64)ans[1] * res[1]) % MOD;
      temp[1] = ((i64)ans[1] * res[0] + (i64)ans[0] * res[1]) % MOD;
      ans[0] = temp[0], ans[1] = temp[1];
    }
  }
  for (int i = n + 1; i <= n + m; ++i) {
    if (tag[i]) continue;
    solve(i);
    int temp[2];
    temp[0] = ((i64)ans[0] * res[0] + (i64)ans[1] * res[1]) % MOD;
    temp[1] = ((i64)ans[1] * res[0] + (i64)ans[0] * res[1]) % MOD;
    ans[0] = temp[0], ans[1] = temp[1];
  }
  printf("%d\n", ans[1]);
  return 0;
}
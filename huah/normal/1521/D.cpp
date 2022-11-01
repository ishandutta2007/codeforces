#include <bits/stdc++.h>

#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <exception>
#include <map>
#include <memory>
#include <ostream>
#include <queue>
#define inf 0x3f3f3f3f
using namespace std;
typedef long long ll;
#define mp(x, y) make_pair(x, y)
const int N = 1e5 + 5, bs = 320, mod = 1e9 + 7;
int n;
vector<int> e[N];
vector<vector<int> > dp[N], pre1[N], pre2[N];
vector<int> nd[N];
void dfs(int u, int p) {
  dp[u].clear();
  pre1[u].clear();
  pre2[u].clear();
  nd[u].clear();
  vector<int> g, op1, op2;
  g.push_back(0);
  g.push_back(0);
  g.push_back(0);
  op1.push_back(0);
  op1.push_back(0);
  op1.push_back(0);
  op2.push_back(0);
  op2.push_back(0);
  op2.push_back(0);
  dp[u].push_back(g);
  pre1[u].push_back(op1);
  pre2[u].push_back(op2);
  nd[u].push_back(0);
  for (int s = 0; s < e[u].size(); s++) {
    int v = e[u][s];
    if (v == p) continue;
    dfs(v, u);
    g[0] = g[1] = g[2] = inf;
    for (int i = 0; i < 3; i++)
      for (int j = 0; j < 3; j++) {
        if (i < 2&& j < 2&& dp[u].back()[i] + dp[v].back()[j] < g[i + 1]) {
          g[i + 1] = dp[u].back()[i] + dp[v].back()[j];
          op1[i + 1] = i;
          op2[i + 1] = j;
        }
        if (dp[u].back()[i] + dp[v].back()[j] + 1 < g[i]) {
          g[i] = dp[u].back()[i] + dp[v].back()[j] + 1;
          op1[i] = i;
          op2[i] = j;
        }
      }
    dp[u].push_back(g);
    pre1[u].push_back(op1);
    pre2[u].push_back(op2);
    nd[u].push_back(v);
  }
}
vector<pair<int, int> > cuts;
vector<pair<int, int> > links;
int son[N][2];
bool cut[N];
void getans(int u, int p, int z) {
  for (int i = dp[u].size() - 1; i > 0; i--) {
    getans(nd[u][i], u, pre2[u][i][z]);
    if (pre1[u][i][z] == z)
      cuts.push_back(mp(u, nd[u][i])), cut[nd[u][i]] = true;
    else {
      if (!son[u][0])
        son[u][0] = nd[u][i];
      else
        son[u][1] = nd[u][i];
    }
    z = pre1[u][i][z];
  }
}
vector<pair<int, int> > qaq;
void cal(int u, int p) {
  if (cut[u]) {
    int x = son[u][0], y = son[u][1];
    while (son[x][0]) x=son[x][0];
    while (son[y][0]) y=son[y][0];
    if(x==0) x=u;
    if(y==0) y=u;
    qaq.push_back(mp(x, y));
  }
  for (int i = 0; i < e[u].size(); i++) {
    int v = e[u][i];
    if (v == p) continue;
    cal(v, u);
  }
}
int main() {
  srand(time(0));
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d", &n);
    qaq.clear();
    links.clear();
    cuts.clear();
    for (int i = 1; i <= n; i++)
      cut[i] = false, e[i].clear(), son[i][0] = son[i][1] = 0;
    for (int i = 1; i < n; i++) {
      int u, v;
      scanf("%d%d", &u, &v);
      e[u].push_back(v);
      e[v].push_back(u);
    }
    dfs(1, 0);
    int ans = inf, z;
    for (int i = 0; i < 3; i++)
      if (dp[1].back()[i] < ans) ans = dp[1].back()[i], z = i;
    printf("%d\n", ans);
    getans(1, 0, z);
    cut[1] = true;
    cal(1, 0);
    assert(qaq.size() == cuts.size() + 1);
    for (int i = 0; i + 1 < qaq.size(); i++)
      links.push_back(mp(qaq[i].second, qaq[i + 1].first));
    assert(cuts.size() == ans);
    for (int i = 0; i < ans; i++)
      printf("%d %d %d %d\n", cuts[i].first, cuts[i].second, links[i].first,
             links[i].second);
  }
}
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cctype>

#include <algorithm>
#include <random>
#include <bitset>
#include <queue>
#include <functional>
#include <set>
#include <map>
#include <vector>
#include <chrono>
#include <iostream>
#include <limits>
#include <numeric>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

// mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 200010;

int n;
vector<int> g0[N], g1[N];
bool vis[N];
int dp01[N], dp11[N], dp02[N], dp12[N];

void dfs(int u) {
  vis[u] = true;
  dp01[u] = 1;
  dp11[u] = 1;
  for (int v : g0[u])
    if (!vis[v]) {
      dfs(v);
      dp11[u] += dp11[v];
    }
  for (int v : g1[u])
    if (!vis[v]) {
      dfs(v);
      dp01[u] += dp01[v];
      dp11[u] += dp01[v];
    }
}

void dfs2(int u) {
  vis[u] = true;
  for (int v : g0[u])
    if (!vis[v]) {
      dp12[v] = dp12[u] + dp11[u] - dp11[v];
      dfs2(v);
    }
  for (int v : g1[u])
    if (!vis[v]) {
      dp02[v] = dp12[v] = dp02[u] + dp01[u] - dp01[v];
      dfs2(v);
    }
}

int main() {
#ifdef LBT
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif

  scanf("%d", &n);
  for (int rep = 1; rep < n; ++rep) {
    int u, v, x;
    scanf("%d%d%d", &u, &v, &x);
    if (x == 0) {
      g0[u].push_back(v);
      g0[v].push_back(u);
    } else {
      g1[u].push_back(v);
      g1[v].push_back(u);
    }
  }
  dfs(1);
  memset(vis, 0, sizeof(vis));
  dfs2(1);
  ll ans = 0;
  for (int i = 1; i <= n; ++i) {
    ans += dp11[i] + dp12[i] - 1;
  }
  printf("%lld\n", ans);

#ifdef LBT
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}
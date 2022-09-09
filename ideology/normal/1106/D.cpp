#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <cctype>

#include <algorithm>
#include <functional>
#include <set>
#include <map>
#include <vector>
#include <queue>
#include <iostream>
#include <limits>
#include <numeric>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int N = 100010;

int n;
int ans[N];
bool vis[N];
vector<int> adj[N];

int main() {
#ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif

  int m;
  scanf("%d%d", &n, &m);
  while (m--) {
    int u, v;
    scanf("%d%d", &u, &v);
    adj[u].push_back(v);
    adj[v].push_back(u);
  }
  priority_queue<int, vector<int>, greater<int>> q;
  q.push(1);
  int cnt = 0;
  while (!q.empty()) {
    int u = q.top();
    q.pop();
    if (vis[u])
      continue;
    vis[u] = true;
    ans[++cnt] = u;
    for (int v : adj[u])
      q.push(v);
  }
  for (int i = 1; i <= n; ++i)
    printf("%d ", ans[i]);

#ifndef ONLINE_JUDGE
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}
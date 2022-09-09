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
#include <queue>
#include <vector>
#include <iostream>
#include <limits>
#include <numeric>

#define LOG(FMT...) // fprintf(stderr, FMT)

using namespace std;

typedef long long ll;
typedef unsigned long long ull;

const int N = 100010, M = 210;

int n, m, k, cnt;
pair<int, pair<int, pair<int, int>>> seg[N * 2];
ll dp[N][M];

map<int, int> key;
map<int, pair<int, pair<int, int>>> help;
priority_queue<pair<int, pair<int, int>>> q, dq;

int dfs(int t) {
  LOG("DFS %d\n", t);
  map<int, pair<int, pair<int, int>>>::iterator it = help.lower_bound(t);
  if (it == help.end()) {
    LOG("ANS0 %d\n", t);
    return 0;
  }
  t = it->first;
  int v;
  if ((v = key[t]) != 0)
    return v;
  v = key[t] = ++cnt;
  int dd = it->second.second.first, tt = it->second.second.second, ww = it->second.first;
  int di = dfs(dd + 1);
  LOG("%d->%d %d\n", t, dd + 1, di);
  memcpy(dp[v], dp[di], sizeof(dp[v]));
  for (int i = 0; i <= m; ++i)
    dp[v][i] += ww;
  int nxt = dfs(t + 1);
  for (int i = 1; i <= m; ++i)
    dp[v][i] = min(dp[v][i], dp[nxt][i - 1]);
  return v;
}

int main() {
#ifndef ONLINE_JUDGE
  freopen("test.in", "r", stdin);
  int nol_cl = clock();
#endif

  scanf("%d%d%d", &n, &m, &k);
  int cc = 0;
  while (k--) {
    int s, t, d, w;
    scanf("%d%d%d%d", &s, &t, &d, &w);
    seg[++cc] = make_pair(s, make_pair(w, make_pair(d, t)));
    seg[++cc] = make_pair(t + 1, make_pair(-w, make_pair(d, t)));
  }
  for (int i = 1; i <= n + 1; ++i)
    key[i] = 0;
  int ptr = 1;
  sort(seg + 1, seg + cc + 1);
  for (const auto& pr : key) {
    int pos = pr.first;
    while (ptr <= cc && seg[ptr].first <= pos) {
      if (seg[ptr].second.first > 0)
        q.push(seg[ptr].second);
      else
        dq.push(make_pair(seg[ptr].second.first * -1, seg[ptr].second.second));
      ++ptr;
    }
    while (!q.empty() && !dq.empty() && q.top() == dq.top()) {
      q.pop();
      dq.pop();
    }
    LOG("%d %d\n", pos, q.empty());
    if (!q.empty())
      help[pos] = q.top();
  }
  int x = dfs(1);
  printf("%lld\n", dp[x][m]);

#ifndef ONLINE_JUDGE
  LOG("Time: %dms\n", int ((clock()
          -nol_cl) / (double)CLOCKS_PER_SEC * 1000));
#endif
  return 0;
}
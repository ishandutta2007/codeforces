#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for (int i = (a), i##end = (b); i <= i##end; ++i)
#define per(i, a, b) for (int i = (a), i##end = (b); i >= i##end; --i)

mt19937 rnd(chrono::high_resolution_clock::now().time_since_epoch().count());

typedef pair <int, int> pii;
int n, a[5], deg[5], par[5];
vector <pii> E[5];

struct edge {
  int u, v, w;
} e[110];

int find(int x) {
  return par[x] == x ? x : par[x] = find(par[x]);
}

int main() {
  int sum = 0;
  scanf("%d", &n);
  rep(i, 1, 4) par[i] = i;
  rep(i, 1, n) {
    int u, v, w;
    scanf("%d %d %d", &u, &w, &v);
    e[i] = {u, v, w};
    sum += w;
    if (u == v) {
      a[u] += w;
    } else {
      E[u].push_back(pii(v, w)), deg[u]++;
      E[v].push_back(pii(u, w)), deg[v]++;
      par[find(u)] = find(v);
    }
  }
  int now = 0, val[5];
  memset(val, 0, sizeof val);
  rep(i, 1, 4) {
    rep(j, i, 4) {
      if (find(j) == find(i)) {
        rep(k, 1, n) {
          int x = e[k].u, y = e[k].v;
          if ((x == i && y == j) || (x == j && y == i)) {
            val[find(i)] += e[k].w;
          }
        }
      }
    }
  }
  rep(i, 1, 4) {
    now = max(now, val[i]);
  }
  int tot = 0;
  bool flg = 1;
  rep(i, 1, 4) {
    flg &= deg[i] & 1;
    tot += find(i) == i;
  }
  if (!flg || tot > 1) {
    return printf("%d", now), 0;
  }
  int ans = 0;
  int mn = 1 << 30;
  rep(i, 1, 4) {
    if ((int) E[i].size() == 1) {
      ans = max(ans, sum - a[i] - E[i][0].second);
      continue;
    }
    for (pii p : E[i]) {
      if ((int) E[p.first].size() != 1){
        mn = min(mn, p.second);
      } 
    }
  }
  rep(i, 1, 4) {
    if ((int) E[i].size() != 1) {
      ans = max(ans, sum - mn);
    }
  }
  printf("%d", max(ans, sum - ans));
  return 0;
}
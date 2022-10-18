#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <cstdio>
#include <queue>


using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

const int MAXN = 100010;
const int MAXQ = 55;

const llint inf = 1e18;

struct Edge {
  int y, w;
};

vector<Edge> E[MAXN];
llint l[MAXQ];
llint bestup[MAXN];
llint best[MAXN];

llint dfs(int x, int dad) {
  // vrati distance do najdubljeg leafa
  llint best1 = -inf, best2 = -inf;
  int id1 = -1;
  for (Edge &e: E[x]) 
    if (e.y != dad) {
      llint d = dfs(e.y, x) + e.w;
      if (d >= best1) {
        best2 = best1;
        best1 = d, id1 = e.y;
      } else
        if (d >= best2) {
          best2 = d;
        }
    }
  

  if (id1 == -1) {
    // leaf
    return best[x] = 0;
  }

  for (Edge &e: E[x])
    if (e.y != dad) {
      if (e.y != id1) bestup[e.y] = max(bestup[e.y], best1 + e.w); else
        bestup[e.y] = max(bestup[e.y], best2 + e.w);
    }

  return best[x] = best1;
}

void dfs2(int x, int dad) {
  best[x] = max(best[x], bestup[x]);
  for (Edge &e: E[x])
    if (e.y != dad) {
      bestup[e.y] = max(bestup[e.y], bestup[x] + e.w);
      dfs2(e.y, x);
    }
}

int dad[MAXN];
int cnt[MAXN];

int findset(int x) {
  return x == dad[x] ? x : dad[x] = findset(dad[x]);
}

void merge(int x, int y) {
  x = findset(x), y = findset(y);
  if (x == y) return;
  dad[y] = x, cnt[x] += cnt[y];
}

int main(void) {
  int n;
  scanf("%d", &n);
  REP(i, n-1) {
    int a, b, w;
    scanf("%d %d %d", &a, &b, &w);
    --a, --b;
    E[a].push_back({b, w});
    E[b].push_back({a, w});
  }

  if (n == 2) {
    best[0] = best[1] = E[0][0].w;
  } else {
    int root = -1;
    REP(i, n)
      if (E[i].size() != 1) root = i;
    
    assert(root != -1);
    
    dfs(root, -1);
    dfs2(root, -1);
  }
  
  vector<pair<llint, int>> v;
  REP(i, n) v.push_back({best[i], i});
  
  sort(v.begin(), v.end());

  int q;
  scanf("%d", &q);  
  REP(qi, q) {
    llint L;
    scanf("%lld", &L);
    
    REP(i, n) dad[i] = -1;

    int ans = 0;
    int ptr = n-1;
    for (int i = n-1; i >= 0; --i) {
      int x = v[i].second;
      dad[x] = x;
      cnt[x] = 1;

      while (ptr >= i && v[ptr].first > best[x] + L) 
        cnt[ findset(v[ptr--].second) ]--;
      
      for (Edge &e: E[x])
        if (dad[e.y] != -1) merge(x, e.y);

      ans = max(ans, cnt[findset(x)]);
    }

    printf("%d\n", ans);
  }

  return 0;
}
#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <cstdio>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

const int MAX = 2020;
const llint inf = 1e18;

struct Edge {
  int b, w;
};

vector<Edge> E[MAX];
vector<int> H[2][MAX];

bool alive[MAX];
int a[MAX];
llint d[2][MAX];
llint c[2][MAX][MAX];
int cnt[2][MAX][MAX];

llint f[MAX][MAX][2][2];
int n, m;

void dijkstra(llint d[MAX], int s) {
  static bool bio[MAX];
  REP(i, n) d[i] = inf, bio[i] = false;
  d[s] = 0;
  REP(i, n) {
    int x = -1;
    REP(j, n)
      if (!bio[j])
        if (x == -1 || d[j] < d[x]) x = j;
    assert(x != -1);

    bio[x] = true;
    for (Edge &e: E[x])
      d[e.b] = min(d[e.b], d[x] + e.w);
  }
}

int main(void) {
  scanf("%d %d", &n, &m);
  int s, t;
  scanf("%d %d", &s, &t); --s, --t;
  REP(i, n) scanf("%d", a+i);
  REP(i, m) {
    int u, v, w;
    scanf("%d %d %d", &u, &v, &w); --u, --v;
    E[u].push_back({v, w});
    E[v].push_back({u, w});
  }
  
  dijkstra(d[0], s);
  dijkstra(d[1], t);

  vector<llint> V[2];
  REP(i, 2) {
    REP(j, n) V[i].push_back(d[i][j]);
    V[i].push_back(-1);
    
    sort(V[i].begin(), V[i].end());
    V[i].erase(unique(V[i].begin(), V[i].end()), V[i].end());
    
    REP(j, (int)V[i].size()) REP(k, n)
      if (d[i][k] == V[i][j]) H[i][j].push_back(k);
  }

  REP(i, 2) {
    REP(j, (int)V[i].size()) {
      llint sum = 0;
      int cn = 0;
      for (int x: H[i][j]) sum += a[x], cn++;
      
      REP(k, (int)V[i^1].size()) {
        for (int x: H[i^1][k])
          if (d[i][x] == V[i][j]) sum -= a[x], cn--;
        c[i][j][k] = sum;
        cnt[i][j][k] = cn;
      }
    }
  }

  for (int d0 = (int)V[0].size()-1; d0 >= 0; --d0)
    for (int d1 = (int)V[1].size()-1; d1 >= 0; --d1) {
      REP(a, 2) REP(b, 2) f[d0][d1][a][b] = -inf;

      bool can0 = d0+1 < (int)V[0].size();
      bool can1 = d1+1 < (int)V[1].size();
      if (!can0 && !can1) {
        REP(a, 2) REP(b, 2) f[d0][d1][a][b] = 0;
        continue;
      }

      if (can0) {
        REP(b, 2) {
          bool ima = b || (cnt[0][d0+1][d1] > 0);
          f[d0][d1][0][b] = c[0][d0+1][d1] + f[d0+1][d1][0][ima];
          if (ima) f[d0][d1][0][b] = max(f[d0][d1][0][b], c[0][d0+1][d1] - f[d0+1][d1][1][0]);
        }
      }

      if (can1) {
        REP(b, 2) {
          bool ima = b || (cnt[1][d1+1][d0] > 0);
          f[d0][d1][1][b] = c[1][d1+1][d0] + f[d0][d1+1][1][ima];
          if (ima) f[d0][d1][1][b] = max(f[d0][d1][1][b], c[1][d1+1][d0] - f[d0][d1+1][0][0]);
        }
      }

      if (!can0) {
        REP(b, 2)
          f[d0][d1][0][b] = f[d0][d1][1][0];
      }

      if (!can1) {
        REP(b, 2)
          f[d0][d1][1][b] = f[d0][d1][0][0];
      }
    }

  llint score = f[0][0][0][0];
  if (score > 0) puts("Break a heart");
  if (score == 0) puts("Flowers");
  if (score < 0) puts("Cry");
  return 0;
}
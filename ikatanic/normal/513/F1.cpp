#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <queue>
#include <cstdio>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

namespace maxflow {
  typedef pair<int, int> edge;
#define b first
#define d second

  const int MAXN = 5050;
  const int inf = 2e9;
  
  vector<edge> E[MAXN];
  vector<int> cap[MAXN];
  int dist[MAXN];
  int bio[MAXN];
  int cur[MAXN];
  int cookie, s, t;
  int N;

  queue<int> Q;

  bool bfs() {
    while (!Q.empty()) Q.pop();
    
    REP(i, N) dist[i] = -1;
    dist[s] = 0;
    Q.push(s);
    while (!Q.empty()) {
      int x = Q.front(); Q.pop();
      if (x == t) return true;

      REP(i, (int)E[x].size()) {
        int y = E[x][i].b;
        if (dist[y] == -1 && cap[x][i] != 0) {
          dist[y] = dist[x]+1;
          Q.push(y);
        }
      }
    }
    return false;
  }
  
  int augment(int x, int c) {
    if (x == t) return c;
    
    for (int &i = cur[x]; i < (int)E[x].size(); ++i) {
      int y = E[x][i].b;
      if (cap[x][i] > 0 && dist[y] == dist[x]+1) {
        int v = augment(y, min(c, cap[x][i]));
        if (v > 0) { 
          cap[x][i] -= v;
          cap[y][E[x][i].d] += v;
          return v;
        }
      }
    }
    return 0;
  }
  
  
  void add_edge(int a, int b, int cab, int cba) {
    E[a].push_back(edge(b, E[b].size()));
    E[b].push_back(edge(a, E[a].size()-1));
    cap[a].push_back(cab);
    cap[b].push_back(cba);
  }
  
  llint solve(int S, int T) {
    s = S, t = T;
    llint ans = 0;
    while (bfs()) {
      int f;
      REP(i, N) cur[i] = 0;
      while ((f = augment(s, inf))) ans += f;
    }
    return ans;
  }

  void init(int n) {
    N = n;
    REP(i, n) E[i].clear(), cap[i].clear();
  }
};


const int MAXN = 30;
const int MAXM = 1000;
const int inf = 1e9;

int d[MAXN][MAXN][MAXN][MAXN];
char a[MAXN][MAXN];

int mx[MAXM], my[MAXM], mt[MAXM];
int fx[MAXM], fy[MAXM], ft[MAXM];

int dx[] = {+1, 0, -1, 0};
int dy[] = {0, +1, 0, -1};

int main(void) {
  int r, c, m, f;
  scanf("%d %d %d %d", &r, &c, &m, &f);
  REP(i, r) scanf("%s", a[i]);

  REP(ir, r) REP(ic, c) REP(jr, r) REP(jc, c)
    d[ir][ic][jr][jc] = inf;

  REP(i, r) REP(j, c) {
    if (a[i][j] == '#') continue;
    
    d[i][j][i][j] = 0;
    
    REP(k, 4) {
      int ni = i + dx[k], nj = j + dy[k];
      if (0 <= ni && ni < r)
        if (0 <= nj && nj < c)
          if (a[ni][nj] != '#')
            d[i][j][ni][nj] = 1;
    }
  }

  REP(kr, r) REP(kc, c) REP(ir, r) REP(ic, c) REP(jr, r) REP(jc, c)
    d[ir][ic][jr][jc] = min(d[ir][ic][jr][jc], d[ir][ic][kr][kc] + d[kr][kc][jr][jc]);

  int bx, by, bt;
  scanf("%d %d %d", &bx, &by, &bt); --bx, --by;
  REP(i, m) {
    scanf("%d %d %d", mx+i, my+i, mt+i);
    --mx[i], --my[i];
  }
  REP(i, f) {
    scanf("%d %d %d", fx+i, fy+i, ft+i);
    --fx[i], --fy[i];
  }

  if (m+1 == f) {
    mx[m] = bx, my[m] = by, mt[m] = bt;
    m++;
  } else
    if (f+1 == m) {
      fx[f] = bx, fy[f] = by, ft[f] = bt;
      f++;
    } else {
      puts("-1");
      return 0;
    }

  assert(f == m);
  
  auto can = [&] (llint T) {
    int inStart = 0;
    int outStart = inStart + r*c;
    int mStart = outStart + r*c;
    int fStart = mStart + m;
    
    int source = fStart + f;
    int sink = source + 1;
    maxflow::init(sink + 1);
    
    REP(i, r) REP(j, c) {
      if (a[i][j] == '#') continue;
      maxflow::add_edge(inStart + i*c + j, outStart + i*c + j, 1, 0);
    }
    
    REP(i, m) {
      maxflow::add_edge(source, mStart + i, 1, 0);
      REP(x, r) REP(y, c) {
        if (d[mx[i]][my[i]][x][y] >= inf) continue;
        llint cost = d[mx[i]][my[i]][x][y] * llint(mt[i]);
        if (cost <= T) maxflow::add_edge(mStart + i, inStart + x*c + y, 1, 0);
      }
    }

    REP(j, f) {
      maxflow::add_edge(fStart + j, sink, 1, 0);
      REP(x, r) REP(y, c) {
        if (d[fx[j]][fy[j]][x][y] >= inf) continue;
        llint cost = d[fx[j]][fy[j]][x][y] * llint(ft[j]);
        if (cost <= T) maxflow::add_edge(outStart + x*c + y, fStart + j, 1, 0);
      }
    }

    return maxflow::solve(source, sink) == m;
  };

  llint lo = 0, hi = 1e13;
  while (lo < hi) {
    llint mid = (lo + hi) / 2;
    if (can(mid)) hi = mid; else
      lo = mid+1;
  }

  if (!can(lo)) lo = -1;
  printf("%lld\n", lo);
  return 0;
}
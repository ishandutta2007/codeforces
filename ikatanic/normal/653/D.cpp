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

namespace maxflow {
  typedef pair<int, int> edge;
#define b first
#define d second

  const int MAXN = 555;
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
        if (dist[y] == -1 && cap[x][i] > 0) {
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

const int MAX = 555;

int a[MAX], b[MAX], c[MAX];

int main(void) {
  int n, m, x;
  scanf("%d %d %d", &n, &m, &x);
  REP(i, m) {
    scanf("%d %d %d", a+i, b+i, c+i);
    --a[i], --b[i];
  }

  double lo = 0, hi = 1e7;
  REP(it, 100) {
    double mid = (lo + hi) / 2;
    maxflow::init(n);
    REP(i, m) {
      llint cap = min((llint)x, (llint)(mid * c[i]));
      maxflow::add_edge(a[i], b[i], cap, 0);
    }
    if (maxflow::solve(0, n-1) < x) lo = mid;
    else hi = mid;
  }
  
  printf("%.10lf\n", x/lo);
  return 0;
}
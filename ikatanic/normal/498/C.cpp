#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <queue>
#include <map>
#include <set>

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

  const int MAXN = 110;
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

const int MAXN = 110;

bool e[MAXN][MAXN];
map<int, int> M[MAXN];
set<int> S;

int main(void) {
  int n, m;
  scanf("%d %d", &n, &m);
  REP(i, n) {
    int x;
    scanf("%d", &x);
    for (int j = 2; j*j <= x; ++j)
      if (x%j == 0) {
        int cnt = 0;
        while (x%j == 0) cnt++, x /= j;
        M[i][j] = cnt;
        S.insert(j);
      }
    
    if (x > 1) M[i][x] = 1, S.insert(x);
  }
  
  REP(i, m) {
    int a, b;
    scanf("%d %d", &a, &b); --a, --b;
    e[a][b] = e[b][a] = true;
  }

  int ans = 0;
  for (int p: S) {
    vector<int> v;

    maxflow::init(n + 2);
    int source = n, sink = n + 1;
    
    REP(i, n)
      if (M[i].count(p)) {
        if (i&1) maxflow::add_edge(source, i, M[i][p], 0); else
          maxflow::add_edge(i, sink, M[i][p], 0);
      }
    
    REP(i, n) REP(j, n)
      if (e[i][j])
        if (i&1) maxflow::add_edge(i, j, maxflow::inf, 0);

    ans += maxflow::solve(source, sink);
  }
  
  printf("%d\n", ans);
  return 0;
}
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

const int MAXN = 220;

namespace maxflow {
  const int MAXN = 220;
  const int inf = 1e9;

  int cap[MAXN][MAXN];
  int dad[MAXN];
  int n;

  bool bfs(int s, int t) {
    REP(i, n) dad[i] = -1;
    
    static queue<int> Q;
    while (!Q.empty()) Q.pop();

    dad[s] = s;
    Q.push(s);
    while (!Q.empty()) {
      int x = Q.front(); Q.pop();
      if (x == t) return true;
      REP(i, n)
        if (cap[x][i] > 0 && dad[i] == -1) {
          dad[i] = x;
          Q.push(i);
        }
    }
    return false;
  }

  void add_cap(int x, int y, int c) { 
    cap[x][y] += c; 
  }

  int solve(int s, int t) {
    int ans = 0;
    while (bfs(s, t)) {
      int f = inf;
      for (int x = t; x != s; x = dad[x])
        f = min(f, cap[dad[x]][x]);
      for (int x = t; x != s; x = dad[x]) {
        cap[dad[x]][x] -= f;
        cap[x][dad[x]] += f;
      }
      ans += f;
    }
    return ans;
  }
  
  void init(int N) {
    n = N;
    REP(i, n) REP(j, n) cap[i][j] = 0;
  }
};

int a[MAXN];
bool bio[MAXN];
bool e[MAXN][MAXN];

int main(void) {
  int n;
  scanf("%d", &n);
  REP(i, n) scanf("%d", a+i);

  int source = n, sink = n + 1;
  maxflow::init(n + 2);

  REP(i, n) REP(j, n)
    if (a[i]%2 == 0) {
      int x = a[i] + a[j];
      e[i][j] = true;
      for (int k = 2; k*k <= x; ++k)
        if (x%k == 0) { e[i][j] = false; break; }
    }

  REP(i, n)
    if (a[i]%2 == 0) {
      maxflow::add_cap(source, i, 2);
      REP(j, n)
        if (e[i][j]) maxflow::add_cap(i, j, 1);
    } else {
      maxflow::add_cap(i, sink, 2);
    }
  
  if (n%2 == 1 || maxflow::solve(source, sink) != n) {
    puts("Impossible");
    return 0;
  }

  vector< vector<int> > ans;
  REP(i, n)
    if (!bio[i]) {
      vector<int> v;
      int x = i;
      do {
        v.push_back(x);

        int y = -1;
        REP(j, n)
          if (e[x][j] || e[j][x]) {
            if (a[x]%2 == 0 && maxflow::cap[x][j] == 0) { y = j; break; }
            if (a[x]%2 == 1 && maxflow::cap[j][x] == 0) { y = j; break; }
          }
        assert(y != -1);

        maxflow::cap[x][y]++, maxflow::cap[y][x]++;
        bio[y] = true;
        x = y;
      } while (x != i);

      ans.push_back(v);
    }
  
  printf("%d\n", (int)ans.size());
  for (auto &v: ans) {
    printf("%d", (int)v.size());
    for (int x: v) printf(" %d", x+1);
    printf("\n");
  }

  return 0;
}
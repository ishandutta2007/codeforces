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

const int MAX = 3030;
const int inf = 1e9;

vector<int> E[MAX];
int d[MAX][MAX];
int n;

void bfs(int s, int d[MAX]) {
  REP(i, n) d[i] = inf;
  d[s] = 0;
  static queue<int> Q;
  Q.push(s);
  while (!Q.empty()) {
    int x = Q.front(); Q.pop();
    for (int y: E[x])
      if (d[y] >= inf) {
        d[y] = d[x] + 1;
        Q.push(y);
      }
  }
}

int main(void) {
  int m;
  scanf("%d %d", &n, &m);
  REP(i, m) {
    int a, b;
    scanf("%d %d", &a, &b);
    --a, --b;
    E[a].push_back(b);
    E[b].push_back(a);
  }
  
  REP(i, n) bfs(i, d[i]);
  
  int s1, t1, l1, s2, t2, l2;
  scanf("%d %d %d", &s1, &t1, &l1); --s1, --t1;
  scanf("%d %d %d", &s2, &t2, &l2); --s2, --t2;
  
  if (d[s1][t1] > l1 || d[s2][t2] > l2) {
    puts("-1");
    return 0;
  }

  int ans = max(0, m - d[s1][t1] - d[s2][t2]);
  REP(step, 2) {
    REP(a, n) REP(b, n) {
      int d1 = d[s1][a] + d[a][b] + d[b][t1];
      int d2 = d[s2][a] + d[a][b] + d[b][t2];
      if (d1 > l1 || d2 > l2) continue;
      ans = max(ans, m - (d1 + d2 - d[a][b]));
    }
    swap(s1, t1);
  }

  printf("%d\n", ans);
  return 0;
}
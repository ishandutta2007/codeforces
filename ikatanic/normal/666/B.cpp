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
int e[MAX][MAX];


int main(void) {
  int n, m;
  scanf("%d %d", &n, &m);
  REP(i, m) {
    int a, b;
    scanf("%d %d", &a, &b); --a, --b;
    E[a].push_back(b);
  }

  REP(i, n) {
    REP(j, n) e[i][j] = inf;
    e[i][i] = 0;
    queue<int> Q;
    Q.push(i);
    while (!Q.empty()) {
      int x = Q.front();
      Q.pop();

      for (int y: E[x])
        if (e[i][x] + 1 < e[i][y]) {
          e[i][y] = e[i][x] + 1;
          Q.push(y);
        }
    }
  }
  
  static vector<int> in[MAX];
  static vector<int> out[MAX];

  REP(i, n) {
    static bool bio[MAX];

    REP(j, n) bio[j] = false;
    bio[i] = true;
    REP(k, 3) {
      int m1 = -1;
      REP(j, n)
        if (!bio[j] && e[j][i] < inf)
          if (m1 == -1 || e[j][i] > e[m1][i]) m1 = j;
      if (m1 == -1) break;

      bio[m1] = true;
      in[i].push_back(m1);
    }

    REP(j, n) bio[j] = false;
    bio[i] = true;
    REP(k, 3) {
      int m1 = -1;
      REP(j, n)
        if (!bio[j] && e[i][j] < inf)
          if (m1 == -1 || e[i][j] > e[i][m1]) m1 = j;
      if (m1 == -1) break;

      bio[m1] = true;
      out[i].push_back(m1);
    }
  }

  int ansa = -1;
  int ansb = -1;
  int ansc = -1;
  int ansd = -1;
  
  int best = 0;
  REP(b, n) REP(c, n)
    if (b != c && e[b][c] < inf)
      for (int a: in[b])
        if (a != c)
          for (int d: out[c])
            if (a != d && b != d && e[a][b] + e[b][c] + e[c][d] > best) {
              best = e[a][b] + e[b][c] + e[c][d];
              ansa = a, ansb = b, ansc = c, ansd = d;
            }
  
  printf("%d %d %d %d\n", ansa+1, ansb+1, ansc+1, ansd+1);
  return 0;
}
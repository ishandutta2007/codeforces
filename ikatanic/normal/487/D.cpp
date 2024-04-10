#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

const int MAXN = 100100;
const int MAXM = 15;
const int INF = 1e9;

char a[MAXN][MAXM];
int tip[MAXN];
int x[MAXN], y[MAXN];
int f[MAXN][MAXM];
bool b[MAXN][MAXM];
bool bio[MAXN][MAXM];
char s[MAXN][5];
vector<int> v;

int n, m, q;

inline void go(int &x, int &y) {
  if (a[x][y] == '^') x--; else
    if (a[x][y] == 'v') x++; else
      if (a[x][y] == '<') y--; else
        y++;
}

inline bool go_to_the_first_important(int &x, int &y) {
  if (!b[x][y]) {
    int tmp = f[x][y];
    x = tmp/(m+2), y = tmp%(m+2);
    return tmp != INF;
  }
  return true;
}

int query(int x, int y) {
  if (!b[x][y]) {
    if (f[x][y] == INF) return f[x][y];
    if (!go_to_the_first_important(x, y)) return INF;
  }

  int step_cnt = 0;
  while (b[x][y] && step_cnt < 110) {
    go(x, y);
    if (!go_to_the_first_important(x, y)) return INF;
    step_cnt++;
  }

  if (b[x][y]) return INF;
  return x*(m+2) + y;
}

int dfs(int x, int y) {
  if (f[x][y] != -1) return f[x][y];
  if (bio[x][y]) return f[x][y] = INF;
  
  bio[x][y] = true;
  int X = x, Y = y;
  go(X, Y);
  f[x][y] = dfs(X, Y);
  return f[x][y];
}

int main(void) {
  scanf("%d %d %d", &n, &m, &q);
  FOR(i, 1, n+1) scanf("%s", a[i]+1);
  
  REP(i, q) {
    char t[10];
    scanf("%s", t);
    tip[i] = t[0] == 'C';
    
    scanf("%d %d", x+i, y+i);
    if (tip[i] == 1) {
      scanf("%s", s[i]);
      v.push_back(i);
    }
  }

  v.push_back(q);
  int cur = 0;
  REP(qi, (int)v.size()) {
    int i = v[qi];
    
    if (qi%100 == 0) {
      REP(i, n+2) REP(j, m+2) {
        f[i][j] = -1, b[i][j] = bio[i][j] = false;
        if (i == 0 || i == n+1 || j == 0 || j == m+1) f[i][j] = i*(m+2) + j;
      }

      for (int qj = qi; qj < qi+100 && qj < (int)v.size(); ++qj) {
        int j = v[qj];
        b[x[j]][y[j]] = true;
        f[x[j]][y[j]] = x[j]*(m+2) + y[j];
      }
      
      REP(i, n+2) REP(j, m+2) dfs(i, j);                    
    }

    while (cur < i) {
      if (tip[cur] == 0) {
        int ans = query(x[cur], y[cur]);
        if (ans == INF) puts("-1 -1"); else
          printf("%d %d\n", ans/(m+2), ans%(m+2));
      }
      cur++;
    }

    a[x[i]][y[i]] = s[i][0];
  }
    
  return 0;
}
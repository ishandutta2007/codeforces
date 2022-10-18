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

const int mod = 1e9 + 7;

inline int add(int a, int b) {
  return a+b >= mod ? a+b-mod : a+b;
}

inline int sub(int a, int b) {
  return a >= b ? a-b : a-b+mod;
}

inline int mul(int a, int b) {
  return llint(a)*b % mod;
}

const int MAX = 100100;
const int MAXK = 11;

vector<int> E[MAX];
int f[MAX][3][MAXK];
int n, m, k, p;

void dfs(int x, int dad) {
  for (int y: E[x]) {
    if (y != dad) dfs(y, x);
  }

  REP(c, 3) {
    static int g[MAXK];
    REP(i, p+1) g[i] = 0;
    g[0] = 1;

    for (int y: E[x]) {
      if (y != dad) {
        static int ng[MAXK];
        REP(i, p+1) ng[i] = 0;
        REP(i, p+1) REP(j, p-i+1) ng[i+j] = add(ng[i+j], mul(g[i], f[y][c][j]));
        REP(i, p+1) g[i] = ng[i];
      }
    }

    if (c == 0) {
      int fc = m - k;
      REP(i, p+1) {
        f[x][0][i] = add(f[x][0][i], mul(g[i], fc));
        f[x][1][i] = add(f[x][1][i], mul(g[i], fc));
      }
    }
    if (c == 1) {
      int fc = k - 1;
      REP(i, p+1) {
        f[x][0][i] = add(f[x][0][i], mul(g[i], fc));
        f[x][1][i] = add(f[x][1][i], mul(g[i], fc));
        f[x][2][i] = add(f[x][2][i], mul(g[i], fc));
      }
    }
    if (c == 2) {
      REP(i, p) {
        f[x][1][i+1] = add(f[x][1][i+1], g[i]);
      }
    }
  }
}

int main(void) {
  scanf("%d %d", &n, &m);
  REP(i, n-1) {
    int a, b;
    scanf("%d %d", &a, &b);
    --a, --b;
    E[a].push_back(b);
    E[b].push_back(a);
  }

  scanf("%d %d", &k, &p);
  
  dfs(0, -1);

  int ret = 0;
  REP(i, p+1) ret = add(ret, f[0][1][i]);
  
  printf("%d\n", ret);
  return 0;
}
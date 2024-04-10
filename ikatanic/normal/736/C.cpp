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

const int MAXN = 110;
const int MAXK = 25;

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

int f[MAXN][MAXN][MAXK];
int sz[MAXN];

vector<int> E[MAXN];
int n, k;

void dfs(int x, int dad) {
  for (int y: E[x])
    if (y != dad) dfs(y, x);

  sz[x] = 1;
  f[x][0][0] = 1;
  f[x][1][k+1] = 1;

  for (int y: E[x]) {
    if (y == dad) continue;

    static int nf[MAXN][MAXK];

    int nsz = sz[x] + sz[y];
    REP(i, nsz+1) REP(j, k+2) nf[i][j] = 0;

    REP(w1, sz[x]+1) REP(b1, k+2) REP(w2, sz[y]+1) REP(b2, k+2) {
      int nb = min(b1, b2 + 1);
      int nw1 = (!w1 || b2 + w1 <= k) ? 0 : w1;
      int nw2 = (!w2 || b1 + w2 <= k) ? 0 : w2 + 1;
      int nw = max(nw1, nw2);

      nf[nw][nb] = add(nf[nw][nb], mul(f[x][w1][b1], f[y][w2][b2]));
    }
      
    REP(i, nsz+1) REP(j, k+2) f[x][i][j] = nf[i][j];
    sz[x] = nsz;
  }

}

int main(void) {
  scanf("%d %d", &n, &k);
  REP(i, n-1) {
    int a, b;
    scanf("%d %d", &a, &b); --a, --b;
    E[a].push_back(b);
    E[b].push_back(a);
  }

  dfs(0, -1);

  int ans = 0;
  REP(i, k+2) ans = add(ans, f[0][0][i]);
  printf("%d\n", ans);
  return 0;
}
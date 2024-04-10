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

const int MAXN = 100010;

const int mod = 1e9 + 7;

int add(int a, int b) {
  return a+b >= mod ? a+b-mod : a+b;
}

int mul(int a, int b) {
  return (llint(a)*b)%mod;
}

int dad[MAXN];
int f[MAXN][2];
int g[MAXN][2][4];
vector<int> E[MAXN];

int main(void) {
  int n;
  scanf("%d", &n);
  FOR(i, 1, n) {
    scanf("%d", dad+i);
    dad[i]--;
    E[dad[i]].push_back(i);
  }

  for (int x = n-1; x >= 0; --x) {
    int m = E[x].size();
    REP(i, m+1) REP(c, 2) REP(s, 4) g[i][c][s] = 0;
    g[0][0][0] = 1;
    REP(i, m) REP(c, 2) REP(s, 4) {
      REP(cur, 2)
        g[i+1][c^cur][s | (1<<cur)] = add(g[i+1][c^cur][s | (1<<cur)], mul(g[i][c][s], f[E[x][i]][cur]));
      g[i+1][c][s] = add(g[i+1][c][s], g[i][c][s]);
    }

    REP(c, 2) REP(s, 4) {
      f[x][c^1] = add(f[x][c^1], g[m][c][s]);
      if (s == 3 || (s == 2 && c == 0))
        f[x][c^1] = add(f[x][c^1], g[m][c][s]);
    }
  }
  
  int ans = add(f[0][0], f[0][1]);
  printf("%d\n", ans);
  return 0;
}
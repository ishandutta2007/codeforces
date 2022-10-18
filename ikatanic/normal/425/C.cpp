#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>

using namespace std;

#define TRACE(x) cout << #x << " = " << x << endl
#define REP(i, n) for (int i = 0; i < (n); ++i)

typedef long long llint;

const int MAXN = 100010;
const int MAXK = 303;
const int inf = 1e9;

int f[MAXN][MAXK];
int p[MAXN][MAXK];

int a[MAXN], b[MAXN];
vector<int> vb[MAXN];

int main(void) {
  int n, m, s, e;
  scanf("%d %d %d %d", &n, &m, &s, &e);
  REP(i, n) scanf("%d", a+i);
  REP(i, m) {
    scanf("%d", b+i);
    vb[b[i]].push_back(i);
  }

  int K = (s/e) + 1;
  REP(i, MAXN) {
    int sz = vb[i].size();
    REP(k, K) {
      p[i][k] = sz;
      f[i][k] = inf;
    }
  }

  f[0][0] = 0;
  REP(i, n) {
    int x = a[i];
    REP(k, K) 
      if (f[i][k] < inf) {
        f[i+1][k] = min(f[i+1][k], f[i][k]);
        while (p[x][k] > 0 && vb[x][ p[x][k]-1 ] >= f[i][k]) p[x][k]--;
        if (p[x][k] < (int)vb[x].size()) f[i+1][k+1] = min(f[i+1][k+1], vb[x][ p[x][k] ]+1);
      }
  }

  int ans = 0;
  REP(i, n+1) REP(k, K)
    if (f[i][k] < inf) {
      int total_e = k*e + i + f[i][k];
      if (total_e <= s) ans = max(ans, k);
    }

  printf("%d\n", ans);
  return 0;
}
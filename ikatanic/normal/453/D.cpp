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

const int MAXN = 1<<20;
const int M = 21;
int mod;

int add(int a, int b) {
  return a+b >= mod ? a+b-mod : a+b;
}

int mul(int a, int b) {
  return (llint(a)*b)%mod;
}

int b[M];
int e[MAXN];
int f[M][MAXN];
int w[M][M][M];
int C[M][M];

void merge(int *a, int *b, int n) {
  static int c[M];
  REP(k, n) {
    c[k] = 0;
    REP(i, n) REP(j, n)
      c[k] = add(c[k], mul(mul(a[i], b[j]), w[i][j][k]));
  }
  REP(k, n) a[k] = c[k];
}

int main(void) {
  int m;
  llint t;
  scanf("%d %lld %d", &m, &t, &mod);
  int n = 1<<m;

  REP(i, n) {
    scanf("%d", e+i);
    e[i] %= mod;
  }
  REP(j, m+1) {
    scanf("%d", b+j);
    b[j] %= mod;
  }
  
  REP(i, m+1) {
    C[i][0] = 1;
    FOR(j, 1, i+1)
      C[i][j] = add(C[i-1][j-1], C[i-1][j]);
  }

  REP(a, m+1) REP(b, m+1) REP(c, m+1) {
    int d = (c + a - b) / 2;
    if (b != c+a-2*d) continue;
    if (d < 0 || d > c || d > a || m-c < a-d) continue;
    w[a][b][c] = mul(C[c][d], C[m - c][a - d]);
  }

  int r[M];
  REP(i, m+1) r[i] = 0;
  r[0] = 1;
  
  while (t > 0) {
    if (t&1) merge(r, b, m+1);
    merge(b, b, m+1);
    t /= 2;
  }

  REP(i, n) f[0][i] = e[i];
  REP(k, m)
    for (int j = m; j > 0; --j)
      REP(i, n)
        f[j][i] = add(f[j][i], f[j-1][i ^ (1<<k)]);

  REP(i, n) {
    int ans = 0;
    REP(j, m+1)
      ans = add(ans, mul(f[j][i], r[j]));
    printf("%d\n", ans);
  }
  
  return 0;
}
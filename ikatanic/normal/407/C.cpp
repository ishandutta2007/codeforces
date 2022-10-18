#include <algorithm>

#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <string>
#include <vector>
#include <iostream>

using namespace std;

#define TRACE(x) cout << #x << " = " << x << endl
#define REP(i, n) for (int i = 0; i < (n); ++i)

typedef long long llint;

const int mod = 1e9 + 7;
const int MAXN = 101000;
const int MAXK = 110;
const int K = 100;

int f[MAXN][MAXK];
int C[MAXN][MAXK];
int a[MAXN];

int add(int a, int b) {
  return a+b >= mod ? a+b-mod : a+b;
}

int neg(int x) {
  return x == 0 ? 0 : mod-x;
}

int main(void) {
  int n, m;
  scanf("%d %d", &n, &m);
  REP(i, n) scanf("%d", a+i);

  REP(i, n+MAXK) {
    C[i][0] = 1;
    for (int j = 1; j <= i && j < MAXK; ++j)
      C[i][j] = add(C[i-1][j], C[i-1][j-1]);
  }

  REP(i, m) {
    int l, r, k;
    scanf("%d %d %d", &l, &r, &k); --l;

    REP(i, k+1) {
      f[l][K-k+i] = add(f[l][K-k+i], C[k][i]);
      f[r][K-k+i] = add(f[r][K-k+i], neg(C[r-l+k][i]));
    }
  }
  
  for (int i = 1; i < n; ++i) {
    f[i][0] = add(f[i][0], f[i-1][0]);
    for (int j = 1; j <= K; ++j)
      f[i][j] = add(f[i][j], add(f[i-1][j], f[i-1][j-1]));
  }

  REP(i, n) {
    a[i] = add(a[i], f[i][K]);
    printf("%d%c", a[i], i == n-1  ? '\n' : ' ');
  }
  return 0;
}
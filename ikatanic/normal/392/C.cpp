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

const int M = 84;
const int mod = 1e9 + 7;

struct matrix {
  int a[M][M];
  matrix() { REP(i, M) REP(j, M) a[i][j] = 0; }

  int* operator [] (int i) { return a[i]; }
  friend matrix operator * (const matrix &a, const matrix &b) {
    matrix r;
    REP(i, M) REP(j, M) REP(k, M) 
      r[i][j] = (r[i][j] + llint(a.a[i][k])*b.a[k][j])%mod;
    return r;
  }
};

matrix pow(matrix a, llint b) {
  if (b == 1) return a;
  if (b%2) return a*pow(a, b-1);
  a = pow(a, b/2);
  return a*a;
}

int C[44][44];

int main(void) {
  llint n;
  int k;
  cin >> n >> k;
  
  if (n == 1) {
    printf("%d\n", 1);
    return 0;
  }

  for (int i = 0; i <= k; ++i) {
    C[i][0] = 1;
    for (int j = 1; j <= i; ++j)
      C[i][j] = (C[i-1][j] + C[i-1][j-1])%mod;
  }

  k++;
  matrix b;
  REP(i, k) REP(j, i+1) {
    b[i][j] = b[i][j+k] = C[i][j];
    REP(l, i-j)
      b[i][j+k] = (b[i][j+k] + b[i][j+k])%mod;
  }
  REP(i, k)
    b[i+k][i] = 1;

  int fs = 2*k;
  b[fs][fs] = 1;
  b[fs][k-1] = 1;
 
  matrix f;
  REP(i, k) {
    f[i][0] = 2;
    f[i+k][0] = 1;
    REP(l, i)
      f[i][0] = (f[i][0] + f[i][0])%mod;
  }
  f[fs][0] = 1;
  f = pow(b, n-1)*f;
  printf("%d\n", f[fs][0]);
  return 0;
}
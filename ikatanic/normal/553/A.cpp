#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <cstdio>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

const int MAXN = 1010;
const int mod = 1e9 + 7;

int add(int a, int b) {
  return a+b >= mod ? a+b-mod : a+b;
}

int sub(int a, int b) {
  return a >= b ? a-b : a-b+mod;
}

int mul(int a, int b) {
  return llint(a)*b % mod;
}

int C[MAXN][MAXN];
int f[MAXN][MAXN];
int a[MAXN];

int main(void) {
  REP(i, MAXN) {
    C[i][0] = 1;
    FOR(j, 1, i+1)
      C[i][j] = add(C[i-1][j], C[i-1][j-1]);
  }
  
  int n;
  scanf("%d", &n);
  REP(i, n) scanf("%d", a+i);
  reverse(a, a + n);

  f[0][0] = 1;
  REP(i, n+1)
    for (int j = MAXN-1; j >= 0; --j)
      if (f[i][j]) {
        if (j > 0) f[i][j-1] = add(f[i][j-1], f[i][j]);
        if (i < n) f[i+1][j+a[i]-1] = add(f[i+1][j+a[i]-1], mul(f[i][j], C[j+a[i]-1][j]));
      }

  printf("%d\n", f[n][0]);
  return 0;
}
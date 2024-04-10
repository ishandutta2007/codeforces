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

const int MAX = 4040;
const int mod = 1e9 + 7;

int add(int a, int b) {
  return a+b >= mod ? a+b-mod : a+b;
}

int mul(int a, int b) {
  return llint(a)*b % mod;
}

int f[MAX][2];
int C[MAX][MAX];

int main(void) {
  REP(i, MAX) {
    C[i][0] = 1;
    FOR(j, 1, i+1)
      C[i][j] = add(C[i-1][j], C[i-1][j-1]);
  }

  int n;
  scanf("%d", &n);

  f[n][0] = 1;
  for (int i = n; i >= 1; --i) 
    REP(c, 2) {
      for (int j = 1; j <= i; ++j) {
        f[i-j][c] = add(f[i-j][c], mul(f[i][c], C[i-1][j-1]));
        if (j == 1) f[i-j][1] = add(f[i-j][1], mul(f[i][c], C[i-1][j-1]));
      }
    }

  printf("%d\n", f[0][1]);
  return 0;
}
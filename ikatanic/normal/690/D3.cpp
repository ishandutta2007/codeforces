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

const int mod = 1e6 + 3;
const int M = 104;

int add(int a, int b) {
  return a+b >= mod ? a+b-mod : a+b;
}
int mul(int a, int b) {
  return (llint(a)*b)%mod;
}

struct matrix {
  int a[M][M];
  matrix() { REP(i, M) REP(j, M) a[i][j] = 0; }
  
  int* operator[] (int i) { return a[i]; }
  friend matrix operator* (matrix a, matrix b) {
    matrix r;
    REP(i, M) REP(j, M) REP(k, M) 
      r[i][j] = add(r[i][j], mul(a[i][k], b[k][j]));
    return r;
  }
};

matrix power(matrix a, llint b) {
  assert(b > 0); b--;
  matrix r = a;
  while (b > 0) {
    if (b&1) r = r*a;
    a = a*a, b /= 2;
  }
  return r;
}

int main(void) {
  int C, W, H;
  scanf("%d %d %d", &C, &W, &H);

  vector<int> pw;
  int cur = 1;
  REP(i, W+1) {
    pw.push_back(cur);
    cur = mul(cur, H);
  }

  matrix a;
  a[0][0] = 1;

  matrix b;
  REP(i, W+1) {
    b[i][0] = pw[i];
  }
  FOR(i, 1, W+1) {
    b[i-1][i] = 1;
  }

  a = a * power(b, C + 1);
  printf("%d\n", a[0][0]);
  return 0;
}
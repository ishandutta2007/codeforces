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

const int MAX = 128;

int add(int a, int b) {
  return a+b >= mod ? a+b-mod : a+b;
}
int mul(int a, int b) {
  return (llint(a)*b)%mod;
}

int M;

struct matrix {
  int a[MAX][MAX];
  matrix() { REP(i, M) REP(j, M) a[i][j] = 0; }
  
  int* operator [] (int i) { return a[i]; }
  friend matrix operator * (matrix a, matrix b) {
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

int w[10];

int main(void) {  
  FOR(i, 1, 8) scanf("%d", w+i);

  bool left[10], right[10], mid[10];

  matrix a;
  M = 1<<7;
  a[0][M-1] = 1;
  for (int n = 7; n >= 1; --n) {
    matrix b;
    REP(sl, 1<<n) REP(sr, 1<<n) REP(sm, 1<<(n-1)) {
      REP(i, n) {
        left[i] = (sl>>i)&1;
        right[i] = (sr>>i)&1;
      }
      REP(i, n-1)
        mid[i+1] = (sm>>i)&1;
      mid[0] = mid[n] = 1;

      bool ok = true;
      REP(i, n)
        if (left[i] && right[i] && mid[i] && mid[i+1]) ok = false;
      
      if (ok) b[sl][sr]++;
    }

    if (w[n] > 0) {
      b = power(b, w[n]);
      a = a * b;
    }

    REP(i, 1<<(n-1))
      a[0][i] = a[0][i | (1<<(n-1))];
    M >>= 1;
  }
  
  printf("%d\n", a[0][0]);
  return 0;
}
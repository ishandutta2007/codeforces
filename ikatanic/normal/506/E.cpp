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

const int M = 310;
const int mod = 10007;

int add(int a, int b) {
  return a+b >= mod ? a+b-mod : a+b;
}

int mul(int a, int b) {
  return (a*b)%mod;
}

struct matrix {
  int a[M][M];
  matrix() { REP(i, M) REP(j, M) a[i][j] = 0; }
  
  int* operator [] (int i) { return a[i]; }
  friend matrix operator * (matrix a, matrix b) {
    matrix r;
    REP(i, M) REP(j, M) {
      llint ans = 0;
      FOR(k, i, j+1) 
        ans += a[i][k] * b[k][j];
      r[i][j] = ans % mod;
    }
    return r;
  }
};

matrix power(matrix a, int b) {
  if (b == 0) {
    REP(i, M) REP(j, M) a[i][j] = i == j;
    return a;
  }
  b--;
  matrix r = a;
  while (b > 0) {
    if (b&1) r = r*a;
    a = a*a, b /= 2;
  }
  return r;
}

const int MAXN = 202;

char s[MAXN];
int f[MAXN][MAXN][MAXN];

int main(void) {
  int m;
  scanf("%s", s);
  scanf("%d", &m);
  int n = strlen(s);
  m += n;

  f[0][n][0] = 1;
  for (int i = 0; i < n; ++i)
    for (int j = n; j > i; --j)
      for (int k = 0; k < n; ++k)
        if (s[i] == s[j-1]) {
          f[i+1][j-1][k+1] = add(f[i+1][j-1][k+1], f[i][j][k]);
        } else {
          f[i+1][j][k] = add(f[i+1][j][k], f[i][j][k]);
          f[i][j-1][k] = add(f[i][j-1][k], f[i][j][k]);
        } 
  

  bool odd = m % 2;
  int ans = 0;

  { // i, i
    matrix b;
    int start25 = 0;
    int start26 = start25 + 100;
    int start24 = start26 + 1;
    int end = start24 + 200;
    REP(i, end-1) b[i][i+1] = 1;
    REP(i, end)
      if (i < start26) b[i][i] = 25; else
        if (i < start24) b[i][i] = 26; else
          b[i][i] = 24;
    b = power(b, m / 2);
    
    REP(k, n+1) {
      int ways = 0;
      REP(i, n+1)
        ways = add(ways, f[i][i][k]);
      int A = k, B = n - 2*k;
      
      if (odd) ways = mul(ways, 26);
      
      ways = mul(ways, b[start26 - A][start24 + B - 1]);
      ans = add(ans, ways);
    }
  }

  { // i, i-1
    matrix b;
    int start25 = 0;
    int start26 = start25 + 100;
    int start24 = start26 + 1;
    int end = start24 + 200;
    REP(i, end-1) b[i][i+1] = 1;
    REP(i, end)
      if (i < start26) b[i][i] = 25; else
        if (i < start24) b[i][i] = 26; else
          b[i][i] = 24;
    b = power(b, m / 2);
    
    REP(k, n+1) {
      int ways = 0;
      FOR(i, 1, n+1)
        ways = add(ways, f[i][i-1][k]);
      int A = k, B = n - 2*k + 1;
      
      if (odd) ways = mul(ways, 26);
      
      ways = mul(ways, b[start26 - A][start24 + B - 1]);
      ans = add(ans, ways);
    }
  }


  if (odd) { // i, i+1
    matrix b;
    int start25 = 0;
    int start24 = start25 + 100;
    int end = start24 + 200;
    REP(i, end-1) b[i][i+1] = 1;
    REP(i, end)
      if (i < start24) b[i][i] = 25; else
        b[i][i] = 24;
    b = power(b, m / 2);
    
    REP(k, n+1) {
      int ways = 0;
      REP(i, n) ways = add(ways, f[i][i+1][k]);
      int A = k+1, B = n - 2*k - 1;
      
      ways = mul(ways, b[start24 - A][start24 + B - 1]);
      ans = add(ans, ways);
    }
  }

  printf("%d\n", ans);
  return 0;
}
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

int add(int a, int b) {
  return a+b >= mod ? a+b-mod : a+b;
}

int mul(int a, int b) {
  return (llint(a)*b)%mod;
}

const int M = 32;

struct matrix {
  int a[M][M];
  matrix() { REP(i, M) REP(j, M) a[i][j] = 0; }
  
  int* operator [] (int i) { return a[i]; }
  friend matrix operator * (matrix a, matrix b) {
    matrix r;
    REP(i, M) REP(j, M) REP(k, M) 
      r[i][j] = add(r[i][j], mul(a[i][k], b[k][j]));
    return r;
  }
};

const int MAXD = 64;
const int MAXK = 32;

matrix f[MAXD];
int k;

matrix calc_matrix(int n, int off) {
  matrix ans;
  REP(i, k+1) REP(j, k+1) {
    int ni = i == k ? i : (i + off)%k;
    int nj = j == k ? j : (j + off)%k;
    ans[ni][nj] = f[n][i][j];
  }
  return ans;
}

int sum_digits(llint n) {
  int ans = 0;
  while (n > 0) {
    ans += n%k;
    n /= k;
  }
  return ans%k;
}

int main(void) {
  llint n;
  scanf("%lld %d", &n, &k);

  int ndigits = 0;
  llint tmp = n;
  while (tmp > 0) {
    tmp /= k;
    ndigits++;
  }

  matrix id;
  REP(i, k+1) id[i][i] = 1;

  f[0] = id;
  REP(i, k+1) f[0][i][0] = 1;
  FOR(i, 1, ndigits) {
    f[i] = id;
    REP(j, k) f[i] = f[i] * calc_matrix(i-1, j);    
  }

  llint cur = 0;
  llint pw = 1;

  ndigits--;
  REP(i, ndigits) pw *= k;

  matrix ans = id;
  while (cur < n) {
    assert(ndigits >= 0);
    while (cur + pw <= n) {
      ans = ans * calc_matrix(ndigits, sum_digits(cur));
      cur += pw;
    }
    pw /= k;
    ndigits--;
  }

  int sum = 0;
  REP(i, k+1) sum = add(sum, ans[k][i]);
  printf("%d\n", sum);
  return 0;
}
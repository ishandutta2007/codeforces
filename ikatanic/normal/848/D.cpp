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

const int MAX = 52;

const int mod = 1e9 + 7;

inline int add(int a, int b) {
  return a+b >= mod ? a+b-mod : a+b;
}

inline int sub(int a, int b) {
  return a >= b ? a-b : a-b+mod;
}

inline int mul(int a, int b) {
  return llint(a)*b % mod;
}

int powmod(int a, int b) {
  if (b == 0) return 1;
  if (b&1) return mul(a, powmod(a, b-1));
  return powmod(mul(a, a), b/2);
}

int choose(int n, int k) {
  if (n < k) return 0;
  
  int ret = 1;
  REP(i, k) ret = mul(ret, n - i);
  int denom = 1;
  FOR(i, 1, k + 1) denom = mul(denom, i);
  ret = mul(ret, powmod(denom, mod - 2));
  return ret;
}

int f[MAX][MAX];
int g[MAX][MAX][MAX][MAX];
int h[MAX][MAX];

int main(void) {
  f[0][1] = 1;
  h[0][1] = 1;
  
  REP(i, MAX) REP(j, MAX) g[0][0][i][j] = 1;
  
  for (int n = 1; n < MAX-1; ++n) {
    for (int k = 1; k <= n+1; ++k) {
      for (int l = 1; l <= k; ++l) {
        g[n][k][l][0] = g[n][k][l - 1][n];
        for (int m = 1; m <= n; ++m) {
          g[n][k][l][m] = g[n][k][l][m - 1];
          for (int c = 1; c * l <= k && c * m <= n; ++c) {
            int nn = n - m * c;
            int nk = k - c * l;
            int nl = l;
            int nm = min(m - 1, nn);

            if (nl > nk) {
              nl = nk;
              nm = nn;
            }

            
            int ways = g[nn][nk][nl][nm];
            ways = mul(ways, choose(add(h[m - 1][l], c - 1), c));
            //            if (n == 4 && k == 3) TRACE(l _ c _ m _ ways _ h[m-1][l]);
            g[n][k][l][m] = add(g[n][k][l][m], ways);
          }
        }
      }
    }
    
    for (int k = 1; k <= n+1; ++k) {
      f[n][k] = g[n][k - 1][k - 1][n];
    }

    for (int k = 1; k <= n+1; ++k) {
      for (int nl = 0; nl <= n; ++nl) {
        int nr = n - nl;
        for (int kl = k; kl <= nl+1; ++kl) {
          for (int kr = k; kr <= nr+1; ++kr) {
            if (min(kl, kr) == k) {
              h[n][k] = add(h[n][k], mul(f[nl][kl], f[nr][kr]));
            }
          }
        }
      }
    }
  }

  //  REP(n, 10) REP(k, n+2) TRACE(n _ k _ f[n][k] _ h[n][k]);
  
  int n, k;
  scanf("%d %d", &n, &k);
  printf("%d\n", f[n][k]);
  return 0;
}
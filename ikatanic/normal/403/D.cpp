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
const int MAXN = 1001;
const int K = 50;

int ans[K+1][MAXN];
int f[2][K+1][MAXN];
int C[2*MAXN][K+1];
int fact[K+1];
 
int add(int x, int y) {
  if (x+y >= mod) return x+y-mod;
  return x+y;
}

int mul(int x, int y) {
  return (llint(x)*y)%mod;
}

int main(void) {
  fact[0] = 1;
  for (int i = 1; i < K; ++i)
    fact[i] = mul(i, fact[i-1]);

  for (int i = 0; i < 2*MAXN; ++i) {
    C[i][0] = 1;
    for (int j = 1; j <= i && j < K; ++j)
      C[i][j] = add(C[i-1][j], C[i-1][j-1]);
  }

  f[0][0][0] = 1;
  REP(i, MAXN) {
    int now = i&1, next = now^1;
    
    int n = i;
    REP(k, K) REP(sum, n)
      if (f[now][k][sum] && sum+k <= n)
        ans[k][n] = add(ans[k][n], mul(f[now][k][sum], C[n-sum-k+k][k]));

    REP(j, K) REP(l, MAXN)
      if (f[now][j][l]) {
        if (l+i < MAXN)
          f[next][j+1][l+i] = add(f[next][j+1][l+i], f[now][j][l]);

        f[next][j][l] = add(f[next][j][l], f[now][j][l]);
        f[now][j][l] = 0;
      }
  }
  
  int t;
  scanf("%d", &t);
  while (t--) {
    int n, k;
    scanf("%d %d", &n, &k);

    int r = 0;
    if (k < K) r = mul(fact[k], ans[k][n]);
    printf("%d\n", r);
  }
  return 0;
}
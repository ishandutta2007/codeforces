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

const int MAXN = 404;
const int inf = 1e8;

int dp[MAXN];
int g[MAXN][MAXN];
int f[MAXN][MAXN];
int v[MAXN], w[MAXN];
int n;

int getV(int l) {
  return (l >= 0 && l < n) ? v[l] : -inf;
}

int score(int i, int j, int k = -1) {
  if (k != -1) return getV(w[k]-w[i] + w[k]-w[j]);
  return getV(w[i] < w[j] ? w[j]-w[i] : w[i]-w[j]);
}

int main(void) {
  scanf("%d", &n);
  REP(i, n) scanf("%d", v+i);
  REP(i, n) scanf("%d", w+i);
  
  REP(d, n) REP(i, n) {
    int j = i+d;
    if (j >= n) continue;

    f[i][j] = g[i][j] = -inf;
    
    if (i == j) {
      f[i][j] = 0;
      g[i][j] = score(i, j);
      continue;
    }
    
    if (w[i]+1 == w[j] || w[i]-1 == w[j]) f[i][j] = g[i+1][j-1]; else
      for (int k = i+1; k < j; ++k)
        if ((w[i] < w[j] && w[i]+1 == w[k]) || (w[i] > w[j] && w[i]-1 == w[k])) 
          f[i][j] = max(f[i][j], g[i+1][k-1] + f[k][j]);
    
    g[i][j] = max(g[i][j], f[i][j] + score(i, j));
    for (int k = i; k < j; ++k)
      g[i][j] = max(g[i][j], g[i][k] + g[k+1][j]);
    for (int k = i+1; k < j; ++k)
      if (w[k] > w[i] && w[k] > w[j])
        g[i][j] = max(g[i][j], f[i][k] + f[k][j] + score(i, j, k));
  }

  REP(i, n+1) dp[i] = 0;
  REP(i, n) {
    dp[i+1] = max(dp[i+1], dp[i]);
    for (int j = i; j < n; ++j)
      dp[j+1] = max(dp[j+1], dp[i] + g[i][j]);
  }

  printf("%d\n", dp[n]);
  return 0;
}
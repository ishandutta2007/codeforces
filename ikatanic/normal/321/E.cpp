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

const int MAXBUFF = 1<<20;

namespace IO {
  char buffer[MAXBUFF], *p = buffer+MAXBUFF;
  
  inline char read_char() {
    if (p == buffer+MAXBUFF) {
      fread(buffer, 1, MAXBUFF, stdin);
      p = buffer;
    }
    return *p++;
  }
  
  inline int read_int() {
    char c;
    while (!isdigit(c = read_char()));
    int ret = c-'0';
    while (isdigit(c = read_char())) ret = ret*10 + c-'0';
    return ret;
  }
};

const int MAXN = 4040;
const int inf = 1e9;

int a[MAXN][MAXN];
int s[MAXN][MAXN];
int cost[MAXN][MAXN];

int f[MAXN][MAXN]; // k, i
int A[MAXN][MAXN];

int sum(int x1, int y1, int x2, int y2) {
  return s[x2][y2] - s[x1-1][y2] - s[x2][y1-1] + s[x1-1][y1-1];
}

int main(void) {
  int n, K;
  scanf("%d %d", &n, &K);
  REP(i, n) REP(j, n) a[i][j] = IO::read_int();

  FOR(i, 1, n+1) FOR(j, 1, n+1)
    s[i][j] = s[i-1][j] + s[i][j-1] - s[i-1][j-1] + a[i-1][j-1];
  FOR(i, 1, n+1) FOR(j, i, n+1)
    cost[i][j] = sum(i, i, j, j) / 2;

  FOR(i, 1, n+1) f[1][i] = cost[1][i];
  FOR(i, 1, n+1) for (int k = K; k >= 2; --k) {
    int lo = i > 1 ? A[k][i-1] : 0;
    int hi = k < K-1 ? A[k+1][i] : n;
    A[k][i] = -1, f[k][i] = inf;
    for (int j = lo; j <= hi && j < i; ++j) {
      int c = f[k-1][j] + cost[j+1][i];
      if (c < f[k][i]) f[k][i] = c, A[k][i] = j;
    }
    assert(A[k][i] != -1);
  }

  printf("%d\n", f[K][n]);
  return 0;
}
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

const int MAXN = 5050;

const int mod = 1e9 + 7;

int add(int a, int b) {
  return a+b >= mod ? a+b-mod : a+b;
}

int sub(int a, int b) {
  return a >= b ? a-b : a-b+mod;
}

int mul(int a, int b) {
  return (llint(a)*b)%mod;
}

short same[MAXN][MAXN];
short best[MAXN][MAXN];
int f[MAXN][MAXN];
bool can[MAXN][MAXN];

char a[MAXN];
int n;

inline void update(int i, int j, int d, short b) {
  if (!can[i][j]) {
    can[i][j] = true;
    best[i][j] = b;
  } else
    best[i][j] = min(best[i][j], b);
  f[i][j] = add(f[i][j], d);
}

int compare(int i, int j) {
  int len = j - i;
  if (same[i][j] >= len) return 0;
  return a[i + same[i][j]] < a[j + same[i][j]] ? 1 : -1;
}

int getDiff(int i, int j) {
  if (i < j) {
    return 1 << min(20, n-i-1);
  }
  if (j < i) {
    return -(1 << min(20, n-j-1));
  }
  return 0;
}

int main(void) {
  scanf("%s", a);
  n = strlen(a);
  REP(i, n) a[i] -= '0';

  for (int i = n-1; i >= 0; --i)
    for (int j = n-1; j >= 0; --j)
      if (a[i] == a[j]) same[i][j] = 1 + same[i+1][j+1];
  
  can[0][0] = true;
  f[0][0] = 1;
  best[0][0] = 0;

  REP(i, n) FOR(j, i, n)
    if (can[i][j]) {
      if (i || j) update(i, j+1, f[i][j], best[i][j]);

      int len = j - i;
      int nextj = j + len;
      if (nextj > n || a[j] == 0) continue;

      if (compare(i, j) < 0) nextj++;
      if (nextj > n) continue;

      if (i == 0 && j == 0) nextj = 1;

      update(j, nextj, f[i][j], best[i][j] + 1);
    }
  
  int ans = 0;
  int k = -1;
  int bestk = -1;
  REP(i, n) 
    if (can[i][n]) {
      ans = add(ans, f[i][n]);
      assert(a[i] == 1);

      if (k == -1) k = i, bestk = best[i][n]; else {
        int diff = getDiff(i, k);
        if (best[i][n] - bestk + diff < 0) k = i, bestk = best[i][n];
      }
    }
  
  int ans2 = 0;
  FOR(i, k, n)
    ans2 = add(mul(ans2, 2), a[i]);
  ans2 = add(ans2, bestk);

  printf("%d\n%d\n", ans, ans2);
  return 0;
}
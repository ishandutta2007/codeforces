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

const int MAXN = 2020;

int f[MAXN][MAXN];
char s[MAXN], p[MAXN];

int main(void) {
  scanf("%s", s);
  scanf("%s", p);

  int n = strlen(s);
  int m = strlen(p);

  REP(i, n) {
    int next = i;
    bool can = true;
    REP(it, m) {
      while (next < n && s[next] != p[it]) next++;
      if (next == n) {
        can = false;
        break;
      }
      next++;
    }

    int cntx = next - i - m;
    REP(j, i+1) {
      f[i+1][j+1] = max(f[i+1][j+1], f[i][j]);
      f[i+1][j] = max(f[i+1][j], f[i][j]);
      if (can) f[next][j+cntx] = max(f[next][j+cntx], f[i][j] + 1);
    }
  }

  REP(i, n+1)
    printf("%d ", f[n][i]);
  printf("\n");
  return 0;
}
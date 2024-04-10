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

const int MAX = 5050;
const int mod = 1e9 + 7;

inline int add(int a, int b) {
  return a+b >= mod ? a+b-mod : a+b;
}

int f[MAX][MAX];
int lcp[MAX][MAX];
char s[MAX];

int main(void) {
  int n;
  scanf("%d", &n);
  scanf("%s", s);
  REP(i, n) s[i] -= '0';
  
  for (int i = n-1; i >= 0; --i)
    for (int j = n-1; j >= i; --j) {
      if (s[i] != s[j]) {
        lcp[i][j] = 0;
      } else {
        lcp[i][j] = 1 + lcp[i + 1][j + 1];
      }
    }

  f[0][0] = 1;
  REP(i, n) REP(j, i + 1) {
    f[i + 1][j] = add(f[i + 1][j], f[i][j]);

    int len = i - j + 1;
    int ni = i + 1;

    if (ni + len <= n) {
      int lc = lcp[j][ni];
      if (s[ni] && lc < len && s[j+lc] < s[ni+lc]) {
        f[ni+len-1][ni] = add(f[ni+len-1][ni], f[i][j]);
      } else
        if (s[ni] && ni + len + 1 <= n) {
          f[ni+len][ni] = add(f[ni+len][ni], f[i][j]);
        }
    }
  }

  int ans = 0;
  REP(j, n) ans = add(ans, f[n][j]);
  printf("%d\n", ans);
  return 0;
}
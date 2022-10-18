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

const int MAX = 110;
const int N = 3;

char s[N][MAX];
bool train[MAX][N][MAX];
bool f[N][MAX];

int main(void) {
  int t;
  scanf("%d", &t);
  while (t--) {
    int M, K;
    scanf("%d %d", &M, &K);
    REP(i, N) scanf("%s", s[i]);

    REP(t, M+1) REP(i, N) REP(j, M) train[t][i][j] = false;

    REP(i, N) REP(j, M-1)
      if (isalpha(s[i][j]) && s[i][j] == s[i][j+1]) {
        int k = j;
        while (k < M && s[i][k] == s[i][j]) k++;
        FOR(l, j, k) s[i][l] = '.';

        REP(t, M+1) {
          for (int l = max(0, j - 2*t); l < max(0, k - 2*t); ++l)
            train[t][i][l] = true;
        }
      }
    
    int si = -1;
    REP(i, 3)
      if (s[i][0] == 's') si = i;
    assert(si != -1);

    REP(i, 3) REP(j, M) f[i][j] = false;
    f[si][0] = true;
    REP(j, M-1) REP(i, N)
      if (f[i][j]) {
        int nj = j + 1;

        if (!train[j][i][nj]) {
          for (int dx = -1; dx <= 1; ++dx) {
            int ni = i + dx;
            if (ni < 0 || ni >= N) continue;
            if (train[j][ni][nj] || train[j+1][ni][nj]) continue;
            f[ni][nj] = true;
          }
        }
      }

    bool ok = false;
    REP(i, N) ok |= f[i][M-1];
    puts(ok ? "YES" : "NO");
  }
  return 0;
}
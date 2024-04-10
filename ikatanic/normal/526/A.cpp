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

char s[111];
bool can[2][111][111];

int main(void) {
  int n;
  scanf("%d", &n);
  scanf("%s", s);

  REP(rot, 2) {
    REP(i, n) FOR(j, i+1, n) {
      int k = j + j-i;
      if (k >= n) continue;
      if (s[i] != '*' || s[j] != '*' || s[k] != '*') continue;
      can[rot][k][j-i] = true;
    }
    reverse(s, s + n);
  }
  
  REP(i, n) REP(d, n)
    if (can[0][i][d] && can[1][n-i-1][d]) {
      puts("yes");
      return 0;
    }

  puts("no");
  return 0;
}
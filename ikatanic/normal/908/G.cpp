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

const int MAX = 707;
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

int pw[11][MAX], sum_pw[11][MAX];
int C[MAX][MAX];
int g[10][MAX];

int main(void) {
  char s[MAX];
  scanf("%s", s);

  REP(d, 11) {
    pw[d][0] = 1;
    sum_pw[d][0] = 0;
    FOR(i, 1, MAX) {
      sum_pw[d][i] = add(sum_pw[d][i - 1], pw[d][i-1]);
      pw[d][i] = mul(pw[d][i-1], d);
    }
  }

  REP(i, MAX) {
    C[i][0] = 1;
    FOR(j, 1, i+1) {
      C[i][j] = add(C[i-1][j-1], C[i-1][j]);
    }
  }

  int ret = 0;
  int len = strlen(s);
  for (int i = 0; i < len; ++i) {
    s[i] -= '0';
  }

  REP(d, 10) REP(p, MAX) {
    g[d][p] = 0;

    REP(e, p+1) {
      int ways = C[p][e];
      ways = mul(ways, pw[9-d][e]);
      ways = mul(ways, pw[d][p-e]);
      g[d][p] = add(g[d][p], mul(pw[10][e], ways));
    }
  }

  for (int i = 0; i < len; ++i) {
    for (int j = 0; j < s[i]; ++j) {
      vector<int> c(10);
      REP(k, i) c[s[k]]++;
      c[j]++;

      int rem = len - i - 1;
      REP(d, 10) {
        int gt = accumulate(c.begin() + d + 1, c.end(), 0);
        int eq = c[d];

        REP(extra_eq, rem+1) {
          int ways = C[rem][extra_eq];
          ways = mul(ways, g[d][rem - extra_eq]);
          ways = mul(ways, pw[10][gt]);
          ways = mul(ways, d);
          ways = mul(ways, sum_pw[10][eq + extra_eq]);
          ret = add(ret, ways);
        }
      }
    }
  }

  sort(s, s + len);
  reverse(s, s + len);
  REP(i, len) {
    ret = add(ret, mul(pw[10][i], s[i]));
  }

  printf("%d\n", ret);
  return 0;
}
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

const int MAX = 505;

char a[MAX];
bool e[MAX][MAX];
bool f[MAX][MAX];

int main(void) {
  int n, m;
  scanf("%d %d", &n, &m);
  REP(i, m) {
    int u, v;
    scanf("%d %d", &u, &v); --u, --v;
    e[u][v] = e[v][u] = true;
  }

  
  REP(i, n) {
    e[i][i] = true;
    bool all = true;
    REP(j, n) all &= e[i][j];
    if (all) {
      a[i] = 'b';
      continue;
    }

    bool ok = false;
    REP(j, i) {
      if (e[i][j] && a[j] != 'b') {
        a[i] = a[j];
        ok = true;
        break;
      }
      if (!e[i][j]) {
        a[i] = a[j] ^ 'a' ^ 'c';
        ok = true;
        break;
      }
    }

    if (!ok) a[i] = 'a';
  }

  a[n] = '\0';
  REP(i, n) REP(j, n) {
    bool expected = (a[i] == 'a' && a[j] == 'c') || (a[i] == 'c' && a[j] == 'a');
    if (expected != !e[i][j]) {
      puts("No");
      return 0;
    }
  }

  puts("Yes");
  puts(a);
  return 0;
}
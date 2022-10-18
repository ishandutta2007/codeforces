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

const int MAX = 1000100;

int ans[MAX];

int main(void) {
  int n, q;
  scanf("%d %d", &n, &q);

  int e = 0;
  int o = 0;
  REP(i, q) {
    int t;
    scanf("%d", &t);
    
    if (t == 1) {
      int x;
      scanf("%d", &x);
      x = ((x % n) + n) % n;
      e = (e + x) % n;
      o = (o + x) % n;
    }

    if (t == 2) {
      if (e % 2 == 0) {
        e = (e + 1) % n;
        o = (o - 1 + n) % n;
      } else {
        e = (e - 1 + n) % n;
        o = (o + 1) % n;
      }
    }
  }

  REP(i, n) {
    if (i % 2 == 0) ans[((i + e) % n)] = i + 1;
    else ans[((i + o) % n)] = i + 1;
  }
  REP(i, n) printf("%d ", ans[i]);
  printf("\n");
  return 0;
}
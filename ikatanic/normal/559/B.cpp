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

const int MAX = 222222;

char a[MAX], b[MAX];

void canonize(char *a, int n) {
  if (n % 2) return;
  int m = n / 2;
  
  canonize(a, m);
  canonize(a + m, m);

  bool lt = false;
  REP(i, m)
    if (a[i] != a[m + i]) {
      lt = a[i] < a[m + i];
      break;
    }
  if (lt) {
    REP(i, m) swap(a[i], a[m + i]);
  }
}

int main(void) {
  scanf("%s", a);
  scanf("%s", b);
  
  int n = strlen(a);
  canonize(a, n);
  canonize(b, n);

  puts(strcmp(a, b) ? "NO" : "YES");
  return 0;
}
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

const int MAXN = 100010;

char s[MAXN];
int ans[MAXN];

int main(void) {
  scanf("%s", s);
  int last = -1;
  int n = strlen(s);
  REP(i, n)
    if (s[i] == '#') last = i;
 
  int bal = 0;
  REP(i, n) {
    if (s[i] == '(') bal++; else
      if (s[i] == ')') bal--; else {
        ans[i] = 1;
        bal--;
      }
    if (bal < 0) { puts("-1"); return 0; }
  }

  if (last != -1) ans[last] += bal;

  bal = 0;
  REP(i, n) {
    if (s[i] == '(') bal++; else
      if (s[i] == ')') bal--; else
        bal -= ans[i];
    if (bal < 0) { puts("-1"); return 0; }
  }
  if (bal != 0) { puts("-1"); return 0; }

  REP(i, n)
    if (s[i] == '#') printf("%d\n", ans[i]);
  return 0;
}
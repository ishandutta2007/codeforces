#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <cstdio>
#include <map>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

char s[100010];
map<char, int> M;

int main(void) {
  int n;
  scanf("%d", &n);
  scanf("%s", s);
  REP(i, n) M[s[i]]++;

  int m = -1, c = 0;
  for (auto &p: M) {
    if (p.second > m) m = p.second, c = 0;
    if (p.second == m) c++;
  }

  int ans = 1;
  REP(i, n) ans = (ans * llint(c)) % int(1e9 + 7);
  printf("%d\n", ans);
  return 0;
}
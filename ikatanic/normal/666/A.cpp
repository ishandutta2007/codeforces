#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <cstdio>
#include <set>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

const int MAX = 111111;

bool f[MAX][4];
char s[MAX];

int main(void) {
  scanf("%s", s);

  string a = s;
  int n = a.size();
  f[n][2] = f[n][3] = true;

  set<string> S;
  for (int i = n-1; i > 4; --i) {
    for (int l : {2, 3}) {
      if (i + l > (int)a.size()) continue;
      
      for (int p: {2, 3}) {
        if (i + l + p <= (int)a.size() && a.substr(i, l) == a.substr(i + l, p)) continue;
        f[i][l] |= f[i + l][p];
      }
      if (f[i][l]) S.insert(a.substr(i, l));
    }
  }

  printf("%d\n", (int)S.size());
  for (auto& s: S) puts(s.c_str());
  return 0;
}
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

vector<string> v = {"vaporeon", "jolteon", "flareon", "espeon", "umbreon", "leafeon", "glaceon", "sylveon"};

int main(void) {
  int n;
  char a[100];

  scanf("%d", &n);
  scanf("%s", a);
  
  for (string s: v)
    if (n == s.size()) {
      bool ok = true;
      REP(i, n)
        if (a[i] == '.' || a[i] == s[i]); else
          ok = false;
      if (ok) puts(s.c_str());
    }
  return 0;
}
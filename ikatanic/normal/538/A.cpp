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

int main(void) {
  char buff[111];
  scanf("%s", buff);
  
  string s = buff;
  for (int i = 0; i <= (int)s.size(); ++i)
    for (int l = 0; i+l <= (int)s.size(); ++l)
      if (s.substr(0, i) + s.substr(i + l) == "CODEFORCES") {
        puts("YES");
        return 0;
      }

  puts("NO");
  return 0;
}
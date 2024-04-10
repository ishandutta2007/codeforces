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

int main(void) {
  char s[55];
  scanf("%s", s);
  int len = strlen(s);
  int ans = 0;
  REP(i, len) {
    if (isdigit(s[i])) {
      if ((s[i] - '0') % 2) {
        ans++;
      }
    } else {
      if (s[i] == 'a' || s[i] == 'e' || s[i] == 'i' || s[i] == 'o' || s[i] == 'u') {
        ans++;
      }
    }
  }

  printf("%d\n", ans);
  return 0;
}
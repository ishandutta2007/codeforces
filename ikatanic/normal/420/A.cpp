#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>

using namespace std;

#define TRACE(x) cout << #x << " = " << x << endl
#define REP(i, n) for (int i = 0; i < (n); ++i)

typedef long long llint;

string ok = "AHIMOTUVWXY";
char s[100010];

int main(void) {
  scanf("%s", s);
  bool ans = true;
  int n = strlen(s);
  REP(i, n) {
    if (s[i] != s[n-i-1]) { ans = false; break; }
    bool ima = false;
    for (char c: ok)
      if (s[i] == c) ima = true;
    if (!ima) { ans = false; break; }
  }

  if (ans) puts("YES"); else
    puts("NO");

  return 0;
}
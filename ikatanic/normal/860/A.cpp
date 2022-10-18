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

char s[3333];

int main(void) {
  scanf("%s", s);

  int n = strlen(s);
  int i = 0;
  while (i < n) {
    int j = i;
    int cons = 0;
    while (j < n) {
      if (s[j] == 'a' || s[j] == 'e' || s[j] == 'i' || s[j] == 'o' || s[j] == 'u') { j++; cons = 0; continue; }

      if (cons >= 2 && (s[j] != s[j - 1] || s[j] != s[j - 2])) break;
      cons++;
      j++;
    }

    FOR(x, i, j) putchar(s[x]);
    putchar(' ');
    i = j;
  }
  printf("\n");
  return 0;
}
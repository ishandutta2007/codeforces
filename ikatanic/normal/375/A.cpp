#include <algorithm>

#include <cassert>
#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <string>
#include <vector>
#include <iostream>

using namespace std;

#define TRACE(x) cout << #x << " = " << x << endl
#define REP(i, n) for (int i = 0; i < (n); ++i)

typedef long long llint;

int a[4] = {1, 6, 8, 9};
int c[10];
char s[1000100];

int main(void)
{
  scanf("%s", s);
  int l = strlen(s);
  
  int w = 0;
  REP(j, l) {
    s[j] -= '0';
    if (s[j] != 1 && s[j] != 6 && s[j] != 8 && s[j] != 9) s[w++] = s[j]; else
      c[s[j]]++;
  }

  REP(i, 10)
    while (c[i] > 1) s[w++] = i, c[i]--;
  
  int p = 1, m = 0;
  REP(i, w) {
    m = (m + p*s[i])%7;
    p = (p*10)%7;
  }

  int a[4] = {1, 6, 8, 9};
  do {
    int c = p, sm = 0;
    REP(i, 4) {
      sm += c*a[i];
      c *= 10;
    }
    
    if ((sm+m)%7 == 0) {
      REP(i, 4)
        s[w++] = a[i];
      break;
    }
  } while (next_permutation(a, a+4));

  if (w != l) printf("0"); else {
    reverse(s, s + l);
    REP(i, l) printf("%c", s[i]+'0');
  }
  printf("\n");
  return 0;
}
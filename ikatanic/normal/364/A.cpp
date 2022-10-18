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

const int MAXN = 4004;

char s[MAXN];
int c[MAXN*10];

int main(void) {
  int a;
  scanf("%d", &a);
  scanf("%s", s);

  int n = strlen(s);
  REP(i, n) {
    int sum = 0;
    for (int j = i; j >= 0; --j) {
      sum += s[j]-'0';
      c[sum]++;
    }
  }

  llint ans = 0;
  if (a == 0) {
    REP(i, 10*n)
      ans += llint(c[i])*c[0]*(1 + (i != 0));
  } else
    for (int i = 1; i < 10*n; ++i)
      if (a%i == 0)
        if (c[i] && (a/i) < 10*n)
          ans += llint(c[i])*c[a/i];
  cout << ans << endl;
  return 0;
}
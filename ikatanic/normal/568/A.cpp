#include <algorithm>
#include <cassert>
#include <cstring>
#include <iostream>
#include <cstdio>
#include <string>

using namespace std;

#define FOR(i, a, b) for (int i = (a); i < (b); ++i)
#define REP(i, n) FOR(i, 0, n)
#define TRACE(x) cout << #x << " = " << x << endl
#define _ << " _ " <<

typedef long long llint;

const int MAX = 1e7;

int c[MAX];

int main(void) {
  c[1] = 1;
  for (int i = 2; i*i < MAX; ++i)
    if (!c[i])
      for (int j = i*i; j < MAX; j += i)
        c[j] = i;

  int p, q;
  scanf("%d %d", &p, &q);

  int pi = 0, rub = 0;
  int ans = -1;
  FOR(n, 1, MAX) {
    pi += !c[n];
    
    int y = 0, x = n;
    while (x) {
      y = y*10 + (x%10);
      x /= 10;
    }

    rub += n == y;
    
    if (pi*1LL*q <= p*1LL*rub) ans = n;
  }

  if (ans == -1) puts("Palindromic tree is better than splay tree"); else
    printf("%d\n", ans);
  return 0;
}
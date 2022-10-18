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

int a[303];
int n;

int main(void)
{
  scanf("%d", &n);
  int s = 0;
  REP(i, n) {
    scanf("%d", a+i);
    s += a[i];
  }

  int pos = 0, d = +1;
  while (s > 0) {
    if (a[pos] > 0) putchar('P'), a[pos]--, s--;
    if (d == +1 && pos == n-1) putchar('L'), putchar('R'), d = -1; else
      if (d == -1 && pos == 0) putchar('R'), putchar('L'), d = +1; else
        putchar(d == +1 ? 'R' : 'L'), pos += d;
  }
  
  return 0;
}
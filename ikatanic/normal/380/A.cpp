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

const int MAXN = 100100;

int a[MAXN];
int tip[MAXN], x[MAXN];
llint first[MAXN];

int main(void)
{
  int m;
  scanf("%d", &m);

  int n = 0;
  llint len = 0;
  REP(i, m) {
    scanf("%d", tip+i);
    
    first[i] = len;
    if (tip[i] == 1) {
      scanf("%d", x+i);
      if (n < MAXN) a[n++] = x[i];
      len++;
    } else {
      int c;
      scanf("%d %d", x+i, &c);
      for (int j = 0; j < c && n < MAXN; ++j)
        for (int k = 0; k < x[i] && n < MAXN; ++k)
          a[n++] = a[k];
      len += x[i]*c;
    }
  }
  
  int q;
  scanf("%d", &q);
  REP(i, q) {
    llint pos;
    scanf("%I64d", &pos); --pos;
    
    int j = (upper_bound(first, first + m, pos) - first) - 1;
    if (tip[j] == 1) printf("%d", x[j]); else
      printf("%d", a[(pos-first[j])%x[j]]);
    printf("%c", i+1 == q ? '\n' : ' ');
  }

  return 0;
}
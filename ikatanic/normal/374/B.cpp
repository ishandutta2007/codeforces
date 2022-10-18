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

const int MAXN = 100010;

char a[MAXN];
int f[MAXN];
llint w[MAXN];

int main(void) {
  scanf("%s", a);
  
  int n = strlen(a);
  f[n] = 0, w[n] = 1;
  for (int i = n-1; i >= 0; --i) {
    f[i] = f[i+1];
    w[i] = w[i+1];
    if (i+1 < n && a[i]-'0'+a[i+1] == '9' && f[i+2]+1 >= f[i]) {
      f[i] = f[i+2]+1;
      if (f[i+2]+1 == f[i+1]) w[i] += w[i+2]; else
        w[i] = w[i+2];
    }
  }

  printf("%I64d\n", w[0]);
  return 0;
}
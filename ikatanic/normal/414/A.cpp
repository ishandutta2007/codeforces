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

int a[100100];

int main(void) {
  int n, k;
  scanf("%d %d", &n, &k);
  
  if (n == 1 || k == 0) {
    printf("%d\n", (n == 1 && k == 0) ? 1 : -1);
    return 0;
  }

  int m = n/2;
  int r = k - (m - 1);
  
  if (r <= 0) {
    puts("-1");
    return 0;
  }

  int p = 0;
  a[p] = r, a[1] = 2*r, p += 2;

  for (int i = 2; p < n; i += 2)
    if (i != a[0] && i != a[1] && i-1 != a[0] && i-1 != a[1])
      a[p] = i, a[p+1] = i-1, p += 2;
    
  REP(i, n)
    printf("%d%c", a[i], i == n-1 ? '\n' : ' ');
  
  return 0;
}
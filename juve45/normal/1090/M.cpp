#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
using namespace std;

const int N = 1000005;

int i, n, k, a[N], len, rs;

int main() {
  scanf("%d %d", &n, &k);
  for(i = 0; i < n; ++i) scanf("%d", a + i);
  for(i = 0; i < n; ++i, rs = max(rs, len))
    if(i && a[i] == a[i - 1]) len = 1;
    else ++len;
  printf("%d\n", rs);
  return 0;
}
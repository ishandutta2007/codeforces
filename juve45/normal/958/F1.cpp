#pragma GCC optimize("Ofast,unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
using namespace std;

const int N = 105;

int i, n, m, a[N], k[N], sm, freq[N];

bool check(int x) {
  memset(freq, 0, sizeof(freq));
  for(int i = 1; i <= m; ++i)
    for(int j = 1; j <= k[i]; ++j, ++x) {
      if(a[x] == -1) i = m + 1, j = 1e9;
      if(a[x] == -1) break;
      ++freq[a[x]];
    }
  for(int i = 1; i <= m; ++i) if(freq[i] != k[i]) return 0;
  return 1;
}

int main() {
  scanf("%d %d", &n, &m);
  for(i = 1; i <= n; ++i) scanf("%d", a + i);
  for(i = 1; i <= m; ++i) scanf("%d", k + i), sm += k[i];

  for(i = 1; i <= n; ++i) if(check(i)) return 0 * puts("YES");
  puts("NO");

  return 0;
}
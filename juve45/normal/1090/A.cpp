#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int i, n, m, mx, x;
long long rs;
vector<int> a[N];

int main() {
  scanf("%d", &n);
  for(i = 1; i <= n; ++i)
    for(scanf("%d", &m); m; --m) {
      scanf("%d", &x);
      a[i].push_back(x);
      mx = max(mx, x);
    }

  for(i = 1; i <= n; ++i) rs += 1LL * (mx - *max_element(a[i].begin(), a[i].end())) * a[i].size();

  printf("%lld\n", rs);

  return 0;
}
#pragma GCC optimize("Ofast")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>
using namespace std;

const int N = 200005;

int i, n, k, a[N], b[N], used[N];
long long ans;
multiset<int> S;

int main() {
  scanf("%d %d", &n, &k);
  for(i = 1; i <= n; ++i) scanf("%d", a + i);
  for(i = 1; i <= n; ++i) scanf("%d", b + i);

  for(i = 1; i <= n; ++i) used[a[i]] = max(used[a[i]], b[i]);

  for(i = 1; i <= n; ++i)
    if(used[a[i]] == b[i]) used[a[i]] = -1, --k;
    else S.insert(b[i]);

  while(k--) {
    ans += *S.begin();
    S.erase(S.begin());
  }

  printf("%lld\n", ans);

  return 0;
}
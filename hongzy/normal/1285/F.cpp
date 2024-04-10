#include <bits/stdc++.h>
#define pb push_back
#define LOG(FMT...) fprintf(stderr, FMT);
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;
typedef long long ll;
const int N = 1e5 + 10;
int n, m, a[N], mu[N], st[N], top, cnt[N];
vector<int> vec[N];
bool vis[N];
int gcd(int a, int b) {
  return !b ? a : gcd(b, a % b);
}
int main() {
  scanf("%d", &n);
  rep(i, 1, n) scanf("%d", a + i), m = max(m, a[i]), vis[a[i]] = 1;
  mu[1] = 1;
  rep(i, 1, m) for(int j = i + i; j <= m; j += i) mu[j] -= mu[i];
  rep(i, 1, m) if(mu[i]) for(int j = i; j <= m; j += i) vec[j].pb(i);
  ll ans = 1;
  per(i, m, 1) {
    bool use = 0;
    for(int j = i; j <= m; j += i) if(vis[j]) { use = 1; break ; }
    if(!use) continue ;
    int z = 0;
    for(int d : vec[i]) z += mu[d] * cnt[d];
    while(z) {
      int la = z;
      for(int d : vec[st[top]]) {
        -- cnt[d];
        if(i % d == 0) z -= mu[d];
      }
      if(la != z)
        ans = max(ans, (ll)i * st[top]);
      -- top;
    }
    st[++ top] = i;
    for(int d : vec[i]) ++ cnt[d];
  }
  printf("%lld\n", ans);
  return 0;
}
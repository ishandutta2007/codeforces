#include <bits/stdc++.h>
#define pb push_back
#define rep(i, j, k) for(int i = j; i <= k; ++ i)
#define per(i, j, k) for(int i = j; i >= k; -- i)
using namespace std;
typedef long long ll;
const int N = 2e6 + 10;
int n, c[N];
ll ans, a[N];
vector<ll> v;
template<class T>
T gcd(T a, T b) { return b ? gcd(b, a % b) : a; }
int main() {
  scanf("%d", &n);
  rep(i, 1, n) scanf("%lld", a + i);
  mt19937 mt(chrono::system_clock().now().time_since_epoch().count());
  rep(T, 1, 10) {
    int u = mt() % n + 1;
    v.clear();
    for(ll d = 1; d * d <= a[u]; d ++) if(a[u] % d == 0) {
      v.pb(d);
      if(d * d != a[u])
        v.pb(a[u] / d);
    }
    sort(v.begin(), v.end());
    fill(c, c + int(v.size()), 0);
    rep(i, 1, n) {
      c[lower_bound(v.begin(), v.end(), gcd(a[i], a[u])) - v.begin()] ++;
    }
    per(i, int(v.size()) - 1, 0) {
      int z = c[i];
      rep(j, i + 1, int(v.size()) - 1)
        if(v[j] % v[i] == 0)
          z += c[j];
      if(z * 2 >= n) { ans = max(ans, v[i]); break ; }
    }
  }
  printf("%lld\n", ans);
  return 0;
}
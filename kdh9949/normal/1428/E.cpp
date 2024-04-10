#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ld = long double;
using pii = pair<int, int>;
using pil = pair<int, ll>;
using pli = pair<ll, int>;
using pll = pair<ll, ll>;

using vint = vector<int>;
using vll = vector<ll>;
using vld = vector<ld>;
using vpii = vector<pii>;
using vpil = vector<pil>;
using vpli = vector<pli>;
using vpll = vector<pll>;

#define x first
#define y second
#define all(v) v.begin(),v.end()

int main() {
  ios::sync_with_stdio(false);
  cin.tie(nullptr);

  int n, k;
  cin >> n >> k;
  k -= n;

  vll a(n);
  for(ll &x : a) cin >> x;

  auto f = [](ll x, ll y) {
    ll a = x / y;
    ll r = x % y;
    ll s = y - r;
    return r * (a + 1) * (a + 1) + s * a * a;
  };

  vll c(n, 1);
  priority_queue<pli> pq;

  ll ans = 0;
  for(int i = 0; i < n; i++) {
    ans += f(a[i], 1);
    pq.emplace(f(a[i], 1) - f(a[i], 2), i);
  }
  
  while(k--) {
    pli t = pq.top();
    pq.pop();
    ans -= t.x;
    c[t.y]++;
    pq.emplace(f(a[t.y], c[t.y]) - f(a[t.y], c[t.y] + 1), t.y);
  }

  cout << ans << '\n';
  return 0;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  ll n, k, m, d;
  cin >> n >> k >> m >> d;
  ll best = 0;
  for (ll y = 1; y <= d; y++) {
    if ((double)k*y >= 2e18) continue;
    ll x = n/(k*(y-1)+1);
    x = min(x, m);
    if (x >= n/(y*k+1)+1) {
      assert((n/x+k-1)/k == y);
      best = max(best, x*y);
    }
  }
  cout << best << endl;
}
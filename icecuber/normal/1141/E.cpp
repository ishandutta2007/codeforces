#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  ll h, n;
  cin >> h >> n;
  vector<ll> acc(n+1,0);
  ll ans = 1e18;
  ll ma = 0;
  for (int i = 1; i <= n; i++) {
    ll d;
    cin >> d;
    acc[i] = acc[i-1]-d;
    ma = max(ma, acc[i]);
  }
  for (int i = 0; i < n; i++) {
    ll t = 1e18;
    if (acc[i] >= h) t = i;
    else if (acc[n] > 0) {
      ll k = (h-acc[i]-1)/acc[n]+1;
      t = k*n+i;
    }
    ans = min(ans, t);
  }
  if (ans == 1e18) cout << -1 << endl;
  else cout << ans << endl;
}
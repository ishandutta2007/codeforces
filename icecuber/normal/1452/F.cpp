#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, q;
  cin >> n >> q;
  vector<int> c(n);
  for (int&v : c) cin >> v;

  while (q--) {
    int t;
    cin >> t;
    if (t == 1) {
      int p, v;
      cin >> p >> v;
      c[p] = v;
    } else {
      assert(t == 2);
      int x;
      ll k;
      cin >> x >> k;
      ll sum = 0;
      for (int i = 0; i < n; i++) {
        sum += c[i]*1ll<<i;
      }
      if (sum < k) {
        cout << -1 << endl;
        continue;
      }

      ll startsum = 0, already = 0;
      for (int i = 0; i <= x; i++) {
        startsum += c[i]*1ll<<i;
        already += c[i];
      }
      k -= already;
      startsum -= already;
      if (k <= 0) {
        cout << 0 << endl;
        continue;
      }

      ll ans = 0;
      int y = n;
      for (int i = x+1; i < n; i++) {
        ll take = min(k>>(i-x), (ll)c[i]);
        startsum += (take<<i)-(take<<(i-x));
        k -= take<<(i-x);
        ans += (take<<(i-x))-take;
        if (take < c[i]) {
          y = i;
          break;
        }
      }

      if (startsum >= k) {
        ans += k;
      } else {
        assert(y < n);
        assert(k < 1ll<<y);

        ll best = 1e18;
        //for (ll i = 0; i <= k; i++) {
        for (int l = 0; l <= y-x; l++) {
          ll i = k>>l<<l;
          if ((i*1ll<<x) + startsum >= k) {
            ll cost = k-i;
            for (int j = x+1; j <= y; j++) {
              cost += ((i-1)>>(j-x))+1;
            }
            best = min(best, cost);
          }
        }
        assert(best < 1e18);
        ans += best;
      }
      cout << ans << endl;
    }
  }
}
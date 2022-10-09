// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

struct cmd {
  ll t, x;
};

ll between(ll l, ll r, ll x) {
  if (l > r) swap(l, r);
  return l <= x && x <= r;
}

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<cmd> a(n);
    map<ll, ll> xt;
    xt[0] = 0;
    for (int i=0; i<n; i++) {
      cin >> a[i].t >> a[i].x;
    }

    {
      int i = 0;
      ll x=0, t=0;
      while (i < n) {
        while (i < n && a[i].t < t) {
          i++;
        }

        if (i == n) {
          break;
        }

        t = a[i].t;
        xt[t] = x;
        t += abs(x - a[i].x);
        x = a[i].x;
        xt[t] = x;
        i++;
      }
    }

    for (int i=0; i<n; i++) {
      auto it = xt.lower_bound(a[i].t);
      if (it->first == a[i].t) {
        continue;
      }

      ll t0 = prev(it)->first;
      // ll t1 = it->first;

      ll x0 = prev(it)->second;
      ll x1 = it->second;

      ll xx;
      if (x0 < x1) {
        xx = x0 + a[i].t - t0;
      } else if (x0 > x1) {
        xx = x0 - a[i].t + t0;
      } else {
        xx = x0;
      }

      xt[a[i].t] = xx;
    }

    ll ans = 0;

    for (int i=0; i<n; i++) {
      // ll tl = a[i].t;
      ll tr = i+1 == n ? 321321321321ll : a[i+1].t;

      auto it = xt.lower_bound(a[i].t);
      while (1) {

        if (next(it) == xt.end()) {
          if (it->second == a[i].x) {
            ans++;
          }
          break;
        }

        if (next(it)->first > tr) {
          break;
        }

        if (between(it->second, next(it)->second, a[i].x)) {
          ans++;
          break;
        }

        ++it;
      }
    }

    cout << ans << '\n';
  }
}
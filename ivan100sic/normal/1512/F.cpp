// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

ll n, c, a[200005], b[200005];

ll cd(ll x, ll y) {
  return (x + y - 1) / y;
}

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  ll t;
  cin >> t;
  while (t--) {
    cin >> n >> c;
    for (int i=0; i<n; i++) {
      cin >> a[i];
    }
    for (int i=0; i<n-1; i++) {
      cin >> b[i];
    }

    ll vr = 0, sol = 2e18, pare = 0;
    for (ll i=0; i<n; i++) {
      // ostani ovde do kraja
      sol = min(sol, vr + cd(c - pare, a[i]));
      // iznapreduj
      if (i < n-1) {
        int tn = pare >= b[i] ? 0ll : cd(b[i] - pare, a[i]);
        vr += tn + 1;
        pare += (a[i]) * tn - b[i];
      }
    }

    cout << sol << '\n';
  }
}
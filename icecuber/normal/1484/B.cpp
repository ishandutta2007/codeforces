#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    vector<ll> a(n), d;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      if (i)
        d.push_back(a[i]-a[i-1]);
    }
    ll m = 0;
    for (ll i : d) m = gcd(m,i-d[0]);

    int ok = 1;
    for (ll i : a) ok &= (i < m);

    if (m == 0) {
      cout << 0 << endl;
    } else if (!ok) {
      cout << -1 << endl;
    } else {
      cout << m << ' ' << ((a[1]-a[0])%m+m)%m << endl;
    }
  }
}
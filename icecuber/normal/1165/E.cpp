#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll mod = 998244353;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<ll> a(n),b(n);
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    a[i] *= (i+1)*ll(n-i);
  }
  for (ll&v : b) cin >> v;
  sort(a.begin(), a.end());
  sort(b.rbegin(), b.rend());
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    (ans += a[i]%mod*b[i]) %= mod;
  }
  cout << ans << endl;
}
// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

ll sum(ll n) {
  ll z = n;
  for (ll x=10; x<=n; x*=10) {
    z += n / x;
  }
  return z;
}

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  int t;
  cin >> t;
  while (t--) {
    ll a, b;
    cin >> a >> b;
    cout << sum(b) - sum(a) << '\n';
  }
}
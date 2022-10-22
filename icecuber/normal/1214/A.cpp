#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  ll n, d, e;
  cin >> n >> d >> e;
  e *= 5;
  ll ans = n;
  for (ll i = 0; i <= e; i++) {
    ll left = n-i*d;
    if (left < 0) continue;
    ans = min(ans, left%e);
  }
  cout << ans << endl;
}
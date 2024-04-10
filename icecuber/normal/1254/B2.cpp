#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<ll> a(n);
  ll sum = 0;
  for (ll&v : a) {
    cin >> v;
    sum += v;
  }
  if (sum == 1) {
    cout << -1 << endl;
    return 0;
  }

  vector<ll> p;
  for (ll i = 2; i*i <= sum; i++) {
    if (sum%i) continue;
    p.push_back(i);
    while (sum%i == 0) {
      sum /= i;
    }
  }
  if (sum > 1) p.push_back(sum);

  ll ans = sum*n;
  for (ll d : p) {
    ll r = 0, need = 0;
    for (int i = 0; i < n; i++) {
      (r += a[i]) %= d;
      need += min(r,d-r);
    }
    ans = min(ans, need);
  }
  cout << ans << endl;
}
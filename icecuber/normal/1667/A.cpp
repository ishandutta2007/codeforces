#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<ll> a(n);
  for (ll&v : a) cin >> v;
  ll ans = 1e18;
  for (int i = 0; i < n; i++) {
    ll need = 0;
    ll p = 0;
    for (int j = i+1; j < n; j++) {
      ll x = p/a[j]+1;
      need += x;
      p = x*a[j];
    }
    p = 0;
    for (int j = i-1; j >= 0; j--) {
      ll x = p/a[j]+1;
      need += x;
      p = x*a[j];
    }
    ans = min(ans, need);
  }
  cout << ans << endl;
}
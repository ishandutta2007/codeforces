#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    ll n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (ll&v : a) cin >> v;
    for (int it = 0; it < min(k, k%2+4); it++) {
      ll d = *max_element(a.begin(), a.end());
      for (ll&v : a) v = d-v;
    }
    for (ll v : a) cout << v << ' ';
    cout << endl;
  }
}
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
    vector<ll> a(n);
    for (ll&v : a) cin >> v;
    vector<ll> ans = {a[0]};
    for (int i = 1; i < n; i++) {
      if ((a[i] > 0) == (ans.back() > 0)) ans.back() = max(ans.back(), a[i]);
      else ans.push_back(a[i]);
    }
    ll sum = 0;
    for (ll v : ans) sum += v;
    cout << sum << endl;
  }
}
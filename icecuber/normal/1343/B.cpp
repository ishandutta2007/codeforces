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
    if (n/2%2) {
      cout << "NO" << endl;
      continue;
    }
    cout << "YES" << endl;
    vector<ll> ans(n);
    ll m = n+10;
    for (int i = 0; i < n/4; i++) {
      ans[i] = m-(i+1)*2;
      ans[i+n/2] = m-(i+1)*2-1;
      ans[i+n/4] = m+(i+1)*2;
      ans[i+n/2+n/4] = m+(i+1)*2+1;
    }
    for (ll v : ans) cout << v << ' ';
    cout << endl;
  }
}
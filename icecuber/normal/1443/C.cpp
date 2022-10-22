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
    vector<array<ll,2>> a(n);
    for (int i = 0; i < n; i++) cin >> a[i][0];
    for (int i = 0; i < n; i++) cin >> a[i][1];
    sort(a.begin(), a.end());
    ll sum = 0;
    ll ans = 1e18;
    for (int i = n-1; i >= 0; i--) {
      ans = min(ans, max(a[i][0], sum));
      sum += a[i][1];
    }
    cout << min(ans,sum) << endl;
  }
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    vector<ll> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      a[i] += i;
    }
    sort(a.begin(), a.end());
    ll ans = -ll(n-k)*(n-k-1)/2;
    for (int i = 0; i < n-k; i++) {
      ans += a[i];
    }
    cout << ans << endl;
  }
}
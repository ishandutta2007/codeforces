#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll a[100000];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  ll n, k;
  cin >> n >> k;
  ll mi = 1e9;
  for (int i = 0; i < n; i++) {
    cin >> a[i];
    mi = min(mi, a[i]);
  }
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    ll v = a[i]-mi;
    if (v%k) {
      cout << -1 << endl;
    return 0;
    }
    ans += v/k;
  }
  cout << ans << endl;
}
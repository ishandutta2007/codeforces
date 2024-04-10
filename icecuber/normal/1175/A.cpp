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
    ll ans = 0;
    while (n) {
      ans += n%k+!!(n/k);
      n /= k;
    }
    cout << ans << endl;
  }
}
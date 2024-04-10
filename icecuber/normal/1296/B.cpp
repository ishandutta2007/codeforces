#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    ll n;
    cin >> n;
    ll ans = 0;
    while (n >= 10) {
      ll v = n/10;
      ans += v*10;
      n %= 10;
      n += v;
    }
    ans += n;
    cout << ans << endl;
  }
}
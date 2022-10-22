#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    ll n, r;
    cin >> n >> r;
    ll m = min(n,r+1);
    ll ans = (n <= r) + m*(m-1)/2;
    cout << ans << endl;
  }
}
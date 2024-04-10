#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  ll a, b;
  cin >> a >> b;
  ll ans = 1;
  for (ll x = a+1; x <= b && ans; x++) {
    ans = ans*(x%10)%10;
  }
  cout << ans << endl;
}
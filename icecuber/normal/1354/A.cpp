#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    if (b >= a) {
      cout << b << endl;
    } else if (d >= c) {
      cout << -1 << endl;
    } else {
      ll q = c-d;
      ll k = (a-b+q-1)/q;
      cout << b+k*c << endl;
    }
  }
}
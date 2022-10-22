#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    ll x, y;
    cin >> x >> y;
    ll n;
    if (y < x) {
      n = x+y;
    } else if (x == y) {
      n = x;
    } else if (x*2 >= y) {
      n = (y+x)/2;
    } else if (y > x) {
      n = y-y/2%x;
    } else assert(0);
    cout << n << endl;
    assert(n%x == y%n);
  }
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  int t;
  cin >> t;
  while (t--) {
    ll a, b, c;
    cin >> a >> b >> c;
    ll ma = max({a,b,c});
    ll sum = a+b+c;
    if (sum-ma < ma) {
      cout << sum-ma << endl;
    } else {
      cout << sum/2 << endl;
    }
  }
}
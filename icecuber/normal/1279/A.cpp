#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    ll a, b, c;
    cin >> a >> b >> c;
    ll ma = max({a, b, c});
    ll sum = a+b+c;
    cout << (ma <= sum-ma+1 ? "Yes" : "No") << endl;
  }
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    ll sum = 0, twos = 0, ma = 0;
    for (int i = 0; i < n; i++) {
      int v;
      cin >> v;
      while (v%2 == 0) twos++, v /= 2;
      sum += v;
      ma = max(ma, ll(v));
    }
    cout << sum-ma+ma*(1ll<<twos) << endl;
  }
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    ll sum = 0, xor_sum = 0;
    for (int i = 0; i < n; i++) {
      int a;
      cin >> a;
      sum += a;
      xor_sum ^= a;
    }
    ll c = (1ll<<55);
    if (sum%2)
      c++;

    sum += c;
    xor_sum ^= c;

    ll d = xor_sum*2-sum;
    cout << 3 << endl;
    cout << d/2 << ' ' << d/2 << ' ' << c << endl;
    assert((xor_sum^d/2^d/2)*2 == sum+d/2+d/2);
  }
}
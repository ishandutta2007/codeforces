#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int q;
  cin >> q;
  while (q--) {
    ll l, r, d;
    cin >> l >> r >> d;
    if (d >= l && d <= r)
      cout << (r+d)/d*d << endl;
    else cout << d << endl;
  }
}
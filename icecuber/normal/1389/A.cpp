#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int l, r;
    cin >> l >> r;
    if (r < l*2) cout << "-1 -1" << endl;
    else cout << l << ' ' << l*2 << endl;
  }
}
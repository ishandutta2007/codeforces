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
    ll mi = 1e18, mi2 = 1e18, ma = -1e18;
    ll acc = 0;
    for (int i = 0; i < n; i++) {
      int a;
      cin >> a;
      mi = min(mi, acc);
      if (i)
	mi2 = min(mi2, acc);
      acc += a;
      if (i < n-1)
	ma = max(ma, acc-mi);
      ma = max(ma, acc-mi2);
    }
    cout << (ma < acc ? "YES" : "NO") << '\n';
  }
}
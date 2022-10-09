// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  int t;
  cin >> t;
  while (t--) {
    int n, l, r;
    ll z = 0;
    cin >> n >> l >> r;
    vector<int> a(n);
    for (int& x : a) cin >> x;
    sort(begin(a), end(a));
    for (int i=0; i<n; i++) {
      auto lo = lower_bound(a.begin()+i+1, a.end(), l - a[i]);
      auto hi = upper_bound(a.begin()+i+1, a.end(), r - a[i]);
      z += hi - lo;
    }
    cout << z << '\n';
  }
}
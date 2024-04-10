#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, x, m;
    cin >> n >> x >> m;
    int l = x, r = x;
    while (m--) {
      int nl, nr;
      cin >> nl >> nr;
      if (nr >= l && nl <= r) {
	r = max(r, nr);
	l = min(l, nl);
      }
    }
    cout << (r-l+1) << endl;
  }
}
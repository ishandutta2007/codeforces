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
    vector<int> a(n),b(n);
    for (int&v : a) cin >> v;
    for (int&v : b) cin >> v;
    int diff = 0, state = 0, ok = 1;
    for (int i = 0; i < n; i++) {
      if (state == 0) {
	if (b[i]-a[i] != 0) {
	  diff = b[i]-a[i];
	  if (diff <= 0) ok = 0;
	  state = 1;
	}
      } else if (state == 1) {
	if (b[i]-a[i] != diff) {
	  if (b[i] == a[i]) {
	    state = 2;
	  } else ok = 0;
	}
      } else if (state == 2) {
	if (b[i]-a[i]) ok = 0;
      }
    }
    cout << (ok ? "YES" : "NO") << '\n';
  }
}
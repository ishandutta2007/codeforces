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
    vector<int> p(n);
    for (int&v : p) {
      cin >> v;
      v--;
    }
    vector<int> c(n);
    for (int&v : c) {
      cin >> v;
      v--;
    }
    vector<int> done(n);
    int ans = n;
    for (int i = 0; i < n; i++) {
      if (done[i]) continue;
      vector<int> cols;
      int x = i;
      while (!done[x]) {
	done[x] = 1;
	cols.push_back(c[x]);
	x = p[x];
      }
      int k = cols.size();
      for (int m = 1; m <= k; m++) {
	if (k%m) continue;
	for (int r = 0; r < m; r++) {
	  int ok = 1;
	  for (int j = r+m; j < k; j += m)
	    if (cols[j] != cols[r]) ok = 0;
	  if (ok) ans = min(ans, m);
	}
      }
    }
    cout << ans << endl;
  }
}
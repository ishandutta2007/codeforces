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
    vector<int> a(n);
    for (int&v : a) cin >> v;
    int mi = 1e9, ma = -1e9;
    for (int i = 0; i+1 < n; i++) {
      if (a[i] == a[i+1]) {
        mi = min(mi, i);
        ma = max(ma, i);
      }
    }
    if (mi == 1e9 || mi == ma) {
      cout << 0 << endl;
    } else {
      cout << max(ma-mi-1, 1) << endl;
    }
  }
}
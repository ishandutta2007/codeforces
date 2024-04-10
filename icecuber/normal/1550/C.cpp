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
    int ans = 0;
    for (int i = 0; i < n; i++) {
      for (int l = 1; l <= 4 && i+l <= n; l++) {
        int ok = 1;
        for (int m = 0; m < 1<<l; m++) {
          if (__builtin_popcount(m) != 3) continue;
          vector<int> b;
          for (int j = 0; j < l; j++)
            if (m>>j&1) b.push_back(a[i+j]);
          ok &= ll(b[0]-b[1])*(b[2]-b[1]) > 0;
        }
        ans += ok;
      }
    }
    cout << ans << endl;
  }
}
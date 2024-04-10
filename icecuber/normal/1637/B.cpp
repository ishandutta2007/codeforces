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
    for (int l = 0; l < n; l++) {
      for (int r = 1; r <= n; r++) {
        for (int i = l; i < r; i++) 
          ans += 1+(a[i]==0);
      }
    }
    cout << ans << endl;
  }
}
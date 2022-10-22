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
    for (int s = 0; s < n; s++) {
      if (s && a[s-1] == a[s]) continue;
      int len = upper_bound(a.begin(), a.end(), a[s])-a.begin()-s;
      int d = 1;
      while (1) {
        int q = lower_bound(a.begin(), a.end(), a[s]+d)-a.begin();
        if (q == n) break;
        d = (a[q]-a[s])*2;
        len++;
      }
      ans = max(ans, len);
    }
    cout << n-ans << endl;
  }
}
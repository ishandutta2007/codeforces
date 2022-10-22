#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int&v : a) cin >> v;
    sort(a.rbegin(), a.rend());
    vector<int> w(k);
    for (int&v : w) cin >> v;
    sort(w.begin(), w.end());
    ll ans = 0;
    for (int i = 0; i < k; i++) {
      ans += a[i];
      if (w[i] == 1) ans += a[i];
    }
    int i = k;
    for (int wj : w) {
      i += wj-1;
      if (wj > 1) {
	ans += a[i-1];
      }
    }
    cout << ans << endl;
  }
}
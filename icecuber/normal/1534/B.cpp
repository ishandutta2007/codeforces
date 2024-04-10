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
    vector<int> a(n);
    for (int&v : a) cin >> v;
    a.insert(a.begin(), 0);
    a.push_back(0);
    n += 2;
    ll ans = 0;
    for (int i = 1; i+1 < n; i++) {
      if (a[i] > a[i-1] && a[i] > a[i+1]) {
        int nv = max(a[i-1], a[i+1]);
        ans += a[i]-nv;
        a[i] = nv;
      }
    }
    for (int i = 1; i < n; i++) {
      ans += abs(a[i]-a[i-1]);
    }
    cout << ans << endl;
  }
}
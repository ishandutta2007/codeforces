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
    vector<int> a(n), b(n);
    for (int&v : a) cin >> v;
    for (int&v : b) cin >> v;
    sort(a.begin(), a.end());
    sort(b.rbegin(), b.rend());
    int ans = 0;
    for (int i = 0; i < k; i++) {
      if (b[i] > a[i]) swap(a[i],b[i]);
    }
    for (int i = 0; i < n; i++) {
      ans += a[i];
    }
    cout << ans << endl;
  }
}
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
    ll d = 0;
    for (int i = 1; i < n; i++) {
      if (a[i]<a[i-1])
        d += a[i-1]-a[i];
    }
    cout << (d <= a[0] ? "YES" : "NO") << endl;
  }
}
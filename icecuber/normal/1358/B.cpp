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
    for (int i = 0; i < n; i++) {
      cin >> a[i];
    }
    sort(a.begin(), a.end());
    int ans = 1;
    int has = 1;
    for (int i = 0; i < n; i++) {
      if (has >= a[i]) ans = i+2;
      has++;
    }
    cout << ans << endl;
  }
}
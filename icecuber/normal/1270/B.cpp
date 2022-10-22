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
    for (int i = 0; i < n; i++) cin >> a[i];
    int l = -1, r = -1;
    for (int i = 1; i < n; i++) {
      if (abs(a[i]-a[i-1]) >= 2) {
	l = i-1, r = i;
      }
    }
    if (l == -1)
      cout << "NO" << endl;
    else {
      cout << "YES" << endl;
      cout << l+1 << ' ' << r+1 << endl;
    }
  }
}
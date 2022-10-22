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
    vector<int> p(n);
    for (int i = 0; i < n; i++) {
      cin >> p[i];
    }
    int ans = -1;
    for (int i = 1; i+1 < n; i++) {
      if (p[i-1] < p[i] && p[i] > p[i+1]) {
	ans = i;
      }
    }
    if (ans == -1) {
      cout << "NO" << endl;
    } else {
      cout << "YES" << endl;
      cout << ans << ' ' << ans+1 << ' ' << ans+2 << endl;
    }
  }
}
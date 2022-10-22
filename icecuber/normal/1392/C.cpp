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
    ll ans = 0, last = 0;
    for (int i = 0; i < n; i++) {
      int a;
      cin >> a;
      if (i && a < last)
	ans += last-a;
      last = a;
    }
    cout << ans << endl;
  }
}
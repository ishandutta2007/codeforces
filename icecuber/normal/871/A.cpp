#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  set<int> bad = {1,2,3,5,7,11};
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    if (bad.count(n)) cout << -1 << '\n';
    else {
      int ans = 0;
      if (n%2) ans++, n -= 9;
      if (n/2%2) ans++, n -= 6;
      ans += n/4;
      cout << ans << '\n';
    }
  }
}
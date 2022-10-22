#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  map<pair<int,int>,int> m;
  int best = 0;
  int ans = 0;
  int n;
  cin >> n;
  vector<int> a(n),b(n);
  for (int&i : a) cin >> i;
  for (int&i : b) cin >> i;
  for (int i = 0; i < n; i++) {
    if (a[i] == 0) ans += b[i]==0;
    else {
      if (b[i] < 0) a[i] *= -1, b[i] *= -1;
      int g = __gcd(b[i], a[i]);
      best = max(best, ++m[{b[i]/g,a[i]/g}]);
    }
  }
  ans += best;
  cout << ans << endl;
}
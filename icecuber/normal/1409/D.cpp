#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    ll n, s;
    cin >> n >> s;
    ll ans = 0;
    while (1) {
      ll sum = 0;
      for (char c : to_string(n)) sum += c-'0';
      if (sum <= s) break;
      ll m = 10;
      while (n%m == 0) m *= 10;
      ll add = (m-n%m);
      n += add;
      ans += add;
    }
    cout << ans << endl;
  }
}
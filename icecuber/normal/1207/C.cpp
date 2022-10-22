#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    ll n, a, b;
    cin >> n >> a >> b;
    string s;
    cin >> s;

    ll high = 1e18, low = 1*b;
    for (int i = 0; i < n; i++) {
      ll nlow, nhigh;
      if (s[i] == '0') {
	nlow = min(high+2*a+b, low+a+b);
	nhigh = min(high+a+b*2, low+a*2+b*2);
      } else {
	nlow = 1e18;
	nhigh = high+a+b*2;
      }
      low = nlow;
      high = nhigh;
    }
    ll ans = low;
    cout << ans << endl;
  }
}
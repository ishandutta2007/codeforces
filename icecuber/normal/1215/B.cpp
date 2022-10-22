#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  int p = 1, m = 0, v = 1;
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    int a;
    cin >> a;
    if (a < 0) v *= -1;
    if (v > 0) ans += p++;
    else ans += m++;
  }
  cout << (ll)n*(n+1)/2-ans << ' ' << ans << endl;
}
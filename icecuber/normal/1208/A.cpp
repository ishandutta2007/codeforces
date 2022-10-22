#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int a, b, n;
    cin >> a >> b >> n;
    int ans;
    if (n%3 == 0) ans = a;
    else if (n%3 == 1) ans = b;
    else ans = a^b;
    cout << ans << endl;
  }
}
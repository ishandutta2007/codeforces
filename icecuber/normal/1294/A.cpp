#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    ll a, b, c, n;
    cin >> a >> b >> c >> n;
    cout << ((a+b+c+n)%3 == 0 && max({a,b,c})*3-(a+b+c) <= n ? "YES" : "NO") << endl;
  }
}
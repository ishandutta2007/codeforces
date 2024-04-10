#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    ll c, sum;
    cin >> c >> sum;
    ll x = sum/c, y = x+1;
    ll r = sum%c;
    cout << x*x*(c-r)+y*y*(r) << endl;
  }
}
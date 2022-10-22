#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    ll n, g, b;
    cin >> n >> g >> b;
    ll fail = n-1, pass = 1e18;
    while (pass-fail > 1) {
      ll mid = pass+fail>>1;
      ll goods = mid/(g+b)*g + min(mid%(g+b), g);
      if (goods*2 >= n && mid >= n) pass = mid;
      else fail = mid;
    }
    cout << pass << endl;
  }
}
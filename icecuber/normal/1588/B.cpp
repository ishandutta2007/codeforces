#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    ll n;
    cin >> n;
    auto query = [](int l, int r) {
      cout << "? " << l+1 << ' ' << r << endl;
      ll ans;
      cin >> ans;
      if (ans == -1) exit(0);
      return ans;
    };
    ll tot = query(0,n);
    int fail = 0, pass = n;
    while (pass-fail > 1) {
      int m = (pass+fail)/2;
      if (query(0,m) == tot) pass = m;
      else fail = m;
    }
    ll r = pass;
    ll totm1 = query(0,r-1);
    ll m = r-(tot-totm1+1);
    ll l = m - (query(0,m)-query(0,m-1)+1);
    cout << "! " << l+1 << ' ' << m+1 << ' ' << r << endl;
  }
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll f(ll x) {
  ll r = x%2 ? x/2*2 : 0;
  r += x/2%2;
  return r;
}
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  ll grundy = 0;
  for (int i = 0; i < n; i++) {
    ll x, m;
    cin >> x >> m;
    grundy ^= f(x+m);
    grundy ^= f(x);
  }
  cout << (grundy ? "tolik" : "bolik") << endl;
}
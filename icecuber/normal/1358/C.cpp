#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll f(ll x, ll y) {
  x--, y--;
  ll s = x+y;
  return s*(s+1)/2+y+1;
}

ll g(ll a, ll b, ll e) {
  ll d = b-a;
  assert(b > a);
  ll ans = 0;
  for (ll i = a; i < e; i += d) {
    ans += i;
    d++;
  }
  return ans;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    ll x1, y1, x2, y2;
    cin >> y1 >> x1 >> y2 >> x2;
    ll w = x2-x1+1;
    ll h = y2-y1+1;
    //ll mi = g(f(x1,y1), f(x1+1,y1), f(x2,y1))+g(f(x2,y1), f(x2,y1+1), f(x2,y2));
    //ll ma = g(f(x1,y1), f(x1,y1+1), f(x1,y2))+g(f(x1,y2), f(x1+1,y2), f(x2,y2));
    cout << (w-1)*(h-1)+1 << endl;//(ma+1-mi) << endl;
  }
}
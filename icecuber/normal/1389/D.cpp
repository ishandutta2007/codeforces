#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    ll n, k;
    cin >> n >> k;
    ll al, ar, bl, br;
    cin >> al >> ar >> bl >> br;
    if (al > bl) swap(al,bl),swap(ar,br);

    ll base = n*max(0ll,min(br,ar)-bl);
    ll x = max(0ll,bl-ar);
    ll y = (max(ar,br)-al)*2 - (br-bl)-(ar-al);
    //cout << x << ' ' << y << endl;
    k -= base;
    ll ans = 1e18;
    for (int i = 0; i < n; i++) {
      ll cost = i*y;
      ll need = k-(y-x)*i;
      if (need <= 0);
      else if (need <= y-x)
	cost += x+need;
      else
	cost += y+(need-(y-x))*2;
      //cout << i << ' ' << cost << ' ' << need << endl;
      ans = min(ans, cost);
    }
    cout << ans << endl;
  }
}
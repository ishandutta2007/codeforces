#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define x first
#define y second

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int q;
  cin >> q;
  map<ll, set<pair<ll,ll>>> m;
  map<pair<ll,ll>,int> dones;
  ll points = 0;
  while (q--) {
    ll t, x, y;
    cin >> t >> x >> y;
    if (t == 1) {
      ll d = x*x+y*y;
      auto&s = m[d];
      for (auto p : s) {
	ll dx = x+p.x, dy = y+p.y;
	ll g = __gcd(dx,dy);
	dones[{dx/g,dy/g}] += 2;
      }
      ll g = __gcd(x,y);
      dones[{x/g,y/g}]++;
      m[d].insert({x,y});
      points++;
      //cout << "DONE: " << dones[{1,1}] << endl;
    } else if (t == 2) {
      ll d = x*x+y*y;
      ll g = __gcd(x,y);
      dones[{x/g,y/g}]--;
      auto&s = m[d];
      m[d].erase({x,y});
      for (auto p : s) {
	ll dx = x+p.x, dy = y+p.y;
	ll g = __gcd(dx,dy);
	dones[{dx/g,dy/g}] -= 2;
      }
      points--;
      //cout << "DONE: " << dones[{1,1}] << endl;
    } else {
      ll g = __gcd(x,y);
      cout << points-dones[{x/g,y/g}] << '\n';
      //cout << "DONE: " << dones[{1,1}] << endl;
    }
  }
}
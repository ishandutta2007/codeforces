#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


struct point {
  ll x, y;
};
point operator-(point a, point b) {
  return {a.x-b.x,a.y-b.y};
}
ll operator*(point a, point b) {
  return a.x*b.x+a.y*b.y;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  point ra, rb;
  cin >> ra.x >> ra.y >> rb.x >> rb.y;
  vector<pair<point,point>> wall;
  wall.push_back({{ra.x,ra.y},{1,0}});
  wall.push_back({{ra.x,ra.y},{0,1}});
  wall.push_back({{rb.x,rb.y},{-1,0}});
  wall.push_back({{rb.x,rb.y},{0,-1}});

  long double mint = 0, maxt = 1e18;
  int ok = 1;
  for (int i = 0; i < n; i++) {
    point p, v;
    cin >> p.x >> p.y >> v.x >> v.y;
    for(auto w : wall) {
      long double div = v*w.second;
      long double base = (p-w.first)*w.second;
      if (div == 0) {
	if (base <= 0) {
	  ok = 0;
	}
      } else {
	if (div > 0)
	  mint = max(mint, -base/div);
	else
	  maxt = min(maxt, -base/div);
      }
    }
  }
  if (!ok || maxt-mint < 1e-12) {
    cout << -1 << endl;
  } else cout << setprecision(20) << mint << endl;
}
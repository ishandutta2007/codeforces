#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll euclid(ll a, ll b, ll&ia, ll&ib) {
  if (!b) {
    ia = 1, ib = 0;
    return a;
  } else {
    ll g = euclid(b,a%b,ib,ia);
    ib -= ia*(a/b);
    return g;
  }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  ll w, h, x, y, vx, vy;
  cin >> w >> h >> x >> y >> vx >> vy;
  if (!vx && x%w || !vy && y%h) {
    cout << -1 << endl;
    return 0;
  }
  if (!vy) {
    cout << (vx > 0 ? w : 0) << ' ' << y << endl;
    return 0;
  }
  if (!vx) {
    cout << x << ' ' << (vy > 0 ? h : 0) << endl;
    return 0;
  }
  ll a = vx > 0 ? (w-x)%w : x;
  ll b = vy > 0 ? (h-y)%h : y;
  ll iw, ih;
  ll g = euclid(w, h, iw, ih);
  //cout << iw*w+ih*h << ' ' << g << endl;
  //cout << iw*w%h << ' ' << ih*h%w << endl;
  if (a%g != b%g) {
    cout << -1 << endl;
    return 0;
  }
  ll t = (iw*(b/g)%h)*w+(ih*(a/g)%w)*h+a%g;
  //cout << (x+vx*t)%w << ' ' << (y+vy*t)%h << endl;
  t = (t%(w*h/g)+w*h/g)%(w*h/g);
  cout << ((x+vx*t)%(2*w)+(2*w))%(2*w) << ' ';
  cout << ((y+vy*t)%(2*h)+(2*h))%(2*h) << endl;
}
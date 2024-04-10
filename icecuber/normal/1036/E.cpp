#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define x first
#define y second
typedef pair<ll,ll> point;
point operator-(point a, point b) {
  return {a.x-b.x,a.y-b.y};
}
ll operator%(point a, point b) {
  return a.x*b.y-a.y*b.x;
}
ll operator*(point a, point b) {
  return a.x*b.x+a.y*b.y;
}

point a[1000], b[1000], d[1000];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    cin >> a[i].x >> a[i].y >> b[i].x >> b[i].y;
    d[i] = b[i]-a[i];
    //cout << a[i].x << ' ' << a[i].y << ' ' << b[i].x << ' ' << b[i].y << ' ' << __gcd(d[i].x, d[i].y)+1 << endl;
    ans += __gcd(abs(d[i].x), abs(d[i].y))+1;
    set<point> covered;
    for (int j = 0; j < i; j++) {
      ll A = (a[j]-a[i])%d[i];
      ll B = (b[j]-a[i])%d[i];
      ll C = (a[i]-a[j])%d[j];
      ll D = (b[i]-a[j])%d[j];
      if ((A==0||B==0||(A<0^B<0)) &&
	  (C==0||D==0||(C<0^D<0))) {
	ll det = d[j]%d[i];
	point c = a[j];
	ll t = (a[i]-a[j])%d[i];
	if (t*d[j].x%det || t*d[j].y%det) continue;
	c.x += t*d[j].x/det;
	c.y += t*d[j].y/det;
	//cout << c.x << ' ' << c.y << endl;
	//cout << (c-a[i])%d[i] << ' ' << (c-a[j])%d[j] << endl;
	covered.insert(c);
      }
    }
    ans -= covered.size();
  }
  cout << ans << endl;
}
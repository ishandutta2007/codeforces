#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define x first
#define y second
typedef pair<ll,ll> point;

point operator-(point a, point b) {
  return {a.x-b.x, a.y-b.y};
}
ll operator%(point a, point b) {
  return a.x*b.y - a.y*b.x;
}


ll operator*(point a, point b) {
  return a.x*b.x + a.y*b.y;
}
point operator+(point a, point b) {
  return {a.x+b.x, a.y+b.y};
}

//~(a-b) gives distance from a to b
double operator~(point a) {
  return hypot(a.x,a.y);
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<point> p(n);
  for (int i = 0; i < n; i++) {
    cin >> p[i].x >> p[i].y;
  }
  if (n%2) {
    cout << "NO" << endl;
    return 0;
  }
  for (int i = 0; i < n/2; i++) {
    point da = p[(i+1)%n]-p[i];
    point db = p[(i+n/2+1)%n]-p[i+n/2];
    if (~(da+db)) {
      cout << "NO" << endl;
      return 0;
    }
  }
  cout << "YES" << endl;
}
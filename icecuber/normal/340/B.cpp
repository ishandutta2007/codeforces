#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

//Convex hull O(n log n)
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


bool angle_cmp(point a, point b) {
  if (a%b == 0) return a*a < b*b;
  return a%b > 0;
}

vector<point> convexHull(vector<point> a) {
  point base = *min_element(a.begin(), a.end());
  for (point&p : a) {
    p = p-base;
  }

  //Sorts counterclockwise
  sort(a.begin(), a.end(), angle_cmp);

  vector<point> hull;
  for (point p : a) {
    while (hull.size() >= 2 && (p-hull.end()[-2]) % (hull.end()[-1]-hull.end()[-2]) >= 0) {
      hull.pop_back();
    }
    hull.push_back(p);
  }
  return hull;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<point> p(n);
  for (auto&x : p) cin >> x.x >> x.y;
  ll best = 0;
  for (int i = 0; i < n; i++) {
    for (int j = 0; j < n; j++) {
      if (i == j) continue;
      ll mi = -1, ma = -1;
      for (int k = 0; k < n; k++) {
	if (k == i || k == j) continue;

	point a = p[i], b = p[j], c = p[k];
	if ((a-b)%(a-c) > 0) {
	  mi = max(mi, abs(abs(a%b+b%c+c%a)));
	} else {
	  ma = max(ma, abs(abs(a%b+b%c+c%a)));
	}
      }
      if (mi > -1 && ma > -1)
	best = max(best, mi+ma);
    }
  }
  cout << setprecision(20) << best/2. << endl;
}
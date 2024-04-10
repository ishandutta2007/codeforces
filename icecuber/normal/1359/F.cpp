#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
#define double long double

struct point {
  double x, y;
};
point operator-(point a, point b) {
  return {a.x-b.x, a.y-b.y};
}
point operator+(point a, point b) {
  return {a.x+b.x, a.y+b.y};
}
double operator%(point a, point b) {
  return a.x*b.y-a.y*b.x;
}
double operator*(point a, point b) {
  return a.x*b.x+a.y*b.y;
}
point operator*(point a, double f) {
  return {a.x*f, a.y*f};
}
double operator~(point a) {
  return sqrt(a.x*a.x+a.y*a.y);
}

struct Segment {
  point a, b;
  double y(double x) {
    return (x-a.x)*(b.y-a.y)/(b.x-a.x)+a.y;
  }
};


const double eps = 1e-14;
bool intersect(Segment a, Segment b) {
  if (abs((a.b-a.a)%(b.b-b.a)) < abs((a.b-a.a)*(b.b-b.a))*eps) {
    point ad = a.b-a.a;
    if (abs(ad%(b.a-a.a)) > abs(ad*(b.a-a.a))*1e-9) return 0;
    double a1 = a.a*ad, a2 = a.b*ad;
    double b1 = b.a*ad, b2 = b.b*ad;
    if (a1 > a2) swap(a1,a2);
    if (b1 > b2) swap(b1,b2);
    return max(a1,b1) <= min(a2,b2);
  }
  double A = (b.a-a.a)%(a.b-a.a), eA = abs((b.a-a.a)*(a.b-a.a))*eps;
  double B = (b.b-a.a)%(a.b-a.a), eB = abs((b.b-a.a)*(a.b-a.a))*eps;
  double C = (a.a-b.a)%(b.b-b.a), eC = abs((a.a-b.a)*(b.b-b.a))*eps;
  double D = (a.b-b.a)%(b.b-b.a), eD = abs((a.b-b.a)*(b.b-b.a))*eps;
  return ((abs(A) <= eA || abs(B) <= eB || ((A<0) ^ (B<0))) &&
	  (abs(C) <= eC || abs(D) <= eD || ((C<0) ^ (D<0))));
}
double curx;
bool operator<(Segment a, Segment b) {
  return a.y(curx) < b.y(curx);
}


int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<point> p(n), d(n);
  for (int i = 0; i < n; i++) {
    double s;
    cin >> p[i].x >> p[i].y >> d[i].x >> d[i].y >> s;
    d[i] = d[i]*(s/~d[i]);
  }
  double low = 0, high = 1e10;
  int foundever = 0;
  //while (abs(high-low)*max(high, 1.) > 1e-7) {
  for (int bit = 0; bit < 100; bit++) {
    double mid = (high+low)/2;
    vector<Segment> seg(n);
    for (int i = 0; i < n; i++) {
      seg[i] = {p[i], p[i]+d[i]*mid};
    }
    /*for (int i = 0; i < n; i++) {
      for (int j = 0; j < i; j++) {
	if (intersect(seg[i],seg[j])) {
	  cout << mid << ' ' << i << ' ' << j << endl;
	}
      }
    }
    cout << endl;*/
    vector<pair<double,int>> event;
    for (int i = 0; i < n; i++) {
      event.emplace_back(seg[i].a.x, i);
      event.emplace_back(seg[i].b.x, i);
    }
    sort(event.begin(), event.end());
    bool found = 0;
    multiset<Segment> active;
    set<int> inset;
    for (auto [x,i] : event) {
      curx = x;
      if (inset.count(i)) {
	auto it = active.find(seg[i]);
	assert(it != active.end());
	if (it != active.begin() && next(it) != active.end() && intersect(*prev(it), *next(it))) {
	  found = 1;
	  foundever = 1;
	  break;
	}
	inset.erase(i);
	active.erase(it);
      } else {
	auto it = active.lower_bound(seg[i]);
	if ((it != active.begin() && intersect(*prev(it), seg[i])) ||
	    (it != active.end() && intersect(*it, seg[i]))) {
	  found = 1;
	  foundever = 1;
	  break;
	}
	inset.insert(i);
	active.insert(seg[i]);
      }
    }
    if (found) high = mid;
    else low = mid;
  }
  if (!foundever)
    cout << "No show :(" << endl;
  else
    cout << setprecision(20) << low << endl;
}
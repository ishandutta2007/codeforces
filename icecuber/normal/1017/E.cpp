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

mt19937_64 mrand(chrono::steady_clock::now().time_since_epoch().count());

vector<tuple<ll,ll,ll>> read(int n) {
  vector<point> p(n);
  for (int i = 0; i < n; i++) {
    cin >> p[i].x >> p[i].y;
  }
  p = convexHull(p);
  n = p.size();
  vector<tuple<ll,ll,ll>> ret;
  for (int i = 0; i < n; i++) {
    point a = p[i], b = p[(i+1)%n], c = p[(i+2)%n];
    point x = b-a, y = c-b;
    ret.emplace_back(x*x, x*y, x%y);
    //cout << x*x << ' ' << x*y << ' ' << x%y << endl;
  }
  return ret;
}

template<class T>
int match(vector<T> a, vector<T> sum) {
  int n = a.size();
  for (auto x : a) sum.push_back(x);
  for (auto x : a) sum.push_back(x);

  int m = sum.size();
  vector<int> z(m,0);
  int l = 0, r = 0;
  for (int i = 1; i < m; i++) {
    if (z[i-l] < r-i) {
      z[i] = z[i-l];
    } else {
      r = max(r,i);
      l = i;
      while (r < m && sum[r-i] == sum[r]) r++;
      z[i] = r-i;
    }
    if (i >= n && z[i] >= n) return 1;
  }
  return 0;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int na, nb;
  cin >> na >> nb;
  auto a = read(na);
  auto b = read(nb);
  cout << (match(a, b) ? "YES" : "NO") << endl;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

typedef pair<ll,ll> point;
#define x first
#define y second

point operator-(point a, point b) {
  return {a.x-b.x, a.y-b.y};
}

ll f(point a, point b, point c) {
  a = a-b;
  c = c-b;
  return c.x*(a.y-a.x*a.x)-a.x*(c.y-c.x*c.x);
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  map<int,int> p;
  for (int i = 0; i < n; i++) {
    int x, y;
    cin >> x >> y;
    if (!p.count(x) || p[x] < y)
      p[x] = y;
  }
  vector<point> hull;
  for (auto i : p) {
    while (hull.size() >= 2 && f(hull[hull.size()-2], hull[hull.size()-1], i) >= 0) hull.pop_back();
    hull.push_back(i);
  }
  cout << hull.size()-1 << endl;
}
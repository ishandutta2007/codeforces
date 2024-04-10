#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct point {
  ll x, y;
};
point operator+(point a, point b) {
  return {a.x+b.x,a.y+b.y};
}
point operator*(point a, ll f) {
  return {a.x*f,a.y*f};
}
point operator-(point a, point b) {
  return {a.x-b.x,a.y-b.y};
}
ll operator~(point a) {
  return hypot(a.x,a.y);
}
ll operator*(point a, point b) {
  return a.x*b.x+a.y*b.y;
}
ll operator%(point a, point b) {
  return a.x*b.y-a.y*b.x;
}

bool ok(point a, point b, point c) {
  return (a-b)*(c-b) > 0;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<point> p(n);
  for (point&v : p) cin >> v.x >> v.y;

  vector<int> done(n);

  vector<int> ans = {0};
  done[0] = 1;
  for (int i = 1; i < n; i++) {
    ll ma = 0, maj = -1;
    for (int j = 0; j < n; j++) {
      if (!done[j]) {
        point d = p[j]-p[ans.back()];
        ll dd = d*d;
        if (dd > ma) {
          ma = dd;
          maj = j;
        }
      }
    }
    assert(ma);
    ans.push_back(maj);
    done[maj] = 1;
  }
  for (int v : ans) cout << v+1 << ' ';
  cout << endl;
}
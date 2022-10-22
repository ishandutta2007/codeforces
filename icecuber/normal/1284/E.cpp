#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct point {
  ll x, y;
};

point operator-(point a, point b) {
  return {a.x-b.x, a.y-b.y};
}
ll operator*(point a, point b) {
  return a.x*b.x+a.y*b.y;
}
ll operator%(point a, point b) {
  return a.x*b.y-a.y*b.x;
}

bool operator<(point a, point b) {
  int ya = a.y < 0, yb = b.y < 0;
  if (ya != yb) return ya < yb;
  return a%b > 0;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<point> p(n);
  for (int i = 0; i < n; i++) {
    cin >> p[i].x >> p[i].y;
  }
  ll ans = 0;
  for (int i = 0; i < n; i++) {
    vector<point> q;
    for (point a : p) {
      q.push_back(a-p[i]);
      if (q.back()*q.back() == 0) q.pop_back();
    }
    sort(q.begin(), q.end());
    //for (point a : q) cout << a.x << ' ' << a.y << endl;
    //cout << endl;
    auto cp = q;
    for (point a : cp) q.push_back(a);

    int j = 0;
    for (int i = 0; i < n-1; i++) {
      while (j < i+n-1 && q[i] % q[j] >= 0) j++;
      ll x = j-i-1, y = n-2-x;
      ans += (x*(x-1)+y*(y-1))/2;
    }
  }
  ans /= 2;

  ans = ((ll)n * (n-1) * (n-2) * (n-3) / 24 * 4 - ans) * (n-4) / 2;
  cout << ans << endl;
}
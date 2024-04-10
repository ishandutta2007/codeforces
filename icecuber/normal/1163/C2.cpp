#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct point {int x, y;};
int operator%(point a, point b) {return a.x*b.y-a.y*b.x;}
point operator-(point a, point b) {return {a.x-b.x,a.y-b.y};}
bool operator<(point a, point b) {return make_pair(a.x,a.y) < make_pair(b.x,b.y);}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<point> p(n);
  for (point&pi : p) cin >> pi.x >> pi.y;

  map<point, vector<int>> m;
  for (int i = 0; i < n; i++)
    for (int j = 0; j < i; j++) {
      if (i == j) continue;
      point d = p[i]-p[j];
      int g = __gcd(abs(d.x),abs(d.y))*(d.y*1e5+d.x > 0 ? 1 : -1);
      d.x /= g;
      d.y /= g;
      m[d].push_back(d%p[i]);
    }
  ll tot = 0, ans = 0;
  for (auto p : m) {
    //for (int i : p.second) cout << i << ' ';
    //cout << endl;
    sort(p.second.begin(), p.second.end());
    ll len = unique(p.second.begin(), p.second.end())-p.second.begin();
    //cout << len << endl;
    ans -= len*(len-1)/2;
    tot += len;
  }
  cout << tot*(tot-1)/2+ans << endl;
}
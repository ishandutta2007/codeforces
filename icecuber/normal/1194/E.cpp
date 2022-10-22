#include <bits/stdc++.h>
using namespace std;
using ll = long long;

struct Line {
  int x0, y0, x1, y1;
};
bool cross(Line a, Line b) {
  return a.x0 <= b.x1 && a.x1 >= b.x0 && a.y0 <= b.y1 && a.y1 >= b.y0;
}

bitset<5000> bs[5000];

int main() {
  int n;
  cin >> n;
  vector<Line> h, v;
  for (int i = 0; i < n; i++) {
    Line l;
    cin >> l.x0 >> l.y0 >> l.x1 >> l.y1;
    if (l.x0 > l.x1) swap(l.x0,l.x1);
    if (l.y0 > l.y1) swap(l.y0,l.y1);
    if (l.x0 == l.x1) v.push_back(l);
    else h.push_back(l);
  }
  if (v.size() > h.size()) swap(v,h);
  for (int i = 0; i < v.size(); i++) {
    for (int j = 0; j < h.size(); j++) {
      bs[i].set(j,cross(v[i],h[j]));
    }
  }

  ll ans = 0;
  for (int i = 0; i < v.size(); i++) {
    for (int j = 0; j < i; j++) {
      ll v = (bs[i]&bs[j]).count();
      ans += v*(v-1)/2;
    }
  }
  cout << ans << endl;
}
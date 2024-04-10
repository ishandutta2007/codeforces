#include <bits/stdc++.h>

#include <algorithm>
#include <cstdio>
#include <map>
#include <memory>

using namespace std;
typedef long long ll;
#define mp(x, y) make_pair(x, y)
const int N = 1e6 + 5, mod = 1e9 + 7;
int n, m, x, y;
ll Dis(pair<int, int> x, pair<int, int> y) {
  return abs(x.first - y.first) + abs(x.second - y.second);
}
int main() {
  // freopen("1.in", "r", stdin);
  int t;
  scanf("%d", &t);
  while (t--) {
    scanf("%d%d%d%d", &n, &m, &x, &y);
    vector<pair<int, int> > points;
    points.push_back(mp(1, m));
    points.push_back(mp(n, m));
    points.push_back(mp(1, 1));
    points.push_back(mp(n, 1));
    int x1, y1, x2, y2;
    ll dis = -1;
    for (int i = 0; i < points.size(); i++)
      for (int j = i + 1; j < points.size(); j++) {
        ll dis_ = Dis(mp(x, y), points[i]) + Dis(points[i], points[j]) +
                  Dis(points[j], mp(x, y));
        if (dis_ > dis)
          dis = dis_, x1 = points[i].first, y1 = points[i].second,
          x2 = points[j].first, y2 = points[j].second;
      }
    // if (t == 0) {
    //   cout << "^_^: " << dis / 2 << ' '
    //        << Dis(mp(x, y), mp(50, 1)) + Dis(mp(50, 1), mp(1000000000, 1)) +
    //               Dis(mp(1000000000, 1), mp(x, y))
    //        << endl;
    // }
    printf("%d %d %d %d\n", x1, y1, x2, y2);
  }
}
#include <bits/stdc++.h>
using namespace std;

#define x first
#define y second

typedef long long ll;

double dist(pair<double, double> a, pair<double, double> b) {
  double dx = a.x-b.x, dy = a.y-b.y;
  return sqrt(dx*dx+dy*dy);
}
int main() {
  double a, b, c;
  double x1, y1, x2, y2;
  cin >> a >> b >> c;
  cin >> x1 >> y1 >> x2 >> y2;
  double ans = abs(x2-x1)+abs(y2-y1);
  vector<pair<double, double>> A, B;
  A.push_back({x1, -(c+a*x1)/b});
  A.push_back({-(c+b*y1)/a, y1});
  B.push_back({x2, -(c+a*x2)/b});
  B.push_back({-(c+b*y2)/a, y2});
  for (auto a : A)
    for (auto b : B) {
      double v = dist(a, {x1,y1})+dist(a,b)+dist(b,{x2,y2});
      ans = min(ans, v);
    }
  cout << setprecision(20) << ans << endl;
}
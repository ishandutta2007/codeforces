#include "bits/stdc++.h"

using namespace std;

const double EPS = 1e-2;
const double PI = 3.14159265;

struct pt {
  long long x, y;
  int id;
  double ang;
  pt(int _x = 0, int _y = 0, int _id=-1) : x(_x), y(_y), id(_id) {
    ang = atan2(y, x);
  }
};

long long score(long long a, long long b) {
  return a*a + b*b;
}

bool cmp(const pt& a, const pt& b) {
  if(a.ang == b.ang)
    return abs(a.x) + abs(a.y) < abs(b.x) + abs(b.y);
  return a.ang < b.ang;
}

int main() {
  srand(15061994);
  ios_base::sync_with_stdio(0);
  int n;
  cin >> n;
  vector <pt> X;
  for(int i=0; i<n; i++)
  {
    int x, y;
    cin >> x >> y;
    X.push_back(pt(x,y,i));
  }
  while(true) {
    random_shuffle(X.begin(), X.end());
    vector <int> ret(n);
    pt d;
    for(int i=0; i<n; i++) {
      if(score(d.x + X[i].x, d.y + X[i].y) <= score(d.x - X[i].x, d.y - X[i].y)) {
        ret[X[i].id] = 1;
        d.x += X[i].x;
        d.y += X[i].y;
      } else {
        ret[X[i].id] = -1;
        d.x -= X[i].x;
        d.y -= X[i].y;
      }
    }
    if(score(d.x, d.y) <= 1.5e6 * 1.5e6) {
      for(int i=0; i<n; i++) cout << ret[i] << " ";
      cout << "\n";
      break;
    }
  }
  return 0;
}
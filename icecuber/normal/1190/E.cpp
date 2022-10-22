#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define M_PI 3.14159265358979323846

typedef pair<ll,ll> point;
#define x first
#define y second

int d[200000];
point p[100000];

ll operator*(point a, point b) {
  return a.x*b.x+a.y*b.y;
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  double low = 0, high = 1e9;
  for (int i = 0; i < n; i++) {
    cin >> p[i].x >> p[i].y;
    high = min(high, sqrt(p[i]*p[i]));
  }
  for (int it = 0; high && it < 100; it++) {
    double r = (low+high)/2;
    vector<pair<double,double>> q;
    for (int i = 0; i < n; i++) {
      double d = sqrt(p[i]*p[i]);
      double a = atan2(p[i].y, p[i].x), b = acos(r/d);
      double x = a+b;
      while (x < 0) x += M_PI*2;
      while (x >= M_PI*2) x -= M_PI*2;
      q.emplace_back(x, x-b*2);
    }
    sort(q.begin(), q.end());
    for (int i = 0; i < n; i++)
      q.push_back({q[i].x+M_PI*2, q[i].y+M_PI*2});
    deque<pair<double,int>> deq;
    for (int i = 0; i < n*2; i++) {
      while (deq.size() && q[i].y > deq.front().x) {
	d[deq.front().y] = i-deq.front().y;
	deq.pop_front();
      }
      deq.push_back({q[i].x, i});
    }
    int mindi = 0, mind = n;
    for (int i = 0; i < n; i++) {
      if (d[i] < mind) {
	mind = d[i];
	mindi = i;
      }
    }
    int need = 1e9;
    for (int a = mindi; a <= mindi+d[mindi]; a++) {
      int c = 0, dist = 0;
      int i = a%n;
      while (dist < n) {
	dist += d[i];
	i += d[i];
	if (i >= n) i -= n;
	c++;
      }
      need = min(need, c);
    }
    /*if (it == 0) {
      for (int i = 0; i < n; i++) cout << d[i] << ' '; cout << endl;
      cout << need << ' ' << m << endl;
      }*/
    if (need > m) high = r;
    else low = r;
  }
  cout << setprecision(20) << high << endl;
}
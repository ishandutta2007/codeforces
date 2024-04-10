#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Range {
  int mi, ma;
  Range() {
    mi = 1e9, ma = -1e9;
  }
  void update(int p) {
    mi = min(p, mi);
    ma = max(p, ma);
  }
};

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<array<int,2>> p(n);
  for (int i = 0; i < n; i++) {
    string s;
    cin >> s;
    for (char c : s) {
      if (c == 'B') p[i][0]++;
      else p[i][1]++;
    }
  }
  Range x, y, xy;
  for (int i = 0; i < n; i++) {
    x.update(p[i][0]);
    y.update(p[i][1]);
    xy.update(p[i][0]-p[i][1]);
  }
  int pass = 1e7, fail = -1;
  int ansx, ansy;
  while (pass-fail > 1) {
    int mid = (pass+fail)/2;
    int ax = x.mi+mid;
    int ay = y.mi+mid;
    ax = min(ax,   xy.mi+mid+ay );
    ay = min(ay, -(xy.ma-mid-ax));
    if (ax >= x.ma-mid && ay >= y.ma-mid &&
	ax-ay >= xy.ma-mid && ax-ay <= xy.mi+mid &&
	ax <= x.mi+mid && ay <= y.mi+mid && ax+ay) {
      pass = mid;
      ansx = ax;
      ansy = ay;
    } else fail = mid;
  }
  cout << pass << endl;
  for (int i = 0; i < ansx; i++) cout << 'B';
  for (int i = 0; i < ansy; i++) cout << 'N';
  cout << endl;
}
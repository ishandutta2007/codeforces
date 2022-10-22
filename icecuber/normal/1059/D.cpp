#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

double x[100000], y[100000];
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  int positives = 0;
  for (int i = 0; i < n; i++) {
    cin >> x[i] >> y[i];
    positives += y[i]>0;
  }
  if (positives == 0)
    for (int i = 0; i < n; i++)
      y[i] *= -1;
  else if (positives != n) {
    cout << -1 << endl;
    return 0;
  }
  double low = 0, high = 1e15;
  for (int it = 0; it < 200; it++) {
    double r = (low+high)*.5;
    double xma = 1e9, xmi = -1e9;
    int ok = 1;
    for (int i = 0; i < n; i++) {
      double dy = r-y[i];
      if (abs(dy) > r) ok = 0;
      else {
	double d = sqrt((2*r-y[i])*y[i]);
	xma = min(xma, x[i]+d);
	xmi = max(xmi, x[i]-d);
      }
    }
    if (xmi>xma) ok = 0;
    if (ok) high = r;
    else low = r;
  }
  cout << setprecision(20) << low << endl;
}
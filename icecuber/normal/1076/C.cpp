#include <bits/stdc++.h>
using namespace std;

int main() {
  int t;
  cin >> t;
  while (t--) {
    int d;
    cin >> d;
    if (d*d<4*d) {
      cout << "N" << endl;
      continue;
    }
    long double sq = sqrt((long double)(d*d-4*d));
    long double a = .5*(d-sq), b = .5*(d+sq);
    cout << setprecision(20) << "Y " << a << ' ' << b << endl;
    //cout << max(
  }
}
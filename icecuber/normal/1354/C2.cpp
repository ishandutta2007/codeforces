#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n;
    cin >> n;
    n *= 2;
    double a = acos(-1)*2/n;
    double r = 0.5/sin(a/2);
    auto f = [&](double alpha) {
      double ret = 0;
      for (int i = 0; i < n; i++) {
	double x = r*cos(i*a+alpha);
	double y = r*sin(i*a+alpha);
	ret = max({ret, abs(x), abs(y)});
      }
      return ret*2;
    };
    double low = 0, high = a/2;
    for (int it = 0; it < 100; it++) {
      double mid = (high+low)*0.5;
      if (f(mid+1e-6)-f(mid-1e-6) < 0) {
	low = mid;
      } else {
	high = mid;
      }
    }
    cout << setprecision(20) << f(low) << endl;
  }
}
#include <bits/stdc++.h>

using namespace std;

int main() {
  ios::sync_with_stdio(false);
  cin.tie(0);
  vector<int> as(11);
  for (int i = 0; i < 11; i++) {
    cin >> as[i];
  }
  cout << fixed << setprecision(2);
  for (int i = 10; i >= 0; i--) {
    int v = as[i];
    double a = sqrt(abs(v));
    double b = v * v * v * 5;
    double res = a + b;
    if (res > 400) {
      cout << "f(" << v << ") = MAGNA NIMIS!" << '\n';
    } else {
      cout << "f(" << v << ") = " << res << '\n';
    }
  }
  return 0;
}
#include <bits/stdc++.h>
using namespace std;

int main() {
  int n;
  cin >> n;
  int operations = 0, needx = 0;
  while (1) {
    int m = n;
    int r = 1, needx_ = 0;
    for (int i = 2; i*i <= m; i++) {
      int count = 0;
      while (m%i == 0) {
	m /= i;
	count++;
      }
      if (count%2) needx_ = 1;
      for (int j = 0; j < (count+1)/2; j++)
	r *= i;
    }
    if (m > 1) {
      r *= m;
      needx_ = 1;
    }
    if (r == n) break;
    needx |= needx_;
    n = r;
    operations += 1;
  }
  cout << n << ' ' << operations+needx << endl;
}
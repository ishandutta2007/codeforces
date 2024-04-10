#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  int p = 0;
  for (int i = 2; i < n; i++) {
    int m = n;
    while (m) {
      p += m%i;
      m /= i;
    }
  }
  int q = n-2;
  int g = __gcd(p,q);
  cout << p/g << '/' << q/g << endl;
}
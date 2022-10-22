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
    int a = 6, b = 10, c = 14;
    n -= a+b+c;
    if (n <= 0) cout << "NO" << endl;
    else {
      cout << "YES" << endl;
      if (n == a || n == b || n == c) cout << a << ' ' << b << ' ' << 15 << ' ' << n-1 << endl;
      else cout << a << ' ' << b << ' ' << c << ' ' << n << endl;
    }
  }
}
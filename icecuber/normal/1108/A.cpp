#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int q;
  cin >> q;
  while (q--) {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    if (b > d)
      cout << b << ' ' << c << endl;
    else
      cout << a << ' ' << d << endl;
  }
}
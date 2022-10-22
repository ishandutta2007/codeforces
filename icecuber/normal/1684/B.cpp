#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    ll a, b, c;
    cin >> a >> b >> c;
    cout << a+b+c << ' ' << b+c << ' ' << c << endl;
  }
}
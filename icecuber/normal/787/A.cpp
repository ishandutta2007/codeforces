#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int a, b, c, d;
  cin >> a >> b >> c >> d;
  for (int t = 0; t < 20000; t++) {
    if (t >= b && t >= d && (t-b)%a==0 && (t-d)%c==0) {
      cout << t << endl;
      return 0;
    }
  }
  cout << -1 << endl;
}
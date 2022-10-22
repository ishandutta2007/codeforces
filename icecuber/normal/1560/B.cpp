#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int a, b, c;
    cin >> a >> b >> c;
    if (a > b) swap(a,b);
    int n = b-a;
    if (n*2 < max({a,b,c})) {
      cout << -1 << endl;
    } else {
      cout << (c <= n ? c+n : c-n) << endl;
    }
  }
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int a, b;
    cin >> a >> b;
    b -= a;
    if (b == 0) cout << 0 << endl;
    else if ((b > 0) == abs(b)%2) cout << 1 << endl;
    else cout << 2 << endl;
  }
}
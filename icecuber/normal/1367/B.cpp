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
    int c[2][2] = {};
    for (int i = 0; i < n; i++) {
      int a;
      cin >> a;
      c[a%2][i%2]++;
    }
    if (c[0][1] != c[1][0]) {
      cout << -1 << endl;
    } else {
      cout << c[0][1] << endl;
    }
  }
}
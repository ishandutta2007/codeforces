#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, x;
    cin >> n >> x;
    int c[2] = {};
    for (int i = 0; i < n; i++) {
      int a;
      cin >> a;
      c[a%2]++;
    }
    int ok = 0;
    for (int i = 0; i <= c[0] && i <= x; i++) {
      int j = x-i;
      if (j <= c[1])
	if (j%2) ok = 1;
    }
    cout << (ok ? "Yes" : "No") << endl;
  }
}
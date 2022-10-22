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
    if (n == 1) {
      cout << -1 << endl;
    } else {
      cout << 2;
      for (int i = 1; i < n; i++) cout << 9;
      cout << endl;
    }
  }
}
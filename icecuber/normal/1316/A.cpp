#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, m;
    cin >> n >> m;
    int a0;
    cin >> a0;
    int sum = 0;
    for (int i = 1; i < n; i++) {
      int a;
      cin >> a;
      sum += a;
    }
    cout << min(a0+sum, m) << endl;
  }
}
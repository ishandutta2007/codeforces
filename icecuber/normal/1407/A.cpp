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
    vector<int> a(n);
    int c[2] = {};
    for (int&v : a) cin >> v, c[v]++;
    if (c[1] <= n/2) {
      cout << n/2 << endl;
      for (int i = 0; i < n/2; i++) cout << 0 << ' ';
      cout << endl;
    } else {
      cout << n/2+n/2%2 << endl;
      for (int i = 0; i < n/2+n/2%2; i++) cout << 1 << ' ';
      cout << endl;
    }
  }
}
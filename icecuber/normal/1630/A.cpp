#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, k;
    cin >> n >> k;
    if (k == n-1 && n == 4) {
      cout << -1 << endl;
      continue;
    }
    vector<array<int,2>> done;
    if (k < n-1) {
      done.push_back({k,n-1});
      if (k)
        done.push_back({0,n-1-k});
    } else {
      done.push_back({n-2,n-1});
      done.push_back({1,3});
      done.push_back({0,n-4});
    }
    for (auto [a,b] : done) cout << a << ' ' << b << endl;
    for (int i = 0; i < n/2; i++) {
      int ok = 1;
      for (auto [a,b] : done) ok &= (i != a && i != b && n-i-1 != a && n-1-i != b);
      if (ok)
        cout << i << ' ' << n-1-i << endl;
    }
  }
}
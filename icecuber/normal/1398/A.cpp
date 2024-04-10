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
    for (int&v : a) cin >> v;
    if (a[0]+a[1] <= a[n-1])
      cout << 1 << ' ' << 2 << ' ' << n << endl;
    else
      cout << -1 << endl;
  }
}
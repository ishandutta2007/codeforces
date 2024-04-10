#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int n, k;
    cin >> n >> k;
    vector<int> a(n);
    for (int&v : a) cin >> v;
    sort(a.begin(), a.end());
    ll sum = 0;
    for (int i = n-k-1; i < n; i++) {
      sum += a[i];
    }
    cout << sum << endl;
  }
}
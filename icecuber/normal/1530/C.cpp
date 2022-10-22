#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(n), b(n);
    for (int&v : a) cin >> v;
    for (int&v : b) cin >> v;
    sort(a.rbegin(), a.rend());
    sort(b.rbegin(), b.rend());
    int pass = n*4, fail = -1;
    while (pass-fail > 1) {
      int mid = (pass+fail)/2;
      int k = n+mid, take = k-k/4;
      ll mine = mid*100, his = 0;
      for (int i = 0; i < min(n, take-mid); i++) {
        mine += a[i];
      }
      for (int i = 0; i < min(n, take); i++) {
        his += b[i];
      }
      if (mine >= his) pass = mid;
      else fail = mid;
    }
    cout << pass << endl;
  }
}
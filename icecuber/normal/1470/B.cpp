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
    map<int,int> cnt;
    for (int i = 0; i < n; i++) {
      cin >> a[i];
      for (int j = 2; j*j <= a[i]; j++) {
        while (a[i]%(j*j) == 0) a[i] /= j*j;
      }
      cnt[a[i]]++;
    }
    int maxodd = 0, ans = 0, sumeven = 0;
    for (auto [v,c] : cnt) {
      ans = max(ans, c);
      if (c%2 && v != 1) {
        maxodd = max(maxodd, c);
      } else {
        sumeven += c;
      }
    }
    int q;
    cin >> q;
    while (q--) {
      ll w;
      cin >> w;
      if (w == 0) {
        cout << ans << endl;
      } else {
        cout << max(ans, sumeven) << endl;
      }
    }
  }
}
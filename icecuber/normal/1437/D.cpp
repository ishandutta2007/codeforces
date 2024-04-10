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
    int ans = 1;
    cin >> a[0];
    int left = 0, cur = 0;

    for (int i = 1; i < n; i++) {
      cin >> a[i];
      if (a[i] > a[i-1]) cur++;
      else {
        if (!left) {
          left = cur;
          cur = 0;
          ans++;
        }
        left--;
        cur++;
      }
    }
    cout << ans << endl;
  }
}
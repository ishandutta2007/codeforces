#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    for (int&v : a) cin >> v;
    int pass = n+1, fail = -1;
    string ans;
    while (pass-fail > 1) {
      int mid = (pass+fail)/2;
      int left = q;
      string cur(n,'0');
      for (int i = 0; i < mid; i++) {
        if (a[i] <= left) cur[i] = '1';
      }
      for (int i = mid; i < n; i++) {
        cur[i] = '1';
        if (a[i] > left) left--;
      }
      if (left < 0) fail = mid;
      else {
        pass = mid;
        ans = cur;
      }
    }
    assert(ans.size());
    cout << ans << endl;
  }
}
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
    vector<int> a(n);
    int sum = 0;
    for (int&v : a) cin >> v, sum += v;
    int badin = (n%2 == 0);
    for (int i = 1; i+1 < n-1; i += 2) {
      if (a[i] != a[i+1]) badin = 0;
    }
    if (sum%2 || sum == n || (a[0] == 1 && a[n-1] == 1 && badin)) {
      cout << "NO" << endl;
      continue;
    }

    int good0 = -1, bad0 = -1;
    int acc = 0;
    int streak = 0;
    for (int i = 0; i < n; i++) {
      acc += a[i];
      if (a[i] == 0 && acc%2 == 0) {
        good0 = i;
      }
      if (a[i] == 0) {
        streak++;
      } else {
        if (streak%2) bad0 = i;
        streak = 0;
      }
    }

    vector<int> ans;
    auto add = [&](int i) {
      assert(i >= 0 && i+2 < n);
      a[i] = a[i+1] = a[i+2] = (a[i]^a[i+1]^a[i+2]);
      ans.push_back(i+1);
    };
    if (good0 == -1) {
      assert(bad0 != -1);
      while (a[bad0-2] == 0) add(bad0-2), bad0 -= 2;
      add(bad0-2);
      good0 = bad0;
    }

    for (int i = good0; i < n; i++) {
      if (a[i]) {
        if (a[i+1]) add(i-1);
        else if (a[i+2]) add(i);
        else add(i), add(i-1);
      }
    }
    for (int i = good0; i >= 0; i--) {
      if (a[i]) {
        if (a[i-1]) add(i-1);
        else if (a[i-2]) add(i-2);
        else add(i-2), add(i-1);
      }
    }

    cout << "YES" << endl;
    cout << ans.size() << endl;
    for (int i : ans) cout << i << ' ';
    cout << endl;
    assert((int)ans.size() <= n);
    for (int i = 0; i < n; i++) assert(!a[i]);

  }
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<int> a(n), pref(n), suf(n);
  for (int&v : a) cin >> v;
  int ans = 0;
  for (int i = 0; i < n; i++) {
    if (i && a[i] > a[i-1]) pref[i] = pref[i-1]+1;
    else pref[i] = 1;
    ans = max(ans, pref[i]);
  }
  for (int i = n-1; i >= 0; i--) {
    if (i+1 < n && a[i] < a[i+1]) suf[i] = suf[i+1]+1;
    else suf[i] = 1;
  }
  for (int i = 1; i+1 < n; i++) {
    if (a[i-1] < a[i+1])
      ans = max(ans, pref[i-1]+suf[i+1]);
  }
  cout << ans << endl;
}
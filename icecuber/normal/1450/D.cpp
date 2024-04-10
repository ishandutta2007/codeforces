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
      cin >> a[i], a[i]--;
      cnt[a[i]]++;
    }
    string ans(n, '0');
    if ((int)cnt.size() == n) ans[0] = '1';

    int l = 0, r = n-1;
    for (int i = 0; i < n; i++) {
      if ((a[l] == i)+(a[r] == i) != 1 || cnt[i] > 1)
        break;
      ans[n-i-1] = '1';
      if (a[l] == i) l++;
      else r--;
    }
    int k = r-l+1;
    int mi = 1e9;
    for (int i = l; i <= r; i++)
      mi = min(mi, a[i]);
    if (mi == n-k) ans[k-1] = '1';

    cout << ans << endl;
  }
}
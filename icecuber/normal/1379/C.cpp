#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int t;
  cin >> t;
  while (t--) {
    int k, n;
    cin >> k >> n;
    vector<array<ll,2>> a(n);
    for (int i = 0; i < n; i++) {
      cin >> a[i][0] >> a[i][1];
    }
    sort(a.begin(), a.end());
    vector<ll> acc(n+1);
    for (int i = 0; i < n; i++) {
      acc[i+1] = acc[i]+a[i][0];
    }
    ll ans = 0;
    for (int i = 0; i < n; i++) {
      ll b = a[i][1];
      int j = lower_bound(a.begin(), a.end(), array<ll,2>({a[i][1], 1ll<<40}))-a.begin();
      j = max(j, n-k);

      ll score = 0;
      if (j == n-k && i >= j) {
	score = acc[n]-acc[j];
      } else if (j == n-k && i < j) {
	j++;
	score = acc[n]-acc[j]+a[i][0];
      } else if (j > n-k && i < j) {
	score = acc[n]-acc[j]+a[i][0]+(k-(n-j)-1)*b;
      } else if (j > n-k && i >= j) {
	score = acc[n]-acc[j]+(k-(n-j))*b;
      } else assert(0);
      ans = max(ans, score);
    }
    cout << ans << endl;
  }
}
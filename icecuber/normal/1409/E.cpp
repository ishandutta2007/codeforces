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
    vector<int> x(n), y(n);
    for (int&v : x) cin >> v;
    for (int&v : y) cin >> v;
    sort(x.begin(), x.end());
    int ans = 0;
    vector<int> dp(n);
    for (int i = 0; i < n; i++) {
      int prv = upper_bound(x.begin(), x.end(), x[i]-k-1)-x.begin()-1;
      dp[i] = max(i ? dp[i-1] : 0, i-prv);
      ans = max(ans, (prv >= 0 ? dp[prv] : 0)+(i-prv));
    }
    cout << ans << endl;
  }
}
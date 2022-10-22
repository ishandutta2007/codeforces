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
    for (int&v : a) cin >> v;
    sort(a.begin(), a.end());
    int m = n*2+5;
    vector<int> dp(m);
    for (int i = 0; i < n; i++) {
      vector<int> ndp(m, 1e9);
      for (int j = 1; j < m; j++) {
        ndp[j] = min({ndp[j], dp[j-1]+abs(j-a[i]), ndp[j-1]});
      }
      dp = ndp;
    }
    cout << *min_element(dp.begin(), dp.end()) << endl;
  }
}
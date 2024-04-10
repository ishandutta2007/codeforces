// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int dp[55];

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  int t;
  cin >> t;
  while (t--) {
    int n, k;
    string s;
    cin >> n >> k >> s;
    vector<int> a;
    for (int i=0; i<n; i++) {
      if (s[i] == '*') {
        a.push_back(i);
      }
    }

    memset(dp, 63, sizeof dp);
    dp[a[0]] = 1;
    for (int i=1; i<(int)a.size(); i++) {
      for (int j=max(0, a[i]-k); j<a[i]; j++) {
        dp[a[i]] = min(dp[a[i]], dp[j] + 1);
      }
    }
    cout << dp[a.back()] << '\n';
  }
}
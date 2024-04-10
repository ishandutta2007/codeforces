// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int dp[5005][5005];

void mn(int& x, int y) {
  x = min(x, y);
}

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  memset(dp, 63, sizeof dp);

  int n;
  vector<int> a, b;

  cin >> n;
  for (int i=0; i<n; i++) {
    int x;
    cin >> x;
    (x ? a : b).push_back(i);
  }

  dp[0][0] = 0;

  int k = a.size();
  int l = b.size();
  for (int i=0; i<=k; i++) {
    for (int j=0; j<l; j++) {
      if (i < k) mn(dp[i+1][j+1], dp[i][j] + abs(a[i] - b[j]));
      mn(dp[i][j+1], dp[i][j]);
    }
  }

  cout << dp[k][l] << '\n';
}
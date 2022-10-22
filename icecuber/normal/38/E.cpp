#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define x first
#define y second

ll dp[3000];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<pair<int,int>> p(n);
  for (auto&v : p) cin >> v.x >> v.y;
  sort(p.begin(), p.end());
  ll ans = 1e18;
  fill_n(dp, n, 1e18);
  dp[0] = 0;
  for (int i = 0; i < n; i++) {
    dp[i] += p[i].y;
    ll acc = dp[i];
    for (int j = i+1; j < n; j++) {
      dp[j] = min(dp[j], acc);
      acc += p[j].x-p[i].x;
    }
    ans = min(ans, acc);
  }
  cout << ans << endl;
}
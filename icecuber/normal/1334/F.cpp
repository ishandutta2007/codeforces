#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<ll> a(n);
  for (ll& v : a) cin >> v;
  vector<ll> p(n);
  for (ll& v : p) cin >> v;
  int m;
  cin >> m;
  vector<ll> b(m);
  for (ll& v : b) cin >> v;
  vector<ll> cost(m+1);
  for (int i = 0; i < n; i++) {
    int j = lower_bound(b.begin(), b.end(), a[i])-b.begin();
    if (j == m) cost[m] += p[i];
    else if (p[i] < 0) {
      cost[j] += p[i];
    }
  }
  vector<ll> dp(m+1,1e18);
  dp[0] = 0;
  for (int i = 0; i < n; i++) {
    int j = lower_bound(b.begin(), b.end(), a[i])-b.begin();
    if (j == m) continue;
    //cout << j << ' ';
    if (b[j] == a[i]) {
      ll take_cost = 0;
      if (p[i] < 0) take_cost = -p[i];
      dp[j+1] = min(dp[j+1], dp[j]+cost[j]+take_cost);
    }
    if (p[i] > 0) {
      cost[j] += p[i];
    }
  }
  //cout << endl;
  /*for (int i = 0; i <= m; i++)
    cout << dp[i] << ' ';
    cout << endl;*/
  if (dp[m] > 1e17) {
    cout << "NO" << endl;
    return 0;
  }
  cout << "YES" << endl;
  cout << dp[m]+cost[m] << endl;
}
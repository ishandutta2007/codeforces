#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, k;
  cin >> n >> k;
  vector<ll> time[2][2];
  for (int i = 0; i < n; i++) {
    int t, a, b;
    cin >> t >> a >> b;
    time[a][b].push_back(t);
  }
  for (int a : {0,1})
    for (int b : {0,1})
      sort(time[a][b].begin(), time[a][b].end());
  for (int i = 0; i < (int)min(time[0][1].size(), time[1][0].size()); i++)
    time[1][1].push_back(time[0][1][i]+time[1][0][i]);
  sort(time[1][1].begin(), time[1][1].end());

  if ((int)time[1][1].size() < k) {
    cout << -1 << endl;
    return 0;
  }
  ll ans = 0;
  for (int i = 0; i < k; i++)
    ans += time[1][1][i];
  cout << ans << endl;
}
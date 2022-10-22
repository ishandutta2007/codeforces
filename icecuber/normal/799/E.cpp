#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<ll> c[2][2];
int la[200000], lb[200000];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  if (k > m) {
    cout << -1 << endl;
    return 0;
  }
  vector<ll> c0(n);
  for (int i = 0; i < n; i++) cin >> c0[i];
  for (int l = 0; l < 2; l++) {
    int na;
    cin >> na;
    for (int i = 0; i < na; i++) {
      int j;
      cin >> j;
      (l ? lb : la)[j-1] = 1;
    }
  }
  for (int i = 0; i < n; i++) {
    c[la[i]][lb[i]].push_back(c0[i]);
  }
  for (int i = 0; i < 2; i++)
    for (int j = 0; j < 2; j++) {
      sort(c[i][j].begin(), c[i][j].end());
      //cout << c[i][j].size() << endl;
    }

  int n00 = c[0][0].size(), n01 = c[0][1].size(), n10 = c[1][0].size(), n11 = c[1][1].size();
  int ind00 = 0, ind01 = 0, ind10 = 0, ind11 = 0;
  ll cost = 0, ans = 1e18;
  for (int both = min(m,n11); both >= 0; both--) {
    ll left = max(0, k-both);
    if (left > n01 || left > n10 || n01+n10+n00+both < m || left*2+both > m) continue;
    while (ind11 < both) {
      cost += c[1][1][ind11++];
    }
    while (ind11 > both) {
      cost -= c[1][1][--ind11];
    }
    while (ind01 < left) {
      cost += c[0][1][ind01++];
    }
    while (ind10 < left) {
      cost += c[1][0][ind10++];
    }
    while (ind00+ind10+ind01+both < m) {
      ll mi = 1e18;
      if (ind00 < n00) mi = min(mi, c[0][0][ind00]);
      if (ind01 < n01) mi = min(mi, c[0][1][ind01]);
      if (ind10 < n10) mi = min(mi, c[1][0][ind10]);
      cost += mi;
      if (ind00 < n00 && c[0][0][ind00] == mi) {
	ind00++;
      } else if (ind01 < n01 && c[0][1][ind01] == mi) {
	ind01++;
      } else if (ind10 < n10 && c[1][0][ind10] == mi) {
	ind10++;
      } else {
	assert(0);
      }
    }
    while (ind00+ind10+ind01+both > m) {
      ll ma = -1e18;
      if (ind00) ma = max(ma, c[0][0][ind00-1]);
      if (ind01 > left) ma = max(ma, c[0][1][ind01-1]);
      if (ind10 > left) ma = max(ma, c[1][0][ind10-1]);
      cost -= ma;
      if (ind00 && c[0][0][ind00-1] == ma) {
	ind00--;
      } else if (ind01 > left && c[0][1][ind01-1] == ma) {
	ind01--;
      } else if (ind10 > left && c[1][0][ind10-1] == ma) {
	ind10--;
      } else assert(0);
    }
    //cout << ind00 << ' ' << ind01 << ' ' << ind10 << ' ' << ind11 << endl;
    ans = min(ans, cost);
  }
  if (ans == 1e18) cout << -1 << endl;
  else cout << ans << endl;
}
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

#define x first
#define y second

const int nax = 4e5+10;
int dp[nax];
int pos[nax];
ll mod = 1e9+7;
ll dp2[nax];

vector<int> reach[nax];
void add(ll&a, ll b) {
  a += b;
  if (a >= mod)
    a -= mod;
}
int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  vector<pair<int,int>> inv(n);
  map<int,int> ma;
  for (int i = 0; i < n; i++) {
    cin >> inv[i].y >> inv[i].x;
    ma[inv[i].x], ma[inv[i].y];
  }
  int c = 0;
  for (auto&p : ma) {
    pos[c] = p.x;
    p.y = c++;
  }
  int start = 0;
  for (auto p : inv) {
    reach[ma[p.y]].push_back(ma[p.x]);
    start = max(start, ma[p.x]+1);
  }
  fill_n(dp, c, 1e9+10);
  dp[0] = pos[0];
  int best = 2e9;
  for (int i = 0; i < c; i++) {
    if (i)
      dp[i] = min(dp[i],dp[i-1]+pos[i]-pos[i-1]);
    for (int j : reach[i]) {
      dp[i] = min(dp[i],dp[j]);
    }
    if (i >= start)
      best = min(best, dp[i]);
  }
  for (int i = c-1; i >= 0; i--) {
    if (dp[i] == best && i >= start) {
      dp2[i] = 1;
    }
    if (i && dp[i-1]+pos[i]-pos[i-1] == dp[i])
      add(dp2[i-1], dp2[i]);
    for (int j : reach[i]) {
      if (dp[j] == dp[i])
	add(dp2[j], dp2[i]);
    }
  }
  cout << dp2[0] << endl;
}
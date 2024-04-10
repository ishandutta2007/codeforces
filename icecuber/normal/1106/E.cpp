#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

struct Query {
  int w, d, t;
};
pair<int,int> a[100020];
vector<Query> q[100020];

ll dp[100020][201];

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m, k;
  cin >> n >> m >> k;
  while (k--) {
    int s, t, d, w;
    cin >> s >> t >> d >> w;
    q[s].push_back({w,d+1,1});
    q[t+1].push_back({w,d+1,-1});
  }
  multiset<pair<int,int>> s;
  for (int i = 1; i <= n; i++) {
    for (Query p : q[i]) {
      if (p.t == 1) {
	s.emplace(p.w,p.d);
      } else {
	s.erase(s.find({p.w,p.d}));
      }
    }
    if (s.empty()) a[i] = {0,i+1};
    else a[i] = *s.rbegin();
  }
  for (int i = n; i >= 1; i--)
    for (int j = 0; j <= m; j++)
      dp[i][j] = min(dp[a[i].second][j]+a[i].first, j ? dp[i+1][j-1] : ll(1e18));
  cout << dp[1][m] << endl;
}
// Retired?
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long unsigned long ull;
typedef double long ld;

int n, m;
vector<pair<int, int>> e[100005];
ll dp[100005][51];

int main() {
  ios::sync_with_stdio(!cin.tie(0));

  cin >> n >> m;
  for (int i=0; i<m; i++) {
    int x, y, w;
    cin >> x >> y >> w;
    e[x].emplace_back(y, w);
    e[y].emplace_back(x, w);
  }

  memset(dp, 63, sizeof dp);
  dp[1][0] = 0;
  set<tuple<ll, int, int>> pq;
  pq.insert({0, 1, 0});

  while (pq.size()) {
    auto [d, x, wi] = *pq.begin();
    pq.erase(pq.begin());

    for (auto [y, wj] : e[x]) {
      ll dy = wi == 0 ? d : d + (wi+wj)*(wi+wj);
      int w = wi == 0 ? wj : 0;
      if (dy < dp[y][w]) {
        pq.erase({dy, y, w});
        dp[y][w] = dy;
        pq.insert({dy, y, w});
      }
    }
  }

  for (int i=1; i<=n; i++) {
    ll z = dp[i][0];
    if (z > 1e17) {
      z = -1;
    }
    cout << z << " \n"[i == n];
  }
}
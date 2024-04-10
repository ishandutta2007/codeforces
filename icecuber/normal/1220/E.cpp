#include <bits/stdc++.h>
using namespace std;
using ll = long long;

vector<int> node[200000];
int deg[200000];

ll w[200000];
ll dp[200000], path[200000];

ll ans = 0;
void dfs1(int p, int par = -1, ll W = 0) {
  W += w[p];
  ans = max(ans, W);
  for (int i : node[p]) {
    if (i == par) continue;
    dfs1(i, p, W);
  }
}

int main() {
  int n, m;
  cin >> n >> m;
  for (int i = 0; i < n; i++)
    cin >> w[i];
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    node[a].push_back(b);
    node[b].push_back(a);
    deg[a]++, deg[b]++;
  }

  int s;
  cin >> s;
  s--;

  if (m == n-1) {
    dfs1(s, -1);
    cout << ans << endl;
    return 0;
  }

  queue<int> q;
  for (int i = 0; i < n; i++)
    if (deg[i] == 1) q.push(i);

  path[s] = 1;
  ll base = 0;
  while (q.size()) {
    int p = q.front();
    q.pop();
    if (path[p]) {
      base += w[p];
      w[p] = 0;
    }
    for (int i : node[p]) {
      deg[i]--;
      if (deg[i]) {
	dp[i] = max(dp[i], dp[p]+w[p]);
      }
      if (path[p]) {
	path[i] = 1;
      }
      if (deg[i] == 1) {
	q.push(i);
      }
    }
  }

  for (int i = 0; i < n; i++) {
    if (deg[i] > 1) {
      base += w[i];
      ans = max(ans, dp[i]);
    }
  }
  cout << base+ans << endl;
}
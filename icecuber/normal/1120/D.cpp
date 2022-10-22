#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int nax = 2e5;
vector<int> node[nax];
ll c[nax], dp[nax][2];

//dp[p][0] = minimum cost to be good independently
//dp[p][1] = minimum cost to be good if supported from above

void dfs(int p, int par = -1) {
  ll sum0 = 0, max_diff = 0;
  for (int i : node[p]) {
    if (i == par) continue;
    dfs(i, p);
    sum0 += dp[i][0];
    max_diff = max(max_diff, dp[i][0]-dp[i][1]);
  }
  if (node[p].size() == 1 && par != -1) {
    //p is a leaf
    dp[p][0] = c[p];
    dp[p][1] = 0;
  } else {
    ll sum1 = sum0-max_diff+c[p];
    dp[p][0] = min(sum0, sum1);
    dp[p][1] = sum0-max_diff;
  }
}

vector<int> ans;
void reconstruct(int p, int p0 = 1, int p1 = 0, int par = -1) {
  ll sum0 = 0, max_diff = 0;
  set<int> max_diffi;
  for (int i : node[p]) {
    if (i == par) continue;
    sum0 += dp[i][0];
    int v = dp[i][0]-dp[i][1];
    if (v > max_diff) max_diffi.clear(), max_diff = v;
    if (v == max_diff) max_diffi.insert(i);
  }
  if (node[p].size() == 1 && par != -1) {
    //p is a leaf
    if (p0) ans.push_back(p);
  } else {
    ll sum1 = sum0-max_diff+c[p];
    set<int> p0s, p1s;
    if (p0 && sum1 <= sum0) {
      // We may pick this node
      ans.push_back(p);
    }
    if (p0 && sum0 <= sum1) {
      // Support no child
      for (int i : node[p]) {
	if (i != par) p0s.insert(i);
      }
    }
    if (p0 && sum1 <= sum0 || p1) {
      // We support one child
      p1s = max_diffi;
      for (int i : node[p]) {
	if (i != par && (max_diffi.size() > 1 || i != *max_diffi.begin())) {
	  p0s.insert(i);
	}
      }
    }
    for (int i : node[p]) {
      if (i == par) continue;
      reconstruct(i, p0s.count(i), p1s.count(i), p);
    }
  }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 0; i < n; i++)
    cin >> c[i];
  for (int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    node[a].push_back(b);
    node[b].push_back(a);
  }
  dfs(0);
  cout << dp[0][0] << ' ';
  reconstruct(0);
  cout << ans.size() << endl;
  sort(ans.begin(), ans.end());
  for (int i : ans) cout << i+1 << ' ';
  cout << endl;
}
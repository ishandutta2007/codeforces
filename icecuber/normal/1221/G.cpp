#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

vector<int> node[40];

int col[40];
int is_bipartite = 1;

void dfs(int p, int c) {
  if (col[p]) {
    if (col[p] != c) is_bipartite = 0;
    return;
  }
  col[p] = c;
  for (int i : node[p])
    dfs(i, 3-c);
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n, m;
  cin >> n >> m;
  if (!m) {
    cout << 0 << endl;
    return 0;
  }
  for (int i = 0; i < m; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    node[a].push_back(b);
    node[b].push_back(a);
  }
  ll all = 1;
  ll all0 = 1;
  for (int i = 0; i < n; i++) {
    if (node[i].empty())
      all0 *= 2;
    all *= 2;
  }
  ll all2 = all0;
  ll all02 = 1;
  for (int i = 0; i < n; i++) {
    if (!col[i]) {
      all02 *= 2;
      dfs(i, 1);
    }
  }
  ll all1 = all02*is_bipartite;
  all02 -= all0+all2;

  int na = n/2, nb = n-na;
  vector<ll> dp(1<<na);
  for (int i = 0; i < 1<<na; i++) {
    int ok = 1;
    for (int j = 0; j < na; j++)
      for (int k : node[j])
	if (k < na) {
	  if ((i>>j&1) && (i>>k&1)) ok = 0;
	}
    if (ok) {
      dp[i]++;
    }
  }
  for (int j = 0; j < na; j++)
    for (int i = 0; i < 1<<na; i++)
      if (i>>j&1)
	dp[i] += dp[i^1<<j];

  ll all01 = 0;
  for (int i = 0; i < 1<<nb; i++) {
    int ok = 1;
    int forbid = 0;
    for (int j = 0; j < nb; j++) {
      for (int k : node[na+j]) {
	if (k >= na) {
	  if ((i>>j&1) && (i>>k-na&1)) ok = 0;
	} else if (i>>j&1) {
	  forbid |= 1<<k;
	}
      }
    }
    if (ok) {
      all01 += dp[(1<<na)-1-forbid];
    }
  }
  all01 -= all0+all1;
  ll all12 = all01;

  //cout << all << endl;
  //cout << all0 << ' ' << all1 << ' ' << all2 << endl;
  //cout << all01 << ' ' << all02 << ' ' << all12 << endl;

  cout << all-all0-all1-all2-all01-all02-all12 << endl;
}
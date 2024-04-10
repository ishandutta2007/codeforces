#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int nax = 1e5;
vector<int> node[nax];

int ans[nax];

/*array<int,2> dfs(int p, int par, int chose) {
  array<int,2> dp = {0,(int)1e9};
  for (int i : node[p]) {
    if (i == par) continue;
    array<int,2> a = dfs(i, p);
    dp = {dp[0]+a[0],
	  min({dp[0]+a[1],dp[1]+a[0],dp[1]+a[1]})};
  }
  return {dp[1], min(dp[0],dp[1])+1};
}*/

int totmove = 0;
int match(int p, int par) {
  vector<int> matches;
  for (int i : node[p]) {
    if (i == par) continue;
    int a = match(i, p);
    if (a) matches.push_back(i);
  }
  if (matches.empty()) {
    if (par == -1) {
      totmove++;
      ans[p] = p;
      swap(ans[node[p][0]], ans[p]);
    }
    return 1;
  } else {
    matches.push_back(p);
    int n = matches.size();
    totmove += n-1;
    for (int i = 0; i < n; i++) {
      ans[matches[i]] = matches[(i+1)%n];
    }
    return 0;
  }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    node[a].push_back(b);
    node[b].push_back(a);
  }
  match(0, -1);
  cout << totmove*2 << endl;
  for (int i = 0; i < n; i++)
    cout << ans[i]+1 << ' ';
  cout << endl;
}
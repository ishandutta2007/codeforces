#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const int N = 2e5;
vector<int> node[N];
ll sz[N], dp[N];
void dfs1(int p, int par = -1) {
  sz[p] = 1;
  dp[p] = 0;
  for (int i : node[p]) {
    if (i == par) continue;
    dfs1(i,p);
    sz[p] += sz[i];
    dp[p] += dp[i]+sz[i];
  }
}

int n;
ll ans = 0;
void dfs2(int p, ll up, int par = -1) {
  for (int i : node[p]) {
    if (i == par) continue;
    dfs2(i,up-sz[i]+n-sz[i],p);
  }
  ans = max(ans, up);
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  cin >> n;
  for (int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    node[a].push_back(b);
    node[b].push_back(a);
  }
  dfs1(0);
  dfs2(0,dp[0]+n);
  cout << ans << endl;
}
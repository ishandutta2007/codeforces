#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll mod = 998244353;
vector<int> node[200000];
ll fac[200001] = {1};
ll ans;

void dfs(int p, int par = -1) {
  ans = ans*fac[node[p].size()]%mod;
  for (int i : node[p]) {
    if (i == par) continue;
    dfs(i,p);
  }
}

int main() {
  ios::sync_with_stdio(0); cin.tie(0);
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++)
    fac[i] = fac[i-1]*i%mod;
  for (int i = 1; i < n; i++) {
    int a, b;
    cin >> a >> b;
    a--, b--;
    node[a].push_back(b);
    node[b].push_back(a);
  }
  ans = n;
  dfs(0);
  cout << ans << endl;
}